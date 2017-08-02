/*
 * Triangle.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: blroot
 */

#include "Triangle.h"
#include <iostream>

namespace superboy {

	Triangle::Triangle(vec3 A, vec3 B, vec3 C) {

		this->A = A;
		this->B = B;
		this->C = C;
		this->materials = Materials();
		this->normal = (this->C-this->A).cross(this->B-this->A).normalize();
		this->fix_normal = true;
	}

	Triangle::~Triangle() {
		// TODO Auto-generated destructor stub
	}

	float Triangle::intersect(Ray ray) {

		float intersection = 0.0f;

		// Construct plane from A,B,C
		float t = (this->A.dot(this->normal)-ray.getEye().dot(this->normal))/ray.getDirection().dot(this->normal);

		// Compute dot products
		vec3 P = ray.getEye() + ray.getDirection()*t;

		vec3 v2 = P-this->A;
		vec3 v0 = this->B-this->A;
		vec3 v1 = this->C-this->A;

		float dot20 = v2.dot(v0);
		float dot00 = v0.dot(v0);
		float dot10 = v1.dot(v0);
		float dot21 = v2.dot(v1);
		float dot11 = v1.dot(v1);

		float alpha = ((dot11*dot20)-(dot10*dot21)) / ((dot00*dot11) - (dot10*dot10));
		float beta = ((dot00*dot21)-(dot10*dot20)) / ((dot00*dot11) - (dot10*dot10));

		if (alpha >= 0 and alpha <= 1 and beta >= 0 and beta <= 1 and alpha + beta <= 1) {

			intersection = t;
		}

		return intersection;
	}

	vec3 Triangle::getNormal(Ray &ray, float &point) {

		// Always return a normal facing to the camera
		// Only run once per triangle

		if (fix_normal) {

			float distance1 = (this->normal+ray.getEye()).norm();
			float distance2 = (-1*this->normal+ray.getEye()).norm();

			if (distance1 < distance2) {

				this->normal = -1*this->normal;
				fix_normal = false;
			}
		}

		return this->normal;

	}

} /* namespace superboy */
