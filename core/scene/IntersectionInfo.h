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
		IntersectionInfo(float minimum_distance, vec3 normal, Object &hitobject);
		Object* getHitObject();
		float& getMinimumDistance();
		vec3& getNormal();
		virtual ~IntersectionInfo();
	private:
		float minimum_distance;
		vec3 normal;
		Object* hitobject;
	};

} /* namespace superboy */
