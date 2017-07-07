/*
 * vec3.h
 *
 *  Created on: Jul 4, 2017
 *      Author: blroot
 */

namespace math {

	struct vec3 {

		float x;
		float y;
		float z;

		vec3();
		vec3(float x, float y, float z);

		float dot(vec3 vector);
		bool operator==(const vec3 &vector);
		vec3 operator+(vec3 right);
		vec3 operator-(vec3 right);
		vec3 operator*(float scalar);
		friend vec3 operator*(float scalar, const vec3& vector);
		friend vec3 operator*(int scalar, const vec3& vector);
		vec3 cross(vec3 vector);
		float norm();
		vec3 normalize();
	};

}
