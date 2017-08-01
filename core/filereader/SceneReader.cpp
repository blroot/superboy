/*
 * SceneReader.cpp
 *
 *  Created on: Jul 30, 2017
 *      Author: blroot
 */

#include "SceneReader.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

namespace superboy {

	SceneReader::SceneReader(const char* filename) {

		this->filename = filename;
		this->ambient = color(0.2f, 0.2f, 0.2f);
	}

	Scene SceneReader::read() {

		Scene scene = Scene();

		ifstream infile;
		string line, command;

		infile.open(this->filename);

		if (infile.is_open()) {

			getline(infile, line);

			while (infile) {

				// Wipe blank and commented lines
				if ((line.find_first_not_of(" \t\r\n") != string::npos)
						&& (line[0] != '#')) {

					float values[10];
					bool valid_input;

					stringstream s(line);
					s >> command;

					if (command == "size") {

						valid_input = this->readvals(s, 2, values);

						if (valid_input) {

							scene.setResolution(values[0], values[1]);
							std::cout << "Setting resolution to: " << values[0] << "x" << values[1] << std::endl;
						}

					} else if (command == "camera") {

						valid_input = this->readvals(s, 10, values);

						if (valid_input) {

							vec3 eye = vec3(values[0], values[1], values[2]);
							vec3 center = vec3(values[3], values[4], values[5]);
							vec3 up = vec3(values[6], values[7], values[8]);

							Camera camera = Camera(eye, center, up, values[9]);

							scene.setCamera(camera);
							std::cout << "Setting camera coordinates: eye " << eye << " center " << center
									<< " up " << up << " fov: " << values[9] << std::endl;
						}

					} else if (command == "ambient") {

						valid_input = this->readvals(s, 3, values);

						if (valid_input) {

							color ambient = color(values[0], values[1], values[2]);
							this->ambient = ambient;
							std::cout << "Setting ambient to: " << ambient << std::endl;
						}

					} else if (command == "directional") {

						valid_input = this->readvals(s, 6, values);

						if (valid_input) {

							vec3 direction = vec3(values[0], values[1], values[2]);
							color colorvec = color(values[3], values[4], values[5]);

							std::shared_ptr<Directional> directional(new Directional(direction, colorvec));

							scene.addLight(directional);
							std::cout << "Adding directional light with: direction " << direction << " color "
									<< colorvec << std::endl;
						}

					} else if (command == "point") {

						valid_input = this->readvals(s, 6, values);

						if (valid_input) {

							vec3 position = vec3(values[0], values[1], values[2]);
							color colorvec = color(values[3], values[4], values[5]);

							std::shared_ptr<Point> point(new Point(position, colorvec));

							scene.addLight(point);
							std::cout << "Adding point light with: position " << position << " color "
									<< colorvec << std::endl;
						}

					} else if (command == "diffuse") {

						valid_input = this->readvals(s, 3, values);

						if (valid_input) {

							color diffuse = color(values[0], values[1], values[2]);
							this->diffuse = diffuse;
							std::cout << "Setting diffuse to: " << diffuse << std::endl;
						}

					} else if (command == "vertex") {

						valid_input = this->readvals(s, 3, values);

						if (valid_input) {

							vec3 vertex = vec3(values[0], values[1], values[2]);
							this->vertex_buffer.push_back(vertex);
							std::cout << "Adding vertex to buffer with coordinates: " << vertex << std::endl;
						}

					} else if (command == "tri") {

						valid_input = this->readvals(s, 3, values);

						if (valid_input) {

							std::shared_ptr<Triangle> triangle(new Triangle(vertex_buffer[values[0]], vertex_buffer[values[1]], vertex_buffer[values[2]]));

							triangle->getMaterials().setAmbient(this->ambient);
							triangle->getMaterials().setDiffuse(this->diffuse);
							scene.addObject(triangle);

							std::cout << "Adding triangle to scene with vertices: " << vertex_buffer[values[0]]
										<< " " << vertex_buffer[values[1]] << " " << vertex_buffer[values[2]] << std::endl;
							std::cout << "Setting triangle ambient to: " << this->ambient << std::endl;
							std::cout << "Setting triangle diffuse to: " << this->diffuse << std::endl;
						}

					} else if (command == "sphere") {

						valid_input = this->readvals(s, 4, values);

						if (valid_input) {

							vec3 center = vec3(values[0], values[1], values[2]);
							float radius = values[3];

							std::shared_ptr<Sphere> sphere(new Sphere(center, radius));

							sphere->getMaterials().setAmbient(this->ambient);
							sphere->getMaterials().setDiffuse(this->diffuse);
							scene.addObject(sphere);

							std::cout << "Adding sphere to scene with center: " << center << " radius: " << radius << std::endl;
							std::cout << "Setting sphere ambient to: " << this->ambient << std::endl;
							std::cout << "Setting sphere diffuse to: " << this->diffuse << std::endl;
						}

					}

				}
				// Get next line
				getline(infile, line);
			}

			return scene;
		} else {
			std::cout << "Error reading scene file" << std::endl;
		}
	}

	bool SceneReader::readvals(stringstream &s, const int numvals, float* values) {

	  for (int i = 0; i < numvals; i++) {
	    s >> values[i];

	    if (s.fail()) {
	      cout << "Failed reading value " << i << " will skip\n";
	      return false;
	    }
	  }
	  return true;
	}

	SceneReader::~SceneReader() {
		// TODO Auto-generated destructor stub
	}

} /* namespace superboy */
