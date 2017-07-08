CC = g++

CFLAGS = 
INCFLAGS = 
LDFLAGS = 

RM = /bin/rm -f 

tests:tests

tests: mat3.o vec3.o mat4.o utils/math/mat3.h utils/math/vec3.h utils/math/mat4.h utils/math/tests.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread
	$(CC) $(CFLAGS) -o tests mat3.o vec3.o mat4.o utils/math/mat3.h utils/math/mat4.h utils/math/vec3.h utils/math/tests.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread$(INCFLAGS) $(LDFLAGS)
mat3.o: utils/math/mat3.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/mat3.cpp
mat4.o: utils/math/mat4.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/mat4.cpp
vec3.o: utils/math/vec3.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/vec3.cpp
clean: 
	$(RM) *.o 
