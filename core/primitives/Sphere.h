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
			Sphere(vec3 center, float radius);
			virtual ~Sphere();
			float intersect(Ray ray);
		private:
			vec3 center;
			float radius;
	};

} /* namespace superboy */
