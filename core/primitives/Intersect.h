/*
 * Intersect.h
 *
 *  Created on: Aug 15, 2017
 *      Author: blroot
 */

#pragma once

#include "../../utils/math/vec3.h"

using namespace math;

namespace superboy {

class Intersect {
	public:
		Intersect();
		Intersect(float distance, vec3 hitpoint, vec3 normal);

		float& getDistance();
		vec3& getHitpoint();
		vec3& getNormal();

		virtual ~Intersect();
	private:
		float distance;
		vec3 hitpoint;
		vec3 normal;
};

} /* namespace superboy */
