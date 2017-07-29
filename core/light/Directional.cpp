/*
 * Directional.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Directional.h"

namespace superboy {

	Directional::Directional(vec3 direction, color colorvec) {

		this->direction = direction;
		this->colorvec = colorvec;
		this->attenuation = vec3(1.0f, 0.0f, 0.0f);
	}

	vec3& Directional::getDirection(vec3 &origin) {

		return this->direction;
	}

	vec3& Directional::getAttenuation() {

		return this->attenuation;
	}

	color& Directional::getColor() {

		return this->colorvec;
	}

	Directional::~Directional() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
