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
		IntersectionInfo();
		IntersectionInfo(float minimum_distance, vec3 normal, vec3 point, Object &hitobject);
		Object* getHitObject();
		float& getMinimumDistance();
		vec3& getNormal();
		vec3& getPoint();
		virtual ~IntersectionInfo();
	private:
		float minimum_distance;
		vec3 normal;
		vec3 point;
		Object* hitobject;
	};

} /* namespace superboy */
