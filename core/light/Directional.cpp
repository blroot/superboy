/*
 * Directional.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Directional.h"
#include <math.h>

namespace superboy {

	Directional::Directional(vec3 direction, color colorvec) {

		this->direction = direction;
		this->colorvec = colorvec;
		this->attenuation = vec3(1.0f, 0.0f, 0.0f);
		this->position = vec3();
		this->type = directional;
	}

	vec3& Directional::getDirection(vec3 &origin) {

		return this->direction;
	}

	float Directional::getAttenuation(vec3 &hitpoint) {

		return 1.0f;
	}

	color& Directional::getColor() {

		return this->colorvec;
	}

	vec3& Directional::getPosition() {

		return this->position;
	}

	float Directional::getDistance(vec3 &hitpoint) {

		return INFINITY;
	}

	Directional::~Directional() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
