# superboy

An non-realtime ray tracing rendering engine for linux featuring:
- Tranformations: translate, scale, rotate
- Lights: point and directional, quadratic attenuation model (only for point)
- Recursive mirror reflections
- Shadows
- Basic primitives: Spheres and Triangles
- Blinn-Phong shading model
- Scene file parsing
- Multithreading

## Usage
`./superboy <scene_file>`

Scene files are just text files with the following procedural commands:

The basics

`size width height` image width and height (will respect aspect ratio)

`output file_name.png` image name

`camera 0 -4 4 0 -1 0 0 1 1 45` creates the camera with eye center up and fov arguments

`maxdepth 5` specify a maximum recursion depth for the scene 

Need some light?

`point 1 1 3 1 1 1` creates a physical point light with center and color arguments

`directional 1 1 3 1 1 1`creates a directional light with direction and color arguments

`attenuation 1 0.1 0.05` set attenuation terms (constant, linear and quadratic)

Transforming objects

`pushTransform` pushes the current transformation into the stack (nice for hierarchical drawing)

`translate  0 0 0.5` translation

`scale 2 1 .25` non uniform scaling

`rotate 0 0 1 45` rotation from axis and angle

`popTransform` removes the current top tranformation from the stack (nice for hierarchical drawing)

Defining the object material (These can be changed per object)

`ambient 0 0 0` ambient term color

`diffuse 0 1 0` diffuse term color

`specular 0 0 0` specular term color

`shininess 100` shininess exponential factor (Phong shading)

`emission 0 0 0` self emmisive term color

Now... how to create objects?

`sphere 0 0 0 1` creates a sphere with center and radius

`vertex 0 0 0` creates a vertex with the specified coordinates

`tri 0 1 2` creates a triangle from three vertices (vertices index is vertex creation order)


Features are pretty basic for the time being, in a near future i'll eventually be adding:
- Trinormals
- Refractive surfaces
- More primitives: Boxes, cilinders?, etc.
- Acceleration structures
- Other shading models
- Antialiasing, Depth of field, blur motion
- Obj file reader

## building the project
This project is known to compile and work under Ubuntu 16.04 under gcc version 5.4.0, but should work under any distro and gcc version with c++11 support

Prerequisites: freeimage

To build just run make

`make`

## running the tests (for math own library)
Yo will need the Google test library installed
https://github.com/google/googletest
