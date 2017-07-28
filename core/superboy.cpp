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
#include "primitives/Triangle.h"
#include "light/Directional.h"
#include "object/Object.h"
#include "scene/Scene.h"
#include "shading/Shader.h"
#include "../utils/math/mat4.h"
#include "color/color.h"
#include <string>
#include <iostream>

using namespace superboy;
using namespace math;

int main(int argc, char **argv) {

	int width = 640;
	int height = 480;
	std::string fname = "BSOD.png";

	// Create image
	Image image = Image(width, height);

	// Create a camera
	Camera camera = Camera(vec3(0.0f, 0.0f, 5.0f), vec3(), vec3(0.0f, 1.0f, 0.0f), 45.0f);

	// Create a directional light
	Directional directional = Directional(vec3(0.0f, -3.0f, 3.0f), color(100.0f, 100.0f, 100.0f));

	// Create two spheres
	Sphere sphere0 = Sphere(vec3(-1.0f, 0.0f, 0.0f), 1.0f);
	//Sphere sphere1 = Sphere(vec3(0.0f, 0.0f, 0.0f), 0.03f);
	//Sphere sphere2 = Sphere(vec3(1.0f, 0.0f, 0.0f), 0.2f);
	Triangle triangle0 = Triangle(vec3(-2.0f, 0.0f, -2.0f), vec3(0.0f, 2.0f, 0.0f), vec3(2.0f, 0.0f, 0.0f));

	// Set objects materials
	sphere0.getMaterials().setDiffuse(color(0.2f, 0.2f, 0.2f));
	sphere0.getMaterials().setEmission(color(1.0f, 1.0f, 1.0f));
	sphere0.getMaterials().setShininess(100.0f);
	sphere0.getMaterials().setSpecular(color(1.0f, 1.0f, 1.0f));

	triangle0.getMaterials().setDiffuse(color(1.0f, 1.0f, 0.0f));
	triangle0.getMaterials().setEmission(color(0.0f, 0.0f, 0.0f));
	triangle0.getMaterials().setShininess(40.0f);
	triangle0.getMaterials().setSpecular(color(1.0f, 1.0f, 1.0f));

	// Add objects and camera to Scene instance
	Scene scene = Scene();
	scene.setCamera(camera);
	scene.addObject(sphere0);
	//scene.addObject(sphere1);
	//scene.addObject(sphere2);
	scene.addObject(triangle0);

	// Add light to scene
	scene.addLight(directional);


	IntersectionInfo intersection;
	Shader shader(scene);


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			//std::cout << "X: " << i << "Y: " << j << std::endl;

			Ray ray = camera.RayThruPixel(i, j, width, height);
			//std::cout << "Ray eye: " << ray.eye.x << ray.eye.y << ray.eye.z << "Ray dir: " << ray.direction.x << ray.direction.y << ray.direction.z << std::endl;

			intersection = scene.intersect(ray);

			image.setColor(i, j, shader.computeColor(intersection));

		}
	}

	image.writeImage(fname);
}

