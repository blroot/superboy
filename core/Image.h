/*
 * Image.h
 *
 *  Created on: Jul 14, 2017
 *      Author: blroot
 */

#pragma once

#include "../utils/math/vec3.h"
#include <string>
#include <vector>

using namespace math;

namespace superboy {

	class Image {
		public:
			std::vector< std::vector<vec3> > colormap;

			int width;
			int height;

			Image(int width, int height);
			virtual ~Image();

			void setColor(int x, int y, vec3 color); // TODO: Color class (RGB values between 0 & 1)
			vec3 getColor(int x, int y);
			void writeImage(std::string fname);
	};

} /* namespace superboy */
