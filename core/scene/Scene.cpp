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

		return IntersectionInfo(minimum_distance, *hitobject);
	}

} /* namespace superboy */
