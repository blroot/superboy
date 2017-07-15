/*
 * Image.h
 *
 *  Created on: Jul 14, 2017
 *      Author: blroot
 */

#pragma once

#include "../utils/math/vec3.h"
#include <string>

using namespace math;
using namespace std;

namespace superboy {

	class Image {
		public:
			vec3 colormap[100][100]; // TODO: fix this dirty b*shit
			int width;
			int height;

			Image(int width, int height);
			virtual ~Image();

			void setColor(int x, int y, vec3 color); // TODO: Color class (RGB values between 0 & 1)
			vec3 getColor(int x, int y);
			void writeImage(string fname);
	};

} /* namespace superboy */
