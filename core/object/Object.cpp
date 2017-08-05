/*
 * Object.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: blroot
 */

#include "Object.h"

namespace superboy {

	Object::Object() {

		this->materials = Materials();
	}

	Object::~Object() {
		// TODO Auto-generated destructor stub
	}

	Materials& Object::getMaterials() {

		return this->materials;
	}

	mat4& Object::getTranform() {

		return this->transform;
	}

	void Object::setTransform(mat4 transform) {

		this->transform = transform;
	}

}
