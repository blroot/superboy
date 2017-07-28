/*
 * sphere.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "Sphere.h"
#include <math.h>

namespace superboy {

	Sphere::Sphere(vec3 center, float radius) {

		this->center = center;
		this->radius = radius;
		this->materials = Materials();
	}

	float Sphere::intersect(Ray ray) {

		float intersection = 0.0f;

		float a = ray.direction.dot(ray.direction);
		float b = 2*(ray.direction.dot(ray.eye - this->center));
		float c = ((ray.eye - this->center).dot(ray.eye - this->center)) - this->radius*this->radius;

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

		return vec3(((ray.eye + ray.direction*point)-this->center).normalize());
	}

	vec3 Sphere::getCenter() {

		return center;
	}

	Sphere::~Sphere() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
