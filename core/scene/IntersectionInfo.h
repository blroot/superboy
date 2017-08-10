/*
 * IntersectionInfo.h
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#pragma once

#include "../object/Object.h"
#include <memory>

namespace superboy {

class IntersectionInfo {
	public:
		IntersectionInfo();
		IntersectionInfo(float minimum_distance, vec3 normal, vec3 hitpoint, Ray& ray, std::shared_ptr<Object> hitobject);
		std::shared_ptr<Object> getHitObject();
		float& getMinimumDistance();
		vec3& getNormal();
		vec3& getPoint();
		Ray* getRay();
		virtual ~IntersectionInfo();
	private:
		float minimum_distance;
		vec3 normal;
		vec3 hitpoint;
		Ray* ray;
		std::shared_ptr<Object> hitobject;
	};

} /* namespace superboy */
