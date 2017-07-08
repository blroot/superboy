/*
 * mat4.h
 *
 *  Created on: Jul 8, 2017
 *      Author: blroot
 */

namespace math {

	struct mat4 {

		float elements[16];

		mat4();
		mat4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
		mat4(float diagonal);

		mat4 transpose();
		float determinant();
		mat4 inverse();

		mat4 operator*(mat4 matrix);
		mat4 operator*(float scalar);
		friend mat4 operator*(float scalar, const mat4& matrix);
		friend mat4 operator*(int scalar, const mat4& matrix);
		mat4& operator=(mat4 matrix);
		bool operator==(mat4 matrix);
	};

}
