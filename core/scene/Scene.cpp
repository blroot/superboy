/*
 * Scene.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#include "Scene.h"
#include <iostream>
#include <math.h>
#include "../primitives/Intersect.h"

namespace superboy {

	Scene::Scene() {

		this->height = 0;
		this->width = 0;
		this->maxdepth = 1;
		this->filename = "default.png";
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

	void Scene::setFilename(std::string filename) {

		this->filename = filename;
	}

	void Scene::setMaxdepth(int depth) {

		this->maxdepth = depth;
	}

	IntersectionInfo Scene::intersect(Ray ray) {

		float minimum_distance = INFINITY;
		std::shared_ptr<Object> hitobject = nullptr;
		Intersect intersection;

		for (int i = 0; i < this->objects.size(); i++) {

			intersection = this->objects[i]->intersect(ray);

			if (intersection.getDistance() > 0.0f and intersection.getDistance() < minimum_distance) {

				minimum_distance = intersection.getDistance();
				hitobject = this->objects[i];
			}
		}

		vec3 normal = vec3();
		vec3 hitpoint = vec3();

		if (hitobject != nullptr) {
			//normal = hitobject->getNormal(ray, minimum_distance);
			//hitpoint = hitobject->getPoint(ray, minimum_distance);

			normal = intersection.getNormal();
			hitpoint = intersection.getHitpoint();
		}

		return IntersectionInfo(minimum_distance, normal, hitpoint, ray, hitobject);
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

	int& Scene::getMaxdepth() {

		return this->maxdepth;
	}

	std::string& Scene::getFilename() {

		return this->filename;
	}

} /* namespace superboy */
