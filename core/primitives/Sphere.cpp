/*
 * sphere.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "Sphere.h"
#include <math.h>
#include "../../utils/math/mat4.h"
#include <iostream>

namespace superboy {

	Sphere::Sphere(vec3 center, float radius) {

		this->center = center;
		this->radius = radius;
		this->materials = Materials();
	}

	void Sphere::applyTransform() {

		this->center += vec3(this->transform.elements[12], this->transform.elements[13], this->transform.elements[14]);
	}

	float Sphere::intersect(Ray ray) {

		float intersection = 0.0f;
		vec3 ray_direction = ray.getDirection();
		vec3 ray_origin = ray.getEye();
		mat4 inverse_transform;

		if (this->transform != mat4(1.0f)) {

			inverse_transform = this->transform.inverse();

			ray_direction = inverse_transform * ray.getDirection();
			ray_origin = inverse_transform * ray.getEye();
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

			//std::cout << this->transform.transpose()*((ray.getEye() + ray.getDirection()*point)-this->center).normalize() << std::endl;
			return this->transform.transpose()*((ray.getEye() + ray.getDirection()*point)-this->center).normalize();
		}

		return ((ray.getEye() + ray.getDirection()*point)-this->center).normalize();
	}

	vec3 Sphere::getPoint(Ray& ray, float& lambda) {

		// Get a little closer to light to overcome numerical errors

		if (this->transform != mat4(1.0f)) {

			vec3 point = ((ray.getEye() + ray.getDirection()*(lambda-1e-4))) + vec3(this->transform.elements[12], this->transform.elements[13], this->transform.elements[14]);
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
