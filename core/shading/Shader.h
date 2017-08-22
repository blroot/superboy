/*
 * Shader.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "../scene/IntersectionInfo.h"
#include "../scene/Scene.h"
#include "../color/color.h"


namespace superboy {

	class Shader {
		public:
			Shader(Scene &scene);
			color computeColor(IntersectionInfo& intersection, int recursion_depth);
			virtual ~Shader();
		private:
			Scene* scene;
			color colorModel(IntersectionInfo& intersection);
			vec3 eyedir;
	};

} /* namespace superboy */
