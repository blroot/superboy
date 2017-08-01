/*
 * Scene.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#include "Scene.h"
#include <iostream>
#include <math.h>

namespace superboy {

	Scene::Scene() {

		this->height = 0;
		this->width = 0;
	}

	Scene::~Scene() {
		// TODO Auto-generated destructor stub
	}

	void Scene::addObject(std::shared_ptr<Object> object) {

		this->objects.push_back(object);
	}

	void Scene::addLight(std::shared_ptr<Light> light) {

		this->lights.push_back(light);
	}

	void Scene::setCamera(Camera &camera) {

		this->camera = camera;
	}

	void Scene::setResolution(int width, int height) {

		this->height = height;
		this->width = width;
	}

	IntersectionInfo Scene::intersect(Ray ray) {

		float minimum_distance = INFINITY;
		std::shared_ptr<Object> hitobject = nullptr;

		for (int i = 0; i < this->objects.size(); i++) {

			float t = this->objects[i]->intersect(ray);

			if (t > 0.0f and t < minimum_distance) {

				//std::cout << "Intersection with object " << i << "-> t is : " << t << std::endl;
				minimum_distance = t;
				hitobject = this->objects[i];
			}
		}

		vec3 normal = vec3();
		vec3 point = vec3();

		if (hitobject != NULL) {
			normal = hitobject->getNormal(ray, minimum_distance);
		}

		return IntersectionInfo(minimum_distance, normal, ray, hitobject);
	}

	std::vector< std::shared_ptr<Object> >& Scene::getObjects() {

		return this->objects;
	}

	std::vector< std::shared_ptr<Light> >& Scene::getLights() {

		return this->lights;
	}

	Camera& Scene::getCamera() {

		return this->camera;
	}

	int& Scene::getWidth() {

		return this->width;
	}

	int& Scene::getHeight() {

		return this->height;
	}

} /* namespace superboy */
