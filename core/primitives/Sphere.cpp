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
	}

	void Sphere::applyTransform() {


	}

	float Sphere::intersect(Ray ray) {

		float intersection = 0.0f;
		vec3 ray_direction = ray.getDirection();
		vec3 ray_origin = ray.getEye();
		mat4 inverse_transform;

		if (this->transform != mat4(1.0f)) {

			inverse_transform = this->transform.inverse();

			ray_direction = inverse_transform * vec4(ray.getDirection(), 0.0f);
			ray_origin = inverse_transform * vec4(ray.getEye(), 1.0f);
		}

		float a = ray_direction.dot(ray_direction);
		float b = 2*(ray_direction.dot(ray_origin - this->center));
		float c = ((ray_origin - this->center).dot(ray_origin - this->center)) - this->radius*this->radius;

		float discriminant = b*b - 4*a*c;

		// No real roots - no intersection
		// Both roots equal: ray tangent to sphere. I decide to set no intersection
		if (discriminant >= 0) {
			// Compute roots
			float first_root = (-b + sqrt(discriminant))/2*a;
			float second_root = (-b - sqrt(discriminant))/2*a;

			if (first_root > 0 and second_root > 0) {
				if (first_root > second_root) {
					intersection = second_root;
				} else {
					intersection = first_root;
				}
			} else if (first_root < 0 and second_root > 0) {
				intersection = second_root;
			} else if (first_root > 0 and second_root < 0) {
				intersection = first_root;
			}
		}

		return intersection;
	}

	vec3 Sphere::getNormal(Ray& ray, float& point) {

		if (this->transform != mat4(1.0f)) {

			//vec4 position = vec4((ray.getEye() + ray.getDirection()*point), 1.0f);
			//return vec3(this->transform.inverse().transpose() * (position-vec4(this->center, 1.0f))).normalize();

			vec3 eye = this->transform.transpose() * vec4(ray.getEye(), 1.0f);
			vec3 direction = this->transform.transpose() * vec4(ray.getDirection(), 0.0f);

		//	std::cout << ((eye + direction*point)-this->center).normalize() << std::endl;

			return ((eye + direction*point)-this->center).normalize();
		}

		return ((ray.getEye() + ray.getDirection()*point)-this->center).normalize();
	}

	vec3 Sphere::getPoint(Ray& ray, float& lambda) {

		// Get a little closer to light to overcome numerical errors

		if (this->transform != mat4(1.0f)) {

			vec4 point = vec4(ray.getEye() + ray.getDirection()*(lambda-1e-4), 1.0f);
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
