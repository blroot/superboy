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

	void Scene::addSphere(Sphere sphere) {

		this->spheres.push_back(sphere);
	}

	IntersectionInfo Scene::intersect(Ray ray) {

		float minimum_distance = 90.0f;
		Sphere *hitobject = 0;

		for (int i = 0; i < this->spheres.size(); i++) {

			float t = this->spheres[i].intersect(ray);

			if (t > 0.0f and t < minimum_distance) {

				std::cout << "Intersection with sphere " << i << "-> t is : " << t << std::endl;
				minimum_distance = t;
				hitobject = &this->spheres[i];
				std::cout << "asdadas" << std::endl;
			}
		}

		return IntersectionInfo(minimum_distance, *hitobject);
	}

} /* namespace superboy */
