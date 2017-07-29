/*
 * Point.cpp
 *
 *  Created on: Jul 29, 2017
 *      Author: blroot
 */

#include "Point.h"

namespace superboy {

	Point::Point(vec3 position, color colorvec) {

		this->position = position;
		this->colorvec = colorvec;
		this->direction = vec3();
		this->attenuation = vec3(0.0f, 0.0f, 1.0f);
	}

	vec3& Point::getDirection(vec3 &origin) {

		this->direction = this->position - origin;

		return this->direction;
	}

	vec3& Point::getAttenuation() {

		return this->attenuation;
	}

	color& Point::getColor() {

		return this->colorvec;
	}

	Point::~Point() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
