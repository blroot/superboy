/*
 * Camera.h
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "../../utils/math/vec3.h"
#include "Ray.h"

#pragma once

using namespace math;

namespace superboy {

	class Camera {
		public:
			vec3 eye;
			vec3 center;
			vec3 up;

			vec3 w;
			vec3 u;
			vec3 v;

			float fov;

			Camera(vec3 eye, vec3 center, vec3 up, float fov);
			virtual ~Camera();
			Ray RayThruPixel(int pixel_x, int pixel_y, int width, int height);
	};

} /* namespace superboy */


