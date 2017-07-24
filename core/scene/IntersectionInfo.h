/*
 * IntersectionInfo.h
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#pragma once

#include "../primitives/Sphere.h"

namespace superboy {

class IntersectionInfo {
	public:
		float minimum_distance;
		const Sphere* hitobject;

		IntersectionInfo();
		IntersectionInfo(float minimum_distance, const Sphere &hitobject);
		virtual ~IntersectionInfo();
	};

} /* namespace superboy */
