/*
 * Shader.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: blroot
 */

#include "Shader.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

namespace superboy {

	Shader::Shader(Scene& scene) {

		this->scene = &scene;
	}

	color Shader::computeColor(IntersectionInfo &intersection) {

		color colorvec = color();

		if (intersection.getHitObject() != NULL) {

			std::cout << "----------- Start Shading pixel -------------" << std::endl;

			colorvec += color(0.1f, 0.1f, 0.1f); // Ambient
			colorvec += intersection.getHitObject()->getMaterials().getEmission();

			for (int i = 0; i < this->scene->getLights().size(); i++) {

					vec3 light_direction = this->scene->getLights()[i]->getDirection();
					vec3 halfvec = (light_direction + scene->getCamera().eye).normalize();
					vec3 surface_normal = intersection.getNormal();
					color lightcolor = this->scene->getLights()[i]->getColor();
					color diffuse = intersection.getHitObject()->getMaterials().getDiffuse();
					color specular = intersection.getHitObject()->getMaterials().getSpecular();

					color diff_light = color(diffuse.x * lightcolor.x, diffuse.y * lightcolor.y, diffuse.z * lightcolor.z);
					color spec_light = color(specular.x * lightcolor.x, specular.y * lightcolor.y, specular.z * lightcolor.z);

					//std::cout << "diff_light: " << diff_light.x << " " << diff_light.y << " " << diff_light.z << std::endl;
					//std::cout << "spec_light: " << spec_light.x << " " << spec_light.y << " " << spec_light.z << std::endl;

					//std::cout << "light_direction: " << light_direction.x << " " << light_direction.y << " " << light_direction.z << std::endl;
					//std::cout << "surface_normal: " << surface_normal.x << " " << surface_normal.y << " " << surface_normal.z << std::endl;

					//color lambert = diff_light * std::max(surface_normal.dot(light_direction), 0.0f);

					Ray ray_to_light = Ray(intersection.getPoint()*1.001f, light_direction);

					color phong;
					color lambert;
					IntersectionInfo light_intersection = scene->intersect(ray_to_light);

					if (light_intersection.getHitObject() == NULL) {
						lambert = diff_light * std::max(surface_normal.dot(light_direction), 0.0f);
						phong = spec_light * pow(std::max(surface_normal.dot(halfvec), 0.0f), intersection.getHitObject()->getMaterials().getShininess());
					}
					//std::cout << "lambert: " << lambert.x << " " << lambert.y << " " << lambert.z << std::endl;
					//std::cout << "phong: " << phong.x << " " << phong.y << " " << phong.z << std::endl;

					colorvec += lambert + phong;
					//std::cout << "Color: " << colorvec.x << " " << colorvec.y << " " << colorvec.z << std::endl;
			}

			if (colorvec.x != 0.0f) {
				std::cout << "Final color: " << colorvec.normalize().x << " " << colorvec.normalize().y << " " << colorvec.normalize().z << std::endl;
			}

			std::cout << "----------- End Shading pixel -------------" << std::endl;
		}

		return colorvec.normalize();

	}

	Shader::~Shader() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
