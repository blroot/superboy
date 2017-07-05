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

		float dot(vec3 left, vec3 right);
		vec3 cross(vec3 vector);
	};

}
