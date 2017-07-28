/*
 * Directional.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "Light.h"
#include "../../utils/math/vec3.h"
#include "../color/color.h"

using namespace math;

namespace superboy {

	class Directional : public Light {
		public:
			Directional(vec3 direction, color colorvec);
			virtual ~Directional();
			vec3& getDirection();
			color& getColor();
		private:
			vec3 direction;
			color colorvec;
	};

} /* namespace superboy */
