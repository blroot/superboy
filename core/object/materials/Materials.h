/*
 * Materials.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "../../../utils/math/vec3.h"

using namespace math;

namespace superboy {

	class Materials {
		public:
			Materials();
			virtual ~Materials();
			void setDiffuse(vec3 diffuse);
			void setSpecular(vec3 specular);
			void setShininess(vec3 shininess);
			void setEmission(vec3 emission);
			vec3& getDiffuse();
			vec3& getSpecular();
			vec3& getShininess();
			vec3& getEmission();
		private:
			vec3 diffuse;
			vec3 specular;
			vec3 shininess;
			vec3 emission;
	};

} /* namespace superboy */
