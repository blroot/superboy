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
			vec3& getDirection(vec3& origin);
			float getAttenuation(vec3 &hitpoint);
			color& getColor();
			vec3& getPosition();
			float getDistance(vec3& hitpoint);

			lightType type;
		private:
			vec3 attenuation;
			vec3 direction;
			color colorvec;
			vec3 position;
	};

} /* namespace superboy */
