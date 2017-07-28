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
	}

	vec3& Directional::getDirection() {

		return this->direction;
	}

	color& Directional::getColor() {

		return this->colorvec;
	}

	Directional::~Directional() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
