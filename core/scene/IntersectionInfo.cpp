/*
 * IntersectionInfo.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#include "IntersectionInfo.h"

namespace superboy {

	IntersectionInfo::IntersectionInfo(float minimum_distance, vec3 normal, vec3 hitpoint, Ray& ray, std::shared_ptr<Object> hitobject) {

		this->minimum_distance = minimum_distance;
		this->hitobject = hitobject;
		this->hitpoint = hitpoint;
		this->normal = normal;
		this->ray = &ray;
	}

	IntersectionInfo::IntersectionInfo() {

		this->minimum_distance = 0;
		this->hitobject = nullptr;
		this->normal = vec3();
		this->hitpoint = vec3();
		this->ray = 0;
	}

	std::shared_ptr<Object> IntersectionInfo::getHitObject() {

		return this->hitobject;
	}

	float& IntersectionInfo::getMinimumDistance() {

		return this->minimum_distance;
	}

	vec3& IntersectionInfo::getNormal() {

		return this->normal;
	}

	vec3& IntersectionInfo::getPoint() {

		return this->hitpoint;
	}

	Ray* IntersectionInfo::getRay() {

		return this->ray;
	}

	IntersectionInfo::~IntersectionInfo() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
