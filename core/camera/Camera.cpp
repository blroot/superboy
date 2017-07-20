/*
 * Camera.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "Camera.h"
#include <math.h>
#include <iostream>

namespace superboy {

	Camera::Camera(vec3 eye, vec3 center, vec3 up, float fov) {

		this->eye = eye;
		this->center = center;
		this->up = up;

		vec3 a = eye - center;
		vec3 b = up;

		this->w = a.normalize();
		this->u = (b.cross(w)).normalize();
		this->v = w.cross(u);

		this->fov = fov;
	}

	Ray Camera::RayThruPixel(int pixel_x, int pixel_y, int width, int height) {

		float alpha = tan(this->fov/2) * (pixel_y - width/2)/width/2;
		float beta = tan(this->fov/2) * (height/2 - pixel_x)/height/2;

		std::cout << "Alpha: " << alpha << "Beta: " << beta << std::endl;

		vec3 direction = alpha*this->u + beta*this->v - this->w;

		return Ray(this->eye, direction);
	}

	Camera::~Camera() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
