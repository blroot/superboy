/*
 * Image.h
 *
 *  Created on: Jul 14, 2017
 *      Author: blroot
 */

#pragma once

#include "color/color.h"
#include <string>
#include <vector>

namespace superboy {

	class Image {
		public:
			std::vector< std::vector<color> > colormap;

			int width;
			int height;

			Image(int width, int height);
			virtual ~Image();

			void setColor(int x, int y, color colorvec); // TODO: Color class (RGB values between 0 & 1)
			color getColor(int x, int y);
			void writeImage(std::string fname);
	};

} /* namespace superboy */
