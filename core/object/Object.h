/*
 * Object.h
 *
 *  Created on: Jul 24, 2017
 *      Author: blroot
 */

#pragma once

#include "../camera/Ray.h"
#include "materials/Materials.h"
#include "../../utils/math/mat4.h"
#include "../primitives/Intersect.h"

namespace superboy {

	class Object {
		public:
			Object();
			virtual ~Object();

			virtual Intersect intersect(Ray ray) =0;
			virtual vec3 getNormal(Ray& ray, float& lambda) =0;
			virtual vec3 getPoint(Ray& ray, float& lambda) =0;
			void setTransform(mat4 transform);
			virtual void applyTransform() =0;
			Materials& getMaterials();
			mat4& getTranform();
		protected:
			Materials materials;
			mat4 transform;
	};

} /* namespace superboy */
