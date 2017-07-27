/*
 * Directional.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Directional.h"

namespace superboy {

	Directional::Directional(vec3 direction, vec3 color) {

		this->direction = direction;
		this->color = color;
	}

	vec3& Directional::getDirection() {

		return this->direction;
	}

	vec3& Directional::getColor() {

		return this->color;
	}

	Directional::~Directional() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
