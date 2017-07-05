CC = g++

CFLAGS = 
INCFLAGS = 
LDFLAGS = 

RM = /bin/rm -f 

math.o: utils/math/vec3.cpp utils/math/vec3.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/vec3.cpp
clean: 
	$(RM) *.o 
