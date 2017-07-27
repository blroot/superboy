/*
 * Shader.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Shader.h"

namespace superboy {

	Shader::Shader() {
		// TODO Auto-generated constructor stub

	}

	vec3 Shader::computeColor(IntersectionInfo &intersection) {

		if (intersection.hitobject != 0) {
			return vec3(255.0f, 0.0f, 0.0f);
		} else {
			return vec3();
		}

	}

	Shader::~Shader() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
