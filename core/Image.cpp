/*
 * Image.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: blroot
 */

#include "Image.h"
#include <FreeImage.h>

namespace superboy {

	Image::Image(int width, int height) {

		this->width = width;
		this->height = height;

		// Initialize vector - set all pixels to black by default
		this->colormap.resize(this->width, std::vector<vec3>(this->height, vec3()));

	}

	Image::~Image() {
		// TODO Auto-generated destructor stub
	}

	void Image::setColor(int x, int y, vec3 color) {

		if (x <= this->width && y <= this->height) {

			this->colormap[x][y] = color;
		}
	}

	vec3 Image::getColor(int x, int y) {

		if (x <= this->width && y <= this->height) {

			return this->colormap[x][y];
		}

		// Return black if out of bounds
		return vec3();
	}

	void Image::writeImage(std::string fname) {

		FreeImage_Initialise();

		int pix = this->width * this->height;
		BYTE pixels[3*pix];

		int pixelsElement = 0;
		for (int i = this->height-1; i >= 0; i--) {

			for (int j = this->width-1; j >=0; j--) {
				pixels[pixelsElement] = getColor(i, j).x;
				pixels[pixelsElement+1] = getColor(i, j).y;
				pixels[pixelsElement+2] = getColor(i, j).z;
				pixelsElement += 3;
			}
		}

		FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, this->width, this->height, this->width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);

		FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
	}

} /* namespace superboy */
