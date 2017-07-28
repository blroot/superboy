/*
 * Object.h
 *
 *  Created on: Jul 24, 2017
 *      Author: blroot
 */

#include "../camera/Ray.h"
#include "materials/Materials.h"

#pragma once

namespace superboy {

	class Object {
		public:
			Object();
			virtual ~Object();

			virtual float intersect(Ray ray) =0;
			virtual vec3 getNormal(Ray& ray, float& point) =0;
			Materials& getMaterials();
		protected:
			Materials materials;
	};

} /* namespace superboy */
