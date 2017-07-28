/*
 * Materials.h
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#pragma once

#include "../../color/color.h"

namespace superboy {

	class Materials {
		public:
			Materials();
			virtual ~Materials();
			void setDiffuse(color diffuse);
			void setSpecular(color specular);
			void setShininess(float shininess);
			void setEmission(color emission);
			color& getDiffuse();
			color& getSpecular();
			float& getShininess();
			color& getEmission();
		private:
			color diffuse;
			color specular;
			float shininess;
			color emission;
	};

} /* namespace superboy */
