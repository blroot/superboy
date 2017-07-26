CC = g++

CFLAGS = 
INCFLAGS = 
LDFLAGS = -lfreeimage

RM = /bin/rm -f 

all:superboy
tests:tests

superboy: build/vec3.o build/mat4.o build/superboy.o build/Image.o build/Camera.o build/Ray.o build/Sphere.o build/Scene.o build/IntersectionInfo.o build/Object.o build/Triangle.o
	$(CC) $(CFLAGS) -o superboy build/vec3.o build/mat4.o build/superboy.o build/Image.o build/Camera.o build/Ray.o build/Sphere.o build/Scene.o build/IntersectionInfo.o build/Object.o build/Triangle.o $(INCFLAGS) $(LDFLAGS)
tests: build/mat3.o build/vec3.o build/mat4.o utils/math/tests.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread
	$(CC) $(CFLAGS) -o tests build/mat3.o build/vec3.o build/mat4.o utils/math/tests.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread $(INCFLAGS) $(LDFLAGS)
build/mat3.o: utils/math/mat3.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/mat3.cpp -o build/mat3.o
build/mat4.o: utils/math/mat4.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/mat4.cpp -o build/mat4.o
build/vec3.o: utils/math/vec3.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/vec3.cpp -o build/vec3.o
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
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/scene/Scene.cpp -o build/Scene.o
build/IntersectionInfo.o: core/scene/IntersectionInfo.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/scene/IntersectionInfo.cpp -o build/IntersectionInfo.o
build/Object.o: core/object/Object.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/object/Object.cpp -o build/Object.o
build/superboy.o:
	$(CC) $(CFLAGS) $(INCFLAGS) -c core/superboy.cpp -o build/superboy.o
clean: 
	$(RM) build/*.o 
	$(RM) superboy 
