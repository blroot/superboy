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
#include "../../utils/math/mat4.h"

using namespace math;

namespace superboy {

	class Sphere : public Object {
		public:
			Sphere(vec3 center, float radius);
			virtual ~Sphere();
			Intersect intersect(Ray ray);
			void applyTransform();
			vec3 getNormal(Ray& ray, float& lambda);
			vec3 getPoint(Ray& ray, float& lambda);
			vec3 getCenter();
		private:
			vec3 center;
			float radius;
			mat4 inverse_transform;
	};

} /* namespace superboy */
