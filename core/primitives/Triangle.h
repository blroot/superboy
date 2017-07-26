/*
 * Triangle.h
 *
 *  Created on: Jul 24, 2017
 *      Author: blroot
 */

#pragma once

#include "../object/Object.h"

namespace superboy {

	class Triangle : public Object {
		public:
			Triangle(vec3 A, vec3 B, vec3 C);
			virtual ~Triangle();
			float intersect(Ray ray);
		private:
			vec3 A;
			vec3 B;
			vec3 C;
	};

} /* namespace superboy */
