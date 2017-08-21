/*
 * Light.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "../../utils/math/vec3.h"
#include "../color/color.h"

using namespace math;

namespace superboy {

class Light {
	public:

		enum lightType {
			point, directional, undef
		};

		lightType type;

		Light();
		virtual ~Light();
		virtual vec3& getDirection(vec3& origin) =0;
		virtual vec3& getAttenuation() =0;
		virtual color& getColor() =0;
		virtual vec3& getPosition() =0;
	};

} /* namespace superboy */
