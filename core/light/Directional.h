/*
 * Directional.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "Light.h"
#include "../../utils/math/vec3.h"

using namespace math;

namespace superboy {

	class Directional : public Light {
		public:
			Directional(vec3 direction, vec3 color);
			virtual ~Directional();
			vec3& getDirection();
			vec3& getColor();
		private:
			vec3 direction;
			vec3 color;
	};

} /* namespace superboy */
