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
#include "primitives/Sphere.h"
#include "primitives/Triangle.h"
#include "light/Directional.h"
#include "light/Point.h"
#include "object/Object.h"
#include "scene/Scene.h"
#include "shading/Shader.h"
#include "../utils/math/mat4.h"
#include "color/color.h"
#include "filereader/SceneReader.h"
#include <string>
#include <iostream>

using namespace superboy;
using namespace math;

int main(int argc, char **argv) {

	if (argc < 2) {
		printHelp();
		return 1;
	}

	SceneReader scene_reader =SceneReader(argv[1]);
	Scene scene = scene_reader.read();

	std::string fname = "BSOD.png";
	int recursion_depth = 5;

	// Create image
	int height = scene.getHeight();
	int width = scene.getWidth();
	Image image = Image(width, height);

	IntersectionInfo intersection;
	//Scene scene = scene_reader.getScene();
	Camera camera = scene.getCamera();
	Shader shader = Shader(scene);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			Ray ray = camera.RayThruPixel(i, j, width, height);
			intersection = scene.intersect(ray);
			image.setColor(i, j, shader.computeColor(intersection, recursion_depth));
		}
	}

	image.writeImage(fname);

	return 0;
}

void printHelp() {

	std::cout << "Usage: ./superboy <scene file>" << std::endl;
}

