/*
 * Point.h
 *
 *  Created on: Jul 29, 2017
 *      Author: blroot
 */

#pragma once

#include "Light.h"
#include "../../utils/math/vec3.h"
#include "../../utils/math/mat4.h"
#include "../color/color.h"

using namespace math;

namespace superboy {

	class Point : public Light {
		public:
			Point(vec3 position, color colorvec);
			void setTransform(mat4 transform);
			void applyTransform();
			void setAttenuation(vec3 attenuation);
			vec3& getDirection(vec3& origin);
			color& getColor();
			float getAttenuation(vec3& hitpoint);
			mat4& getTranform();
			vec3& getPosition();
			float getDistance(vec3& hitpoint);

			lightType type;
			virtual ~Point();
		private:
			vec3 attenuation;
			vec3 position;
			color colorvec;
			vec3 direction;
			mat4 transform;
	};

} /* namespace superboy */
