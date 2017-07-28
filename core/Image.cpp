/*
 * Image.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: blroot
 */

#include "Image.h"
#include <FreeImage.h>
#include <iostream>

namespace superboy {

	Image::Image(int width, int height) {

		this->width = width;
		this->height = height;

		// Initialize vector - set all pixels to black by default
		this->colormap.resize(this->height, std::vector<color>(this->width, color()));

	}

	Image::~Image() {
		// TODO Auto-generated destructor stub
	}

	void Image::setColor(int x, int y, color colorvec) {

		if (x <= this->height && y <= this->width) {

			this->colormap[x][y] = colorvec;
		}
	}

	color Image::getColor(int x, int y) {

		if (x <= this->height && y <= this->width) {

			return this->colormap[x][y];
		}

		// Return black if out of bounds
		return color();
	}

	void Image::writeImage(std::string fname) {

		FreeImage_Initialise();

		int pix = this->width * this->height;
		BYTE pixels[3*pix];

		int pixelsElement = 0;
		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				pixels[pixelsElement] = getColor(i, j).z;
				pixels[pixelsElement+1] = getColor(i, j).y;
				pixels[pixelsElement+2] = getColor(i, j).x;
				pixelsElement += 3;
			}
		}

		FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, this->width, this->height, this->width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);

		FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);

		FreeImage_DeInitialise();
	}

} /* namespace superboy */
