/*
 * sphere.h
 *
 *  Created on: Jul 19, 2017
 *      Author: blroot
 */

#pragma once

namespace superboy {

	class sphere {
		public:
			float center;
			float radius;

			sphere();
			virtual ~sphere();
			bool intersect();
	};

} /* namespace superboy */
