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

		recursiveShading(intersection, intersection.getHitObject()->getMaterials().getSpecular(), colorvec, 5, primary);

		return colorvec.normalize();

	}

	void Shader::recursiveShading(IntersectionInfo &intersection, color& reflectivity, color &colorvec, int recursion_depth, RayType ray_type) {

		if (recursion_depth >= 0) {

			if (intersection.getMinimumDistance() != INFINITY) {

				//std::cout << "----------- Start Shading pixel -------------" << std::endl;

				// If ray is from camera apply shading model
				if (ray_type == primary) {
					colorvec += intersection.getHitObject()->getMaterials().getAmbient();
					colorvec += intersection.getHitObject()->getMaterials().getEmission();
				}

				for (int i = 0; i < this->scene->getLights().size(); i++) {

					color phong;
					color lambert;
					float attenuation_model;

					vec3 hitpoint = intersection.getRay()->getPoint(intersection.getMinimumDistance());
					vec3 light_direction = this->scene->getLights()[i]->getDirection(hitpoint);
					vec3 halfvec = (light_direction + scene->getCamera().eye).normalize();
					vec3 surface_normal = intersection.getNormal();
					color lightcolor = this->scene->getLights()[i]->getColor();
					vec3 attenuation = this->scene->getLights()[i]->getAttenuation();
					color diffuse = intersection.getHitObject()->getMaterials().getDiffuse();
					color specular = intersection.getHitObject()->getMaterials().getSpecular();
					float distance_to_light = (light_direction - hitpoint).norm();

					color diff_light = color(diffuse.x * lightcolor.x, diffuse.y * lightcolor.y, diffuse.z * lightcolor.z);
					color spec_light = color(specular.x * lightcolor.x, specular.y * lightcolor.y, specular.z * lightcolor.z);

					Ray ray_to_light = Ray(hitpoint, light_direction);

					IntersectionInfo light_intersection = scene->intersect(ray_to_light);

					// Trace a ray from hit point to light source -> if no intersection -> compute shading
					if (light_intersection.getHitObject() == NULL) {
						lambert = diff_light * std::max(surface_normal.normalize().dot(light_direction.normalize()), 0.0f);
						phong = spec_light * pow(std::max(surface_normal.dot(halfvec), 0.0f), intersection.getHitObject()->getMaterials().getShininess());
						attenuation_model = attenuation.x + attenuation.y*distance_to_light + attenuation.z*(distance_to_light*distance_to_light);
						color lambert_phong = lambert + phong;
						//std::cout << "Light Direction: " << light_direction.x << " " << light_direction.y << " " << light_direction.z << std::endl;
						//std::cout << "NdotL: " << surface_normal.dot(light_direction) << std::endl;
						//std::cout << "Phong: " << phong.x << " " << phong.y << " " << phong.z << std::endl;
						//std::cout << "Lambert: " << lambert.x << " " << lambert.y << " " << lambert.z << std::endl;
						//std::cout << "Lambert + Phong: " << lambert_phong.x << " " << lambert_phong.y << " " << lambert_phong.z << std::endl;
					}

					// If ray is from camera apply shading model
					if (ray_type == primary) {
						//colorvec += 1/attenuation_model * (lambert + phong);
						colorvec += 1/attenuation_model * (lambert + phong);
						//std::cout << "Attenuated: " << colorvec.x << " " << colorvec.y << " " << colorvec.z << std::endl;
					}

					// If ray is secondary add color from reflection
					if (ray_type == secondary) {
						//color lambert_phong = intersection.getHitObject()->getMaterials().getAmbient() + intersection.getHitObject()->getMaterials().getEmission() + lambert + phong;
						color lambert_phong = intersection.getHitObject()->getMaterials().getAmbient() + intersection.getHitObject()->getMaterials().getEmission() + lambert + phong;

						colorvec += color(reflectivity.x*lambert_phong.x, reflectivity.y*lambert_phong.y, reflectivity.z*lambert_phong.z);
					}

					// Trace a mirror ray to compute reflections
					vec3 mirror_vector = intersection.getRay()->getDirection() - 2*(intersection.getRay()->getDirection().dot(surface_normal))*surface_normal;
					Ray ray_from_mirror = Ray(hitpoint, mirror_vector);
					IntersectionInfo mirror_intersection = scene->intersect(ray_from_mirror);

					if (mirror_intersection.getMinimumDistance() != INFINITY) {

						recursiveShading(mirror_intersection, reflectivity, colorvec, recursion_depth-1, secondary);
					}

				}

			}
		}
	}

	Shader::~Shader() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
