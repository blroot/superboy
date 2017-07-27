/*
 * Shader.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "../../utils/math/vec3.h"
#include "../scene/IntersectionInfo.h"
#include "../scene/Scene.h"

using namespace math;

namespace superboy {

	class Shader {
		public:
			Shader();
			vec3 computeColor(IntersectionInfo& intersection, Scene& scene);
			virtual ~Shader();
	};

} /* namespace superboy */
