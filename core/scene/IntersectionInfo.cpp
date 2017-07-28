/*
 * IntersectionInfo.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#include "IntersectionInfo.h"

namespace superboy {

	IntersectionInfo::IntersectionInfo(float minimum_distance, vec3 normal, Object& hitobject) {

		this->minimum_distance = minimum_distance;
		this->hitobject = &hitobject;
		this->normal = normal;
	}

	IntersectionInfo::IntersectionInfo() {

		this->minimum_distance = 0;
		this->hitobject = 0;
		this->normal = vec3();
	}

	Object* IntersectionInfo::getHitObject() {

		return this->hitobject;
	}

	float& IntersectionInfo::getMinimumDistance() {

		return this->minimum_distance;
	}

	vec3& IntersectionInfo::getNormal() {

		return this->normal;
	}

	IntersectionInfo::~IntersectionInfo() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
