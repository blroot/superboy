/*
 * color.h

 *
 *  Created on: Jul 28, 2017
 *      Author: blroot
 */

#pragma once

namespace superboy {

	struct color {

		float x;
		float y;
		float z;

		color();
		color(float x, float y, float z);

		bool operator==(const color &vector);
		color operator+(color right);
		color& operator+=(color right);
		color operator-(color right);
		color operator*(float scalar);
		friend color operator*(float scalar, const color& vector);
		friend color operator*(int scalar, const color& vector);
		color normalize() const;
	};

}
