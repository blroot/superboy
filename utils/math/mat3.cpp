/*
 * mat3.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: blroot
 */

#include "mat3.h"

namespace math {

	/*
	 * Note that matrix is in column order
	 */

	mat3::mat3() {

	}

	mat3::mat3(float diagonal) {
		elements[0] = diagonal;
		elements[4] = diagonal;
		elements[8] = diagonal;
	}

	mat3::mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
		elements[0] = a;
		elements[1] = d;
		elements[2] = g;
		elements[3] = b;
		elements[4] = e;
		elements[5] = h;
		elements[6] = c;
		elements[7] = f;
		elements[8] = i;
	}

	mat3 mat3::transpose(const mat3 &matrix) {
		return mat3(matrix.elements[0], matrix.elements[1], matrix.elements[2],
					matrix.elements[3], matrix.elements[4], matrix.elements[5],
					matrix.elements[6], matrix.elements[7], matrix.elements[8]);
	}

	mat3 operator*(mat3 left, mat3 right) {
		return mat3(left.elements[0]*right.elements[0] + left.elements[3]*right.elements[1] + left.elements[6]*right.elements[2],
					left.elements[0]*right.elements[3] + left.elements[3]*right.elements[4] + left.elements[6]*right.elements[5],
					left.elements[0]*right.elements[6] + left.elements[3]*right.elements[7] + left.elements[6]*right.elements[8],
					left.elements[1]*right.elements[0] + left.elements[4]*right.elements[1] + left.elements[7]*right.elements[2],
					left.elements[1]*right.elements[3] + left.elements[4]*right.elements[4] + left.elements[7]*right.elements[5],
					left.elements[1]*right.elements[6] + left.elements[4]*right.elements[7] + left.elements[7]*right.elements[8],
					left.elements[2]*right.elements[0] + left.elements[5]*right.elements[1] + left.elements[8]*right.elements[2],
					left.elements[2]*right.elements[3] + left.elements[5]*right.elements[4] + left.elements[8]*right.elements[5],
					left.elements[2]*right.elements[6] + left.elements[5]*right.elements[7] + left.elements[8]*right.elements[8]
					);
	}

}
