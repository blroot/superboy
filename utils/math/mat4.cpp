/*
 * mat4.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: blroot
 */

#include "mat4.h"

namespace math {

	/*
	 * Note that matrix is in column order
	 */

	mat4::mat4() {

		for (int i = 0; i < 16; i++) {
			this->elements[i] = 0.0f;
		}
	}

	mat4::mat4(float diagonal) {

		for (int i = 0; i < 16; i++) {
			this->elements[i] = 0.0f;
		}

		elements[0] = diagonal;
		elements[5] = diagonal;
		elements[10] = diagonal;
		elements[15] = diagonal;
	}

	mat4::mat4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p) {

		elements[0] = a;
		elements[1] = e;
		elements[2] = i;
		elements[3] = m;
		elements[4] = b;
		elements[5] = f;
		elements[6] = j;
		elements[7] = n;
		elements[8] = c;
		elements[9] = g;
		elements[10] = k;
		elements[11] = o;
		elements[12] = d;
		elements[13] = h;
		elements[14] = l;
		elements[15] = p;
	}

	mat4 mat4::transpose() {

		return mat4(this->elements[0], this->elements[1], this->elements[2], this->elements[3],
					this->elements[4], this->elements[5], this->elements[6], this->elements[7],
					this->elements[8], this->elements[9], this->elements[10], this->elements[11],
					this->elements[12], this->elements[13], this->elements[14], this->elements[15]);
	}

	mat4 mat4::operator*(mat4 matrix) {

			return mat4(this->elements[0]*matrix.elements[0] + this->elements[4]*matrix.elements[1] + this->elements[8]*matrix.elements[2] + this->elements[12]*matrix.elements[3],
						this->elements[0]*matrix.elements[4] + this->elements[4]*matrix.elements[5] + this->elements[8]*matrix.elements[6] + this->elements[12]*matrix.elements[7],
						this->elements[0]*matrix.elements[8] + this->elements[4]*matrix.elements[9] + this->elements[8]*matrix.elements[10] + this->elements[12]*matrix.elements[11],
						this->elements[0]*matrix.elements[12] + this->elements[4]*matrix.elements[13] + this->elements[8]*matrix.elements[14] + this->elements[12]*matrix.elements[15],
						this->elements[1]*matrix.elements[0] + this->elements[5]*matrix.elements[1] + this->elements[9]*matrix.elements[2] + this->elements[13]*matrix.elements[3],
						this->elements[1]*matrix.elements[4] + this->elements[5]*matrix.elements[5] + this->elements[9]*matrix.elements[6] + this->elements[13]*matrix.elements[7],
						this->elements[1]*matrix.elements[8] + this->elements[5]*matrix.elements[9] + this->elements[9]*matrix.elements[10] + this->elements[13]*matrix.elements[11],
						this->elements[1]*matrix.elements[12] + this->elements[5]*matrix.elements[13] + this->elements[9]*matrix.elements[14] + this->elements[13]*matrix.elements[15],
						this->elements[2]*matrix.elements[0] + this->elements[6]*matrix.elements[1] + this->elements[10]*matrix.elements[2] + this->elements[14]*matrix.elements[3],
						this->elements[2]*matrix.elements[4] + this->elements[6]*matrix.elements[5] + this->elements[10]*matrix.elements[6] + this->elements[14]*matrix.elements[7],
						this->elements[2]*matrix.elements[8] + this->elements[6]*matrix.elements[9] + this->elements[10]*matrix.elements[10] + this->elements[14]*matrix.elements[11],
						this->elements[2]*matrix.elements[12] + this->elements[6]*matrix.elements[13] + this->elements[10]*matrix.elements[14] + this->elements[14]*matrix.elements[15],
						this->elements[3]*matrix.elements[0] + this->elements[7]*matrix.elements[1] + this->elements[11]*matrix.elements[2] + this->elements[15]*matrix.elements[3],
						this->elements[3]*matrix.elements[4] + this->elements[7]*matrix.elements[5] + this->elements[11]*matrix.elements[6] + this->elements[15]*matrix.elements[7],
						this->elements[3]*matrix.elements[8] + this->elements[7]*matrix.elements[9] + this->elements[11]*matrix.elements[10] + this->elements[15]*matrix.elements[11],
						this->elements[3]*matrix.elements[12] + this->elements[7]*matrix.elements[13] + this->elements[11]*matrix.elements[14] + this->elements[15]*matrix.elements[15]
						);
	}

	float mat4::determinant() {

		return (this->elements[0]*( this->elements[5]*this->elements[10]*this->elements[15]
									+ this->elements[6]*this->elements[11]*this->elements[13]
								    + this->elements[7]*this->elements[9]*this->elements[14]
								    - this->elements[13]*this->elements[10]*this->elements[7]
								    - this->elements[14]*this->elements[11]*this->elements[5]
									- this->elements[15]*this->elements[9]*this->elements[6])
				-this->elements[4]*( this->elements[1]*this->elements[10]*this->elements[15]
									+ this->elements[2]*this->elements[11]*this->elements[13]
									+ this->elements[3]*this->elements[9]*this->elements[14]
									- this->elements[13]*this->elements[10]*this->elements[3]
									- this->elements[14]*this->elements[11]*this->elements[1]
								    - this->elements[15]*this->elements[9]*this->elements[2])
				+this->elements[8]*( this->elements[1]*this->elements[6]*this->elements[15]
									+ this->elements[2]*this->elements[7]*this->elements[13]
									+ this->elements[3]*this->elements[5]*this->elements[14]
									- this->elements[13]*this->elements[6]*this->elements[3]
									- this->elements[14]*this->elements[7]*this->elements[1]
									- this->elements[15]*this->elements[5]*this->elements[2])
				-this->elements[12]*( this->elements[1]*this->elements[6]*this->elements[11]
									+ this->elements[2]*this->elements[7]*this->elements[9]
									+ this->elements[3]*this->elements[5]*this->elements[10]
									- this->elements[9]*this->elements[6]*this->elements[3]
									- this->elements[10]*this->elements[7]*this->elements[1]
									- this->elements[11]*this->elements[5]*this->elements[2])

		);
	}

	mat4 mat4::inverse() {

		mat4 cofactor = mat4();

		cofactor.elements[0] = (this->elements[5]*this->elements[10]*this->elements[15]
							    + this->elements[6]*this->elements[11]*this->elements[13]
							    + this->elements[7]*this->elements[9]*this->elements[14]
							    - this->elements[13]*this->elements[10]*this->elements[7]
							    - this->elements[14]*this->elements[11]*this->elements[5]
							    - this->elements[15]*this->elements[9]*this->elements[6]);

		cofactor.elements[1] = -(this->elements[4]*this->elements[10]*this->elements[15]
					            + this->elements[6]*this->elements[11]*this->elements[12]
								+ this->elements[7]*this->elements[8]*this->elements[14]
								- this->elements[12]*this->elements[10]*this->elements[7]
								- this->elements[14]*this->elements[11]*this->elements[4]
								- this->elements[15]*this->elements[8]*this->elements[6]);

		cofactor.elements[2] = (this->elements[4]*this->elements[9]*this->elements[15]
							    + this->elements[5]*this->elements[11]*this->elements[12]
							    + this->elements[7]*this->elements[8]*this->elements[13]
								- this->elements[12]*this->elements[9]*this->elements[7]
								- this->elements[13]*this->elements[11]*this->elements[4]
								- this->elements[15]*this->elements[8]*this->elements[5]);

		cofactor.elements[3] = -(this->elements[4]*this->elements[9]*this->elements[14]
							    + this->elements[5]*this->elements[10]*this->elements[12]
								+ this->elements[6]*this->elements[8]*this->elements[13]
								- this->elements[12]*this->elements[9]*this->elements[6]
								- this->elements[13]*this->elements[10]*this->elements[4]
								- this->elements[14]*this->elements[8]*this->elements[5]);

		cofactor.elements[4] = -(this->elements[1]*this->elements[10]*this->elements[15]
							    + this->elements[2]*this->elements[11]*this->elements[13]
								+ this->elements[3]*this->elements[9]*this->elements[14]
								- this->elements[13]*this->elements[10]*this->elements[3]
								- this->elements[14]*this->elements[11]*this->elements[1]
								- this->elements[15]*this->elements[9]*this->elements[2]);

		cofactor.elements[5] = (this->elements[0]*this->elements[10]*this->elements[15]
							    + this->elements[2]*this->elements[11]*this->elements[12]
								+ this->elements[3]*this->elements[8]*this->elements[14]
								- this->elements[12]*this->elements[10]*this->elements[3]
								- this->elements[14]*this->elements[11]*this->elements[0]
								- this->elements[15]*this->elements[8]*this->elements[2]);

		cofactor.elements[6] = -(this->elements[0]*this->elements[9]*this->elements[15]
							    + this->elements[1]*this->elements[11]*this->elements[12]
								+ this->elements[3]*this->elements[8]*this->elements[13]
								- this->elements[12]*this->elements[9]*this->elements[3]
								- this->elements[13]*this->elements[11]*this->elements[0]
								- this->elements[15]*this->elements[8]*this->elements[1]);

		cofactor.elements[7] = (this->elements[0]*this->elements[9]*this->elements[14]
							    + this->elements[1]*this->elements[10]*this->elements[12]
								+ this->elements[2]*this->elements[8]*this->elements[13]
								- this->elements[12]*this->elements[9]*this->elements[2]
								- this->elements[13]*this->elements[10]*this->elements[0]
								- this->elements[14]*this->elements[8]*this->elements[1]);

		cofactor.elements[8] = (this->elements[1]*this->elements[6]*this->elements[15]
							    + this->elements[2]*this->elements[7]*this->elements[13]
								+ this->elements[3]*this->elements[5]*this->elements[14]
								- this->elements[13]*this->elements[6]*this->elements[3]
								- this->elements[14]*this->elements[7]*this->elements[1]
								- this->elements[15]*this->elements[5]*this->elements[2]);

		cofactor.elements[9] = -(this->elements[0]*this->elements[6]*this->elements[15]
							     + this->elements[2]*this->elements[7]*this->elements[12]
								 + this->elements[3]*this->elements[4]*this->elements[14]
								 - this->elements[12]*this->elements[6]*this->elements[3]
								 - this->elements[14]*this->elements[7]*this->elements[0]
								 - this->elements[15]*this->elements[4]*this->elements[2]);

		cofactor.elements[10] = (this->elements[0]*this->elements[5]*this->elements[15]
							     + this->elements[1]*this->elements[7]*this->elements[12]
								 + this->elements[3]*this->elements[4]*this->elements[13]
								 - this->elements[12]*this->elements[5]*this->elements[3]
								 - this->elements[13]*this->elements[7]*this->elements[0]
								 - this->elements[15]*this->elements[4]*this->elements[1]);

		cofactor.elements[11] = -(this->elements[0]*this->elements[5]*this->elements[14]
							      + this->elements[1]*this->elements[6]*this->elements[12]
								  + this->elements[2]*this->elements[4]*this->elements[13]
								  - this->elements[12]*this->elements[5]*this->elements[2]
								  - this->elements[13]*this->elements[6]*this->elements[0]
								  - this->elements[14]*this->elements[4]*this->elements[1]);

		cofactor.elements[12] = -(this->elements[1]*this->elements[6]*this->elements[11]
							    + this->elements[2]*this->elements[7]*this->elements[9]
								+ this->elements[3]*this->elements[5]*this->elements[10]
								- this->elements[9]*this->elements[6]*this->elements[3]
								- this->elements[10]*this->elements[7]*this->elements[1]
								- this->elements[11]*this->elements[5]*this->elements[2]);

		cofactor.elements[13] = (this->elements[0]*this->elements[6]*this->elements[11]
							     + this->elements[2]*this->elements[7]*this->elements[8]
								 + this->elements[3]*this->elements[4]*this->elements[10]
								 - this->elements[8]*this->elements[6]*this->elements[3]
								 - this->elements[10]*this->elements[7]*this->elements[0]
								 - this->elements[11]*this->elements[4]*this->elements[2]);

		cofactor.elements[14] = -(this->elements[0]*this->elements[5]*this->elements[11]
							    + this->elements[1]*this->elements[7]*this->elements[8]
								+ this->elements[3]*this->elements[4]*this->elements[9]
								- this->elements[8]*this->elements[5]*this->elements[3]
								- this->elements[9]*this->elements[7]*this->elements[0]
								- this->elements[11]*this->elements[4]*this->elements[1]);

		cofactor.elements[15] = (this->elements[0]*this->elements[5]*this->elements[10]
							     + this->elements[1]*this->elements[6]*this->elements[8]
								 + this->elements[2]*this->elements[4]*this->elements[9]
								 - this->elements[8]*this->elements[5]*this->elements[2]
						         - this->elements[9]*this->elements[6]*this->elements[0]
								 - this->elements[10]*this->elements[4]*this->elements[1]);

		return 1/this->determinant()*cofactor.transpose();
	}

	mat4 operator*(int scalar, const mat4& matrix) {

		mat4 resulting_matrix = mat4();

		for (int i = 0; i < 16; i++) {
			resulting_matrix.elements[i] = scalar*matrix.elements[i];
		}

		return resulting_matrix;
	}

	mat4 operator*(float scalar, const mat4& matrix) {

		mat4 resulting_matrix = mat4();

		for (int i = 0; i < 16; i++) {
			resulting_matrix.elements[i] = scalar*matrix.elements[i];
		}

		return resulting_matrix;
	}

	mat4& mat4::operator=(mat4 matrix) {

		for (int i = 0; i < 16; i++)  {
			this->elements[i] = matrix.elements[i];
		}
	}

}
