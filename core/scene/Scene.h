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
#include <vector>

namespace superboy {

class Scene {
	public:
		std::vector<Object*> objects;
		std::vector<Light*> lights;

		Scene();
		void addObject(Object &object);
		void addLight(Light &light);
		IntersectionInfo intersect(Ray ray);
		virtual ~Scene();
};

} /* namespace superboy */
