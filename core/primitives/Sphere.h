/*
 * Sphere.h
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#pragma once

#include "../camera/Ray.h"
#include "../object/Object.h"
#include "../../utils/math/vec3.h"

using namespace math;

namespace superboy {

	class Sphere : public Object {
		public:
			Sphere(vec3 center, float radius);
			virtual ~Sphere();
			float intersect(Ray ray);
			vec3 getNormal(Ray& ray, float& point);
			vec3 getCenter();
		private:
			vec3 center;
			float radius;
	};

} /* namespace superboy */
