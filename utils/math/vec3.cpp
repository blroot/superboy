#include <vec3.h>

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
				    -(this->x*vector.z - this->z*vector.x,
					this->x*vector.y - this->y*vector.x));
	}

	vec3 operator+(vec3 left, vec3 right) {
		return vec3(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	vec3 operator-(vec3 left, vec3 right) {
		return vec3(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	vec3 operator*(float scalar, vec3 vector) {
		return vec3(scalar * vector.x, scalar * vector.y, scalar * vector.z);
	}

	float operator*(vec3 left, vec3 right) {
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}
}
