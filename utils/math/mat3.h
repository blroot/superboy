/*
 * mat3.h
 *
 *  Created on: Jul 5, 2017
 *      Author: blroot
 */

namespace math {

	struct mat3 {

		float elements[9];

		mat3();
		mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
		mat3(float diagonal);

		mat3 transpose(const mat3 &matrix);
		mat3 inverse(const mat3 &matrix);
	};

}


