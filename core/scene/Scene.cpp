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

	}

	Scene::~Scene() {
		// TODO Auto-generated destructor stub
	}

	void Scene::addObject(Object& object) {

		this->objects.push_back(&object);
	}

	void Scene::addLight(Light& light) {

		this->lights.push_back(&light);
	}

	void Scene::setCamera(Camera &camera) {

		this->camera = camera;
	}

	IntersectionInfo Scene::intersect(Ray ray) {

		float minimum_distance = INFINITY;
		Object *hitobject = 0;

		for (int i = 0; i < this->objects.size(); i++) {

			float t = this->objects[i]->intersect(ray);

			if (t > 0.0f and t < minimum_distance) {

				//std::cout << "Intersection with object " << i << "-> t is : " << t << std::endl;
				minimum_distance = t;
				hitobject = this->objects[i];
			}
		}

		vec3 normal = vec3();

		if (hitobject != NULL) {
			normal = hitobject->getNormal(ray, minimum_distance);
		}

		return IntersectionInfo(minimum_distance, normal , *hitobject);
	}

	std::vector<Object*>& Scene::getObjects() {

		return this->objects;
	}

	std::vector<Light*>& Scene::getLights() {

		return this->lights;
	}

	Camera& Scene::getCamera() {

		return this->camera;
	}

} /* namespace superboy */
