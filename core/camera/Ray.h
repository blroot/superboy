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
			Ray(vec3 eye, vec3 direction);
			vec3 getPoint(float& lambda);
			vec3& getEye();
			vec3& getDirection();
			virtual ~Ray();
		private:
			vec3 eye;
			vec3 direction;
	};

} /* namespace superboy */
