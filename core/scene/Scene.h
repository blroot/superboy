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
#include <memory>

namespace superboy {

class Scene {
	public:
		Scene();
		void addObject(std::shared_ptr<Object> object);
		void addLight(std::shared_ptr<Light> light);
		void setCamera(Camera &camera);
		void setResolution(int width, int height);
		void setMaxdepth(int depth);
		void setFilename(std::string filename);
		std::vector< std::shared_ptr<Object> >& getObjects();
		std::vector< std::shared_ptr<Light> >& getLights();
		Camera& getCamera();
		int& getWidth();
		int& getHeight();
		std::string& getFilename();
		int& getMaxdepth();
		IntersectionInfo intersect(Ray& ray);
		bool isInShadow(Ray& ray, float& distance_to_light);
		virtual ~Scene();
	private:
		std::vector< std::shared_ptr<Object> > objects;
		std::vector< std::shared_ptr<Light> > lights;
		Camera camera;
		int width;
		int height;
		int maxdepth;
		std::string filename;
};

} /* namespace superboy */
