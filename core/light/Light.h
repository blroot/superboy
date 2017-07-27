/*
 * Light.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "../../utils/math/vec3.h"

using namespace math;

namespace superboy {

class Light {
	public:
		Light();
		virtual ~Light();
		virtual vec3& getDirection() =0;
	};

} /* namespace superboy */
