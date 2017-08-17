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

	void Point::setTransform(mat4 transform) {

		this->transform = transform;
	}

	void Point::applyTransform() {

		// Translation - Since we're not using homogeneous coordinates, we do this this way
		this->position += vec3(this->transform.elements[12], this->transform.elements[13], this->transform.elements[14]);
	}

	vec3& Point::getDirection(vec3 &origin) {

		this->direction = (this->position - origin).normalize();

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
