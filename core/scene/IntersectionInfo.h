/*
 * IntersectionInfo.h
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#pragma once

#include "../object/Object.h"

namespace superboy {

class IntersectionInfo {
	public:
		float minimum_distance;
		const Object* hitobject;

		IntersectionInfo();
		IntersectionInfo(float minimum_distance, const Object &hitobject);
		virtual ~IntersectionInfo();
	};

} /* namespace superboy */
