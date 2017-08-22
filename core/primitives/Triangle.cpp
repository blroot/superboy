/*
 * Triangle.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: blroot
 */

#include "../../utils/math/vec4.h"
#include "Triangle.h"
#include <iostream>

namespace superboy {

	Triangle::Triangle(vec3 A, vec3 B, vec3 C) {

		this->A = A;
		this->B = B;
		this->C = C;

		this->materials = Materials();
		this->normal = (this->B-this->A).cross(this->C-this->A).normalize();
		//this->normal = (this->C-this->A).cross(this->B-this->A).normalize();
	}

	Triangle::~Triangle() {
		// TODO Auto-generated destructor stub
	}

	void Triangle::applyTransform() {

		// Apply transforms using homogeneous coordinates

		this->A = this->transform * vec4(this->A, 1.0f);
		this->B = this->transform * vec4(this->B, 1.0f);
		this->C = this->transform * vec4(this->C, 1.0f);

		this->normal = (this->B-this->A).cross(this->C-this->A).normalize();
		//this->normal = (this->C-this->A).cross(this->B-this->A).normalize();

	}

	Intersect Triangle::intersect(Ray ray) {

		float intersection = 0.0f;

		// Construct plane from A,B,C
		float t = ((this->A.dot(this->normal))-(ray.getEye().dot(this->normal)))/ray.getDirection().dot(this->normal);

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

		if (alpha >= 0.0 and alpha <= 1.0 and beta >= 0.0 and beta <= 1.0 and alpha + beta <= 1.0) {

			intersection = t;
		}

		//return intersection;
		return Intersect(intersection, this->getPoint(ray, intersection), this->normal);
	}

	vec3 Triangle::getNormal(Ray &ray, float &lambda) {

		return this->normal;
	}

	vec3 Triangle::getPoint(Ray &ray, float &lambda) {

		return ray.getEye() + ray.getDirection()*(lambda);
	}

	vec3& Triangle::getA() {

		return this->A;
	}

	vec3& Triangle::getC() {

		return this->C;
	}

	vec3& Triangle::getB() {

		return this->B;
	}

} /* namespace superboy */
