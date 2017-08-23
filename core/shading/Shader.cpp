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

	color Shader::computeColor(IntersectionInfo &intersection, int recursion_depth) {

		if (recursion_depth <= 0) {
			return intersection.getHitObject()->getMaterials().getAmbient();
		}
		if (intersection.getHitObject() == nullptr) {
			return color(); // TODO: should be ambient
		}

		vec3 surface_normal = intersection.getNormal();
		vec3 hitpoint = intersection.getPoint();

		color colorvec = colorModel(intersection);

		// Reflection Ray
		if (intersection.getHitObject()->getMaterials().getSpecular() != color()) {
			vec3 mirror_vector = intersection.getRay()->getDirection() - 2*(intersection.getRay()->getDirection().dot(surface_normal))*surface_normal;
			Ray ray_from_mirror = Ray(hitpoint + surface_normal*1e-4, mirror_vector.normalize());
			IntersectionInfo mirror_intersection = scene->intersect(ray_from_mirror);

			if (mirror_intersection.getHitObject() != nullptr) {
				color specular = intersection.getHitObject()->getMaterials().getSpecular();
				color mirror_color = computeColor(mirror_intersection, recursion_depth-1);
				colorvec += color(specular.x * mirror_color.x, specular.y * mirror_color.y, specular.z * mirror_color.z);
			}
		}

		// Refraction Ray
		// TODO: Not needed atm

		return colorvec.normalize();

	}

	color Shader::colorModel(IntersectionInfo &intersection) {

		color diffuse = intersection.getHitObject()->getMaterials().getDiffuse();
		color specular = intersection.getHitObject()->getMaterials().getSpecular();
		vec3 surface_normal = intersection.getNormal();

		vec3 hitpoint = intersection.getPoint();

		// Ambient + Emission
		color colorvec = color();
		colorvec += intersection.getHitObject()->getMaterials().getAmbient();
		colorvec += intersection.getHitObject()->getMaterials().getEmission();


		for (int i = 0; i < this->scene->getLights().size(); i++) {

			vec3 light_direction = this->scene->getLights()[i]->getDirection(hitpoint);

			vec3 halfvec = (light_direction + -1*intersection.getRay()->getDirection()).normalize();
			float distance_to_light = this->scene->getLights()[i]->getDistance(hitpoint);
			float attenuation_model = this->scene->getLights()[i]->getAttenuation(hitpoint);

			color lightcolor = this->scene->getLights()[i]->getColor();

			// Shadow Ray
			Ray ray_to_light = Ray(hitpoint + surface_normal*1e-4, light_direction);
			bool is_in_shadow = scene->isInShadow(ray_to_light, distance_to_light);

			if (!is_in_shadow) {

				color diff_light = color(diffuse.x * lightcolor.x, diffuse.y * lightcolor.y, diffuse.z * lightcolor.z);
				color spec_light = color(specular.x * lightcolor.x, specular.y * lightcolor.y, specular.z * lightcolor.z);

				color lambert = diff_light * std::max<float>(surface_normal.normalize().dot(light_direction), 0.0f);
				color phong = spec_light * pow(std::max<float>(surface_normal.dot(halfvec), 0.0), (int)intersection.getHitObject()->getMaterials().getShininess());

				colorvec += attenuation_model * (lambert + phong);
			}

		}

		return colorvec;
	}

	Shader::~Shader() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */

