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
#include <vector>

namespace superboy {

class Scene {
	public:
		std::vector<Sphere> spheres;

		Scene();
		void addSphere(Sphere sphere);
		IntersectionInfo intersect(Ray ray);
		virtual ~Scene();
};

} /* namespace superboy */
