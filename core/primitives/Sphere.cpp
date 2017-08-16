/*
 * sphere.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "Sphere.h"
#include <math.h>
#include "../../utils/math/mat4.h"
#include "../../utils/math/vec4.h"
#include <iostream>

namespace superboy {

	Sphere::Sphere(vec3 center, float radius) {

		this->center = center;
		this->radius = radius;
		this->materials = Materials();
		this->inverse_transform;
	}

	void Sphere::applyTransform() {

		this->inverse_transform = this->transform.inverse();
	}

	Intersect Sphere::intersect(Ray ray) {

		float intersection = 0.0f;
		vec3 ray_direction = ray.getDirection();
		vec3 ray_origin = ray.getEye();

		//if (this->transform != mat4(1.0f)) {

			ray_direction = this->inverse_transform * vec4(ray.getDirection(), 0.0f);
			ray_direction = ray_direction.normalize();
			ray_origin = this->inverse_transform * vec4(ray.getEye(), 1.0f);
		//}

		float a = ray_direction.dot(ray_direction);
		float b = 2*(ray_direction.dot(ray_origin - this->center));
		float c = ((ray_origin - this->center).dot(ray_origin - this->center)) - this->radius*this->radius;

		float discriminant = b*b - 4*a*c;

		// No real roots - no intersection
		// Both roots equal: ray tangent to sphere. I decide to set no intersection
		if (discriminant >= 0.0f) {
			// Compute roots
			float first_root = (-b + sqrt(discriminant))/2*a;
			float second_root = (-b - sqrt(discriminant))/2*a;

			if (first_root > 0.0f and second_root > 0.0f) {
				if (first_root > second_root) {
					intersection = second_root;
				} else {
					intersection = first_root;
				}
			} else if (first_root < 0.0f and second_root > 0.0f) {
				intersection = second_root;
			} else if (first_root > 0.0f and second_root < 0.0f) {
				intersection = first_root;
			}
		}

		vec3 point = ray_origin + ray_direction*(intersection);
		point = this->transform * vec4(point, 1.0f);

		//if (this->transform != mat4(1.0f)) {
			intersection = (vec3(point) - ray.getEye()).norm();
		//}

		vec3 normal = this->inverse_transform.transpose()* vec4(point-this->center, 1.0f);

		//return intersection;
		return Intersect(intersection, point + normal*1e-4, normal);
	}

	vec3 Sphere::getNormal(Ray& ray, float& lambda) {

		if (this->transform != mat4(1.0f)) {

			vec3 eye = this->inverse_transform * vec4(ray.getEye(), 1.0f);
			vec3 direction = this->inverse_transform * vec4(ray.getDirection(), 0.0f);

			vec3 normal = (eye + direction.normalize()*lambda)-this->center;
			normal = this->inverse_transform.transpose()*vec4(normal, 0.0f);

			//vec3 normal = this->getPoint(ray, lambda)-this->center;

			return normal.normalize();
		}

		return ((ray.getEye() + ray.getDirection()*lambda)-this->center).normalize();
	}

	vec3 Sphere::getPoint(Ray& ray, float& lambda) {

		if (this->transform != mat4(1.0f)) {

			//vec3 eye = this->inverse_transform * vec4(ray.getEye(), 1.0f);
			//vec3 direction = this->inverse_transform * vec4(ray.getDirection(), 0.0f);

			//vec3 point = eye + direction.normalize()*(lambda-1e-4);
			vec4 point = vec4(ray.getEye() + ray.getDirection().normalize()*(lambda-1e-4), 1.0f);

			return this->transform*point;
		}

		return ray.getEye() + ray.getDirection()*(lambda-1e-4);
	}

	vec3 Sphere::getCenter() {

		return center;
	}

	Sphere::~Sphere() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
