CC = g++ -std=c++11

CFLAGS = 
INCFLAGS = -fopenmp
LDFLAGS = -lfreeimage

RM = /bin/rm -fr 

all:superboy
tests:tests

superboy: mkbuild build/vec3.o build/vec4.o build/mat4.o build/superboy.o build/color.o build/Image.o build/Camera.o build/Ray.o build/Sphere.o build/Scene.o build/IntersectionInfo.o build/Object.o build/Triangle.o build/Light.o build/Directional.o build/Point.o build/Materials.o build/Shader.o build/SceneReader.o
	$(CC) $(CFLAGS)-o superboy build/vec3.o build/vec4.o build/mat4.o build/color.o build/superboy.o build/Image.o build/Camera.o build/Ray.o build/Sphere.o build/Scene.o build/IntersectionInfo.o build/Object.o build/Triangle.o build/Light.o build/Directional.o build/Point.o build/Materials.o build/Shader.o build/SceneReader.o $(INCFLAGS) $(LDFLAGS)
tests: build/mat3.o build/vec3.o build/vec4.o build/mat4.o utils/math/tests.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread
	$(CC) $(CFLAGS) -o tests build/mat3.o build/vec3.o build/vec4.o build/mat4.o utils/math/tests.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread $(INCFLAGS) $(LDFLAGS)
build/mat3.o: utils/math/mat3.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/mat3.cpp -o build/mat3.o
build/mat4.o: utils/math/mat4.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/mat4.cpp -o build/mat4.o
build/vec3.o: utils/math/vec3.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/vec3.cpp -o build/vec3.o
build/vec4.o: utils/math/vec4.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/vec4.cpp -o build/vec4.o
build/color.o: core/color/color.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/color/color.cpp -o build/color.o
build/Image.o: core/Image.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/Image.cpp -o build/Image.o
build/Camera.o: core/camera/Camera.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/camera/Camera.cpp -o build/Camera.o
build/Ray.o: core/camera/Ray.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/camera/Ray.cpp -o build/Ray.o
build/Sphere.o: core/primitives/Sphere.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/primitives/Sphere.cpp -o build/Sphere.o
build/Triangle.o: core/primitives/Triangle.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/primitives/Triangle.cpp -o build/Triangle.o
build/Scene.o: core/scene/Scene.h
	$(CC) $(CFLAGS) $(INCFLAGS) -g -c core/scene/Scene.cpp -o build/Scene.o
build/IntersectionInfo.o: core/scene/IntersectionInfo.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/scene/IntersectionInfo.cpp -o build/IntersectionInfo.o
build/Object.o: core/object/Object.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/object/Object.cpp -o build/Object.o
build/Materials.o: core/object/materials/Materials.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/object/materials/Materials.cpp -o build/Materials.o
build/Light.o: core/light/Light.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/light/Light.cpp -o build/Light.o
build/Directional.o: core/light/Directional.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/light/Directional.cpp -o build/Directional.o
build/Point.o: core/light/Point.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/light/Point.cpp -o build/Point.o
build/Shader.o: core/shading/Shader.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/shading/Shader.cpp -o build/Shader.o
build/SceneReader.o: core/filereader/SceneReader.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/filereader/SceneReader.cpp -o build/SceneReader.o
build/superboy.o core/superboy.h:
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/superboy.cpp -o build/superboy.o
mkbuild:
	mkdir build/
clean: 
	$(RM) build/ 
	$(RM) superboy 
