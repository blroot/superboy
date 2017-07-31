/*
 * color.cpp
 *
 *  Created on: Jul 28, 2017
 *      Author: blroot
 */

#include "color.h"

#include <math.h>

namespace superboy {

	color::color() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	color::color(float x, float y, float z) {

		if (x > 1.0f) {
			this->x = 1.0f;
		} else if (x < 0.0f) {
			this->x = 0.0f;
		} else {
			this->x = x;
		}

		if (y > 1.0f) {
			this->y = 1.0f;
		} else if (y < 0.0f) {
			this->y = 0.0f;
		} else {
			this->y = y;
		}

		if (z > 1.0f) {
			this->z = 1.0f;
		} else if (z < 0.0f) {
			this->z = 0.0f;
		} else {
			this->z = z;
		}
	}

	color color::normalize() const {

		float x, y, z;

		if (this->x > 255.0f) {
			x = 255.0f;
		} else if (this->x < 0.0f) {
			x = 0.0f;
		} else {
			x = this->x;
		}

		if (this->y > 255.0f) {
			y = 255.0f;
		} else if (this->y < 0.0f) {
			y = 0.0f;
		} else {
			y = this->y;
		}

		if (this->z > 255.0f) {
			z = 255.0f;
		} else if (this->z < 0.0f) {
			z = 0.0f;
		} else {
			z = this->z;
		}

		return color(x, y, z);
	}


	bool color::operator==(const color &vector) {
		return this->x == vector.x && this->y == vector.y && this->z == vector.z;
	}

	color color::operator+(color right) {
		return color(this->x + right.x, this->y + right.y, this->z + right.z);
	}

	color& color::operator+=(color right) {
		this->x = this->x + right.x;
		this->y = this->y + right.y;
		this->z = this->z + right.z;

		return *this;
	}

	color color::operator-(color right) {
		return color(this->x - right.x, this->y - right.y, this->z - right.z);
	}

	color color::operator*(float scalar) {
		return color(scalar * this->x, scalar * this->y, scalar * this->z);
	}

	color operator*(float scalar, const color &vector) {
		return color(scalar * vector.x, scalar * vector.y, scalar * vector.z);
	}

	color operator*(int scalar, const color &vector) {
		return color(scalar * vector.x, scalar * vector.y, scalar * vector.z);
	}

	std::ostream& operator<<(std::ostream& stream, const color& vector) {
		stream << "color: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

}
