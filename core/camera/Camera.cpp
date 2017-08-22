/*
 * Camera.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#include "Camera.h"
#include <math.h>
#include <iostream>

const float pi = 3.14159265;

namespace superboy {

	Camera::Camera() {
		this->fov = 0.0f;
	}

	Camera::Camera(vec3 eye, vec3 center, vec3 up, float fov) {

		this->eye = eye;
		this->center = center;
		this->up = up;

		vec3 a = eye - center;
		vec3 b = up;

		this->w = a.normalize();
		this->u = (b.cross(w)).normalize();
		this->v = w.cross(u);

		this->fov = (pi/180)*fov;
	}

	Ray Camera::RayThruPixel(int pixel_y, int pixel_x, int width, int height) {

		// Shoot from the center of the pixel as requested
		float pixel_x_center = pixel_x + 0.5f;
		float pixel_y_center = pixel_y + 0.5f;

		float aspect = (float)width/(float)height;

		float alpha = aspect * tan(this->fov/2.0) * (pixel_x_center - (width/2.0))/(width/2.0);
		float beta = tan(this->fov/2.0) * ((height/2.0) - pixel_y_center)/(height/2.0);

		vec3 direction = alpha*this->u + beta*this->v - this->w;

		return Ray(this->eye, direction);
	}

	Camera::~Camera() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
