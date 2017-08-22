/*
 * Point.cpp
 *
 *  Created on: Jul 29, 2017
 *      Author: blroot
 */

#include "Point.h"
#include <iostream>

namespace superboy {

	Point::Point(vec3 position, color colorvec) {

		this->position = position;
		this->colorvec = colorvec;
		this->direction = vec3();
		this->attenuation = vec3(1.0f, 0.0f, 0.0f);
		this->type = point;
	}

	void Point::setAttenuation(vec3 attenuation) {

		this->attenuation = attenuation;
	}

	void Point::setTransform(mat4 transform) {

		this->transform = transform;
	}

	void Point::applyTransform() {

		this->position = this->transform * vec4(this->position, 1.0f);
	}

	vec3& Point::getDirection(vec3 &origin) {

		this->direction = (this->position - origin).normalize();

		return this->direction;
	}

	float Point::getAttenuation(vec3 &hitpoint) {

		float distance_to_light = this->getDistance(hitpoint);

		float attenuation_model = 1.0/(attenuation.x + attenuation.y*distance_to_light + attenuation.z*(distance_to_light*distance_to_light));

		return attenuation_model;
	}

	color& Point::getColor() {

		return this->colorvec;
	}

	vec3& Point::getPosition() {

		return this->position;
	}

	float Point::getDistance(vec3& hitpoint) {

		return (this->position - hitpoint).norm();
	}

	Point::~Point() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
