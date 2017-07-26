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
#include "object/Object.h"
#include "scene/Scene.h"
#include "../utils/math/mat4.h"
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

	// Create two spheres
	Sphere sphere0 = Sphere(vec3(-1.0f, 0.0f, 0.0f), 0.1f);
	Sphere sphere1 = Sphere(vec3(0.0f, 0.0f, 0.0f), 0.03f);
	Sphere sphere2 = Sphere(vec3(1.0f, 0.0f, 0.0f), 0.2f);
	Triangle triangle0 = Triangle(vec3(), vec3(0.0f, 0.3f, 0.0f), vec3(0.5f, 0.0f, 0.0f));

	// Scale triangle
	float sx = 2.0f;
	float sy = 3.0f;
	float sz = 4.0f;

	mat4 scalematrix;
	scalematrix = scalematrix.scale(2.0f, 3.0f, 4.0f);

	vec3 scale = scalematrix * sphere0.getCenter();

	std::cout << "x: " << scale.x << "y: " << scale.y << "z: " << scale.z << std::endl;

	// Add spheres to Scene instance
	Scene scene = Scene();
	scene.addObject(sphere0);
	scene.addObject(sphere1);
	scene.addObject(sphere2);
	scene.addObject(triangle0);


	IntersectionInfo intersection;


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			//std::cout << "X: " << i << "Y: " << j << std::endl;

			Ray ray = camera.RayThruPixel(i, j, width, height);
			//std::cout << "Ray eye: " << ray.eye.x << ray.eye.y << ray.eye.z << "Ray dir: " << ray.direction.x << ray.direction.y << ray.direction.z << std::endl;

			intersection = scene.intersect(ray);

			if (intersection.hitobject != 0) {

				image.setColor(i, j, vec3(255.0f, 0.0f, 0.0f));
				//std::cout << "Intersection true: " << std::endl;
			} else {
				image.setColor(i, j, vec3(255.0f, 255.0f, 255.0f));
			}

		}
	}

	image.writeImage(fname);
}

