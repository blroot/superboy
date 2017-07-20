/*
 * superboy.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: blroot
 */

#include "Image.h"
#include "camera/Ray.h"
#include "camera/Camera.h"
#include "primitives/Sphere.h"
#include <string>
#include <iostream>

using namespace superboy;

int main(int argc, char **argv) {

	int width = 640;
	int height = 640;
	std::string fname = "BSOD.png";

	Image image = Image(width, height);
	Camera camera = Camera(vec3(0.0f, 0.0f, 10.0f), vec3(), vec3(0.0f, 0.1f, 0.0f), 45.0f);
	Sphere sphere = Sphere(vec3(), 1.0f);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			std::cout << "X: " << i << "Y: " << j << std::endl;

			Ray ray = camera.RayThruPixel(i, j, width, height);
			std::cout << "Ray eye: " << ray.eye.x << ray.eye.y << ray.eye.z << "Ray dir: " << ray.direction.x << ray.direction.y << ray.direction.z << std::endl;

			float intersection = sphere.intersect(ray);

			std::cout << "Intersection: " << intersection << std::endl;

			if (intersection > 0) {

				image.setColor(i, j, vec3(255.0f, 0.0f, 0.0f));
				std::cout << "Intersection true: " << std::endl;
			}

		}
	}

	image.writeImage(fname);
}

