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
		this->type = point;
	}

	void Point::setTransform(mat4 transform) {

		this->transform = transform;
	}

	void Point::applyTransform() {

		this->position = this->transform * vec4(this->position, 1.0f);
	}

	vec3& Point::getDirection(vec3 &origin) {

		this->direction = (this->position - origin);

		return this->direction;
	}

	vec3& Point::getAttenuation() {

		return this->attenuation;
	}

	color& Point::getColor() {

		return this->colorvec;
	}

	vec3& Point::getPosition() {

		return this->position;
	}

	Point::~Point() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
