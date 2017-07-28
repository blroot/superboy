/*
 * Scene.h
 *
 *  Created on: Jul 23, 2017
 *      Author: blroot
 */

#pragma once

#include "../primitives/Sphere.h"
#include "../camera/Ray.h"
#include "IntersectionInfo.h"
#include "../object/Object.h"
#include "../light/Light.h"
#include "../camera/Camera.h"
#include <vector>

namespace superboy {

class Scene {
	public:
		Scene();
		void addObject(Object &object);
		void addLight(Light &light);
		void setCamera(Camera &camera);
		std::vector<Object*>& getObjects();
		std::vector<Light*>& getLights();
		Camera& getCamera();
		IntersectionInfo intersect(Ray ray);
		virtual ~Scene();
	private:
		std::vector<Object*> objects;
		std::vector<Light*> lights;
		Camera camera;
};

} /* namespace superboy */
