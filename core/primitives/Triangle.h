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
			Intersect intersect(Ray ray);
			void applyTransform();
			vec3 getNormal(Ray& ray, float& lambda);
			vec3 getPoint(Ray& ray, float& lambda);
			vec3& getA();
			vec3& getC();
			vec3& getB();
		private:
			vec3 normal;
			vec3 A;
			vec3 B;
			vec3 C;
	};

} /* namespace superboy */
