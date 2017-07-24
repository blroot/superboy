/*
 * IntersectionInfo.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#include "IntersectionInfo.h"

namespace superboy {

	IntersectionInfo::IntersectionInfo(float minimum_distance, const Sphere& hitobject) {

		this->minimum_distance = minimum_distance;
		this->hitobject = &hitobject;
	}

	IntersectionInfo::IntersectionInfo() {

		this->minimum_distance = 0;
		this->hitobject = 0;
	}

	IntersectionInfo::~IntersectionInfo() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
