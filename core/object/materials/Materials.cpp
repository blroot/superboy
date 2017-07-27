/*
 * Materials.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Materials.h"

namespace superboy {

	Materials::Materials() {

		this->diffuse = vec3();
		this->emission = vec3();
		this->shininess = vec3();
		this->specular = vec3();
	}

	void Materials::setDiffuse(vec3 diffuse) {

		this->diffuse = diffuse;
	}

	void Materials::setSpecular(vec3 specular) {

		this->specular = specular;
	}

	void Materials::setShininess(vec3 shininess) {

		this->shininess = shininess;
	}

	void Materials::setEmission(vec3 emission) {

		 this->emission = emission;
	}

	vec3& Materials::getDiffuse() {

		return this->diffuse;
	}

	vec3& Materials::getSpecular() {

		return this->specular;
	}

	vec3& Materials::getShininess() {

		return this->shininess;
	}

	vec3& Materials::getEmission() {

		return this->emission;
	}

	Materials::~Materials() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
