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

		color colorvec = colorModel(intersection);

		vec3 surface_normal = intersection.getNormal();

		vec3 hitpoint = intersection.getPoint();

		// Reflection Ray
		if (intersection.getHitObject()->getMaterials().getSpecular() != color()) {
			vec3 mirror_vector = intersection.getRay()->getDirection() - 2*(intersection.getRay()->getDirection().dot(surface_normal))*surface_normal;
			Ray ray_from_mirror = Ray(hitpoint, mirror_vector);
			IntersectionInfo mirror_intersection = scene->intersect(ray_from_mirror);

			if (mirror_intersection.getHitObject() != nullptr) {
				colorvec += computeColor(mirror_intersection, recursion_depth-1);
			}
		}

		// Refraction Ray
		// TODO: Not needed atm

		return colorvec.normalize();

	}

	color Shader::colorModel(IntersectionInfo &intersection) {

		vec3 hitpoint = intersection.getPoint();

		color diffuse = intersection.getHitObject()->getMaterials().getDiffuse();
		color specular = intersection.getHitObject()->getMaterials().getSpecular();
		vec3 surface_normal = intersection.getNormal();

		// Ambient + Emission
		color colorvec = color();
		colorvec += intersection.getHitObject()->getMaterials().getAmbient();
		colorvec += intersection.getHitObject()->getMaterials().getEmission();

		for (int i = 0; i < this->scene->getLights().size(); i++) {

			vec3 light_direction = this->scene->getLights()[i]->getDirection(hitpoint);
			color lightcolor = this->scene->getLights()[i]->getColor();
			vec3 halfvec = (light_direction + scene->getCamera().eye).normalize();
			float distance_to_light = (light_direction - hitpoint).norm();
			vec3 attenuation = this->scene->getLights()[i]->getAttenuation();
			float attenuation_model = attenuation.x + attenuation.y*distance_to_light + attenuation.z*(distance_to_light*distance_to_light);

			// Shadow Ray
			Ray ray_to_light = Ray(hitpoint, light_direction);
			IntersectionInfo light_intersection = scene->intersect(ray_to_light);

			if (light_intersection.getHitObject() == nullptr) {

				color diff_light = color(diffuse.x * lightcolor.x, diffuse.y * lightcolor.y, diffuse.z * lightcolor.z);
				color spec_light = color(specular.x * lightcolor.x, specular.y * lightcolor.y, specular.z * lightcolor.z);

				color lambert = diff_light * std::max(surface_normal.normalize().dot(light_direction.normalize()), 0.0f);
				color phong = spec_light * pow(std::max(surface_normal.dot(halfvec), 0.0f), intersection.getHitObject()->getMaterials().getShininess());

				//colorvec += (1/attenuation_model) * (lambert + phong);
				colorvec += lambert + phong;
			}

		}

		return colorvec;
	}

	Shader::~Shader() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */

