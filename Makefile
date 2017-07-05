CC = g++

CFLAGS = 
INCFLAGS = 
LDFLAGS = 

RM = /bin/rm -f 

math.o: utils/math/*.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c utils/math/*.cpp
clean: 
	$(RM) *.o 
