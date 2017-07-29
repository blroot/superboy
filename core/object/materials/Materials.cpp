/*
 * Materials.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Materials.h"

namespace superboy {

	Materials::Materials() {

		this->diffuse = color();
		this->emission = color();
		this->shininess = 0.0f;
		this->specular = color();
		this->ambient = color();
	}

	void Materials::setAmbient(color ambient) {

		this->ambient = ambient;
	}

	void Materials::setDiffuse(color diffuse) {

		this->diffuse = diffuse;
	}

	void Materials::setSpecular(color specular) {

		this->specular = specular;
	}

	void Materials::setShininess(float shininess) {

		this->shininess = shininess;
	}

	void Materials::setEmission(color emission) {

		 this->emission = emission;
	}

	color& Materials::getAmbient() {

		return this->ambient;
	}

	color& Materials::getDiffuse() {

		return this->diffuse;
	}

	color& Materials::getSpecular() {

		return this->specular;
	}

	float& Materials::getShininess() {

		return this->shininess;
	}

	color& Materials::getEmission() {

		return this->emission;
	}

	Materials::~Materials() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
