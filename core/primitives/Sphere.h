/*
 * Sphere.h
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "../camera/Ray.h"
#include "../object/Object.h"

#pragma once

namespace superboy {

	class Sphere : public Object {
		public:
			vec3 center;
			float radius;

			Sphere(vec3 center, float radius);
			virtual ~Sphere();
			float intersect(Ray ray);
	};

} /* namespace superboy */
