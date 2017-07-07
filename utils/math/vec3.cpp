/*
 * vec3.cpp
 *
 *  Created on: Jul 4, 2017
 *      Author: blroot
 */

#include "vec3.h"
#include <math.h>

namespace math {

	vec3::vec3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3 vec3::cross(vec3 vector) {
		return vec3(this->y*vector.z - this->z*vector.y,
				    -(this->x*vector.z - this->z*vector.x),
					this->x*vector.y - this->y*vector.x);
	}

	float vec3::norm() {
		return sqrt(x*x + y*y + z*z);
	}

	vec3 vec3::normalize() {
		float norm = this->norm();
		return vec3(this->x/norm, this->y/norm, this->z/norm);
	}

	float vec3::dot(vec3 vector) {
		return this->x * vector.x + this->y * vector.y + this->z * vector.z;
	}

	bool vec3::operator==(const vec3 &vector) {
		return this->x == vector.x && this->y == vector.y && this->z == vector.z;
	}

	vec3 vec3::operator+(vec3 right) {
		return vec3(this->x + right.x, this->y + right.y, this->z + right.z);
	}

	vec3 vec3::operator-(vec3 right) {
		return vec3(this->x - right.x, this->y - right.y, this->z - right.z);
	}

	vec3 vec3::operator*(float scalar) {
		return vec3(scalar * this->x, scalar * this->y, scalar * this->z);
	}

	vec3 operator*(float scalar, const vec3 &vector) {
		return vec3(scalar * vector.x, scalar * vector.y, scalar * vector.z);
	}

	vec3 operator*(int scalar, const vec3 &vector) {
		return vec3(scalar * vector.x, scalar * vector.y, scalar * vector.z);
	}
}
