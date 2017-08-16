/*
 * Intersect.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: blroot
 */

#include "Intersect.h"

namespace superboy {

	Intersect::Intersect(float distance, vec3 hitpoint, vec3 normal) {

		this->distance = distance;
		this->hitpoint = hitpoint;
		this->normal = normal;
	}

	Intersect::Intersect() {

		this->distance = 0.0f;
	}

	float& Intersect::getDistance() {

		return this->distance;
	}

	vec3& Intersect::getHitpoint() {

		return this->hitpoint;
	}

	vec3& Intersect::getNormal() {

		return this->normal;
	}

	Intersect::~Intersect() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
