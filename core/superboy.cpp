/*
 * superboy.cpp
 *
 *  Created on: Jul 15, 2017
 *      Author: blroot
 */

#include "superboy.h"
#include "Image.h"
#include "camera/Ray.h"
#include "camera/Camera.h"
#include "scene/Scene.h"
#include "shading/Shader.h"
#include "filereader/SceneReader.h"
#include <string>
#include <iostream>
#include <omp.h>

using namespace superboy;
using namespace math;

int main(int argc, char **argv) {

	if (argc < 2) {
		printHelp();
		return 1;
	}

	SceneReader scene_reader = SceneReader(argv[1]);
	Scene scene = scene_reader.read();

	std::string fname = scene.getFilename();
	int recursion_depth = scene.getMaxdepth();

	// Create image
	int height = scene.getHeight();
	int width = scene.getWidth();
	Image image = Image(width, height);

	IntersectionInfo intersection;
	Camera camera = scene.getCamera();
	Shader shader = Shader(scene);

	int pixels_processed = 0;
	int total_pixels = width * height;

	#pragma omp parallel for collapse(2) private(intersection)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			Ray ray = camera.RayThruPixel(i, j, width, height);
			intersection = scene.intersect(ray);
			image.setColor(i, j, shader.computeColor(intersection, recursion_depth));

			#pragma omp critical
			{
				pixels_processed++;
				//printProgress(total_pixels, pixels_processed);
			}
		}
	}

	image.writeImage(fname);

	return 0;
}

void printHelp() {

	std::cout << "Usage: ./superboy <scene file>" << std::endl;
}

void printProgress(int& total_pixels, int& pixels_processed) {

	std::cout << "Rendering: " << 100*pixels_processed/total_pixels << " %" << std::endl;
}

