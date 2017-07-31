/*
 * Ray.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "Ray.h"

namespace superboy {

	Ray::Ray(vec3 eye, vec3 direction) {

		this->eye = eye;
		this->direction = direction;
	}

	vec3 Ray::getPoint(float &lambda) {

		// Get a little closer to light to overcome numerical errors
		return vec3(this->eye + this->direction*(lambda-1e-4));
	}

	vec3& Ray::getEye() {

		return this->eye;
	}

	vec3& Ray::getDirection() {

		return this->direction;
	}

	Ray::~Ray() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
