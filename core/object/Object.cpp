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

	float Object::intersect(Ray ray) {

		return 0.0f;
	}

}