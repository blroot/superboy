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
#include "light/Point.h"
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

	int width = 1920;
	int height = 1080;
	std::string fname = "BSOD.png";

	// Create image
	Image image = Image(width, height);

	// Create a camera
	Camera camera = Camera(vec3(0.0f, 0.0f, 5.0f), vec3(), vec3(0.0f, 1.0f, 0.0f), 45.0f);

	// Create a directional light
	Directional directional0 = Directional(vec3(-1.0f, -1.0f, 0.5f), color(1.0f, 1.0f, 1.0f));
	Directional directional1 = Directional(vec3(1.0f, -1.0f, 0.7f), color(1.0f, 1.0f, 1.0f));
	Point point0 = Point(vec3(3.0f, 0.0f, 1.5f), color(1.0f, 1.0f, 1.0f));
	//Point point1 = Point(vec3(0.0f, 0.0f, 0.5f), color(1.0f, 1.0f, 1.0f));

	// Create two spheres
	Sphere sphere0 = Sphere(vec3(-1.0f, 1.0f, 1.0f), 0.4f);
	Sphere sphere1 = Sphere(vec3(-1.0f, -1.0f, 1.0f), 0.4f);
	Sphere sphere2 = Sphere(vec3(0.0f, 0.0f, 1.0f), 0.7f);
	Sphere sphere3 = Sphere(vec3(1.0f, 1.0f, 1.0f), 0.4f);
	Sphere sphere4 = Sphere(vec3(1.0f, -1.0f, 1.0f), 0.4f);
	//Triangle triangle0 = Triangle(vec3(-10.0f, -10.0f, 0.0f), vec3(0.0f, 10.0f, 0.0f), vec3(10.0f, -10.0f, 0.0f));
	//Triangle triangle1 = Triangle(vec3(-5.0f, 5.0f, -10.0f), vec3(-5.0f, -5.0f, -10.0f), vec3(5.0f, -5.0f, -10.0f));

	// Set objects materials
	sphere0.getMaterials().setAmbient(color(0.1f, 0.1f, 0.1f));
	sphere0.getMaterials().setDiffuse(color(0.0f, 1.0f, 0.0f));
	sphere0.getMaterials().setEmission(color(0.0f, 0.0f, 0.0f));
	sphere0.getMaterials().setShininess(50.0f);
	sphere0.getMaterials().setSpecular(color(0.5f, 0.5f, 0.5f));

	sphere1.getMaterials().setAmbient(color(0.1f, 0.1f, 0.1f));
	sphere1.getMaterials().setDiffuse(color(0.0f, 0.0f, 1.0f));
	sphere1.getMaterials().setEmission(color(0.0f, 0.0f, 0.0f));
	sphere1.getMaterials().setShininess(50.0f);
	sphere1.getMaterials().setSpecular(color(0.5f, 0.5f, 0.5f));

	sphere2.getMaterials().setAmbient(color(0.1f, 0.1f, 0.1f));
	sphere2.getMaterials().setDiffuse(color(1.0f, 0.0f, 0.0f));
	sphere2.getMaterials().setEmission(color(0.0f, 0.0f, 0.0f));
	sphere2.getMaterials().setShininess(50.0f);
	sphere2.getMaterials().setSpecular(color(0.5f, 0.5f, 0.5f));

	sphere3.getMaterials().setAmbient(color(0.1f, 0.1f, 0.1f));
	sphere3.getMaterials().setDiffuse(color(1.0f, 1.0f, 0.0f));
	sphere3.getMaterials().setEmission(color(0.0f, 0.0f, 0.0f));
	sphere3.getMaterials().setShininess(50.0f);
	sphere3.getMaterials().setSpecular(color(0.5f, 0.5f, 0.5f));

	sphere4.getMaterials().setAmbient(color(0.1f, 0.1f, 0.1f));
	sphere4.getMaterials().setDiffuse(color(0.0f, 1.0f, 1.0f));
	sphere4.getMaterials().setEmission(color(0.0f, 0.0f, 0.0f));
	sphere4.getMaterials().setShininess(50.0f);
	sphere4.getMaterials().setSpecular(color(0.5f, 0.5f, 0.5f));

	// Add objects and camera to Scene instance
	Scene scene = Scene();
	scene.setCamera(camera);
	scene.addObject(sphere0);
	scene.addObject(sphere1);
	scene.addObject(sphere2);
	scene.addObject(sphere3);
	scene.addObject(sphere4);
	//scene.addObject(triangle0);
	//scene.addObject(triangle1);

	// Add light to scene
	scene.addLight(directional0);
	//scene.addLight(directional1);
	//scene.addLight(point0);
	//scene.addLight(point1);


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

