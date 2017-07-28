/*
 * Ray.h
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "../../utils/math/vec3.h"

#pragma once

using namespace math;

namespace superboy {

	class Ray {
		public:
			vec3 eye;
			vec3 direction;

			Ray(vec3 eye, vec3 direction);
			vec3 getPoint(float& lambda);
			virtual ~Ray();
	};

} /* namespace superboy */
