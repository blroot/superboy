/*
 * SceneReader.h
 *
 *  Created on: Jul 30, 2017
 *      Author: blroot
 */

#pragma once

#include <string>
#include <sstream>
#include "../scene/Scene.h"
#include "../../utils/math/vec3.h"
#include "../camera/Camera.h"
#include "../light/Directional.h"
#include "../light/Point.h"
#include "../color/color.h"
#include "../primitives/Triangle.h"
#include "../primitives/Sphere.h"

namespace superboy {

class SceneReader {
	public:
		SceneReader(const char* file);
		Scene read();
		virtual ~SceneReader();
	private:
		bool readvals(std::stringstream &s, const int numvals, float* values);
		const char* file;
		color ambient;
		color diffuse;
		color specular;
		color emission;
		float shininess;
		std::vector<vec3> vertex_buffer;
};

} /* namespace superboy */
