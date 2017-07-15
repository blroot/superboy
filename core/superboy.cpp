/*
 * superboy.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: blroot
 */

#include "Image.h"

using namespace superboy;

int main(int argc, char **argv) {

	int width = 100;
	int height = 100;
	string fname = "BSOD";

	Image image = Image(width, height);

	image.setColor(0, 0, vec3(255.0f, 0.0f, 0.0f));
	image.setColor(50, 50, vec3(0.0f, 255.0f, 0.0f));
	image.setColor(99, 99, vec3(0.0f, 0.0f, 255.0f));

	image.writeImage(fname);
}

