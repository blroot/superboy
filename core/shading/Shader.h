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

	enum RayType {
		primary, secondary
	};

	class Shader {
		public:
			Shader(Scene &scene);
			color computeColor(IntersectionInfo& intersection);
			virtual ~Shader();
		private:
			Scene* scene;
			void recursiveShading(IntersectionInfo& intersection, color& reflectivity, color& colorvec, int recursion_depth, RayType ray_type);
	};

} /* namespace superboy */
