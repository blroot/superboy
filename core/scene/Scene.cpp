/*
 * Scene.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#include "Scene.h"
#include <iostream>

namespace superboy {

	Scene::Scene() {

	}

	Scene::~Scene() {
		// TODO Auto-generated destructor stub
	}

	void Scene::addObject(Object& object) {

		this->objects.push_back(&object);
	}

	IntersectionInfo Scene::intersect(Ray ray) {

		float minimum_distance = 90.0f;
		Object *hitobject = 0;

		for (int i = 0; i < this->objects.size(); i++) {

			float t = this->objects[i]->intersect(ray);

			if (t > 0.0f and t < minimum_distance) {

				std::cout << "Intersection with sphere " << i << "-> t is : " << t << std::endl;
				minimum_distance = t;
				hitobject = this->objects[i];
				std::cout << "asdadas" << std::endl;
			}
		}

		return IntersectionInfo(minimum_distance, *hitobject);
	}

} /* namespace superboy */
