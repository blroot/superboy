/*
 * Sphere.h
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "../camera/Ray.h"

#pragma once

namespace superboy {

	class Sphere {
		public:
			vec3 center;
			float radius;

			Sphere(vec3 center, float radius);
			virtual ~Sphere();
			float intersect(Ray ray);
	};

} /* namespace superboy */
