#makefile for Lab6, Burleigh, HT16

CC = gcc #compilier
CFLAGS = -lm
OBJECTS = libcomponent.c libtest.c

program2: $(OBJECTS)
	$(CC) -o program2 $(OBJECTS) $(CFLAGS)

	
libcomponent.o: libcomponent.c
	$(CC) -c -Wall -fpic libcomponent.c
	
libcomponent.so: libcomponent.o
	$(CC) -shared -o libcomponent.so libcomponent.o
	
.PHONY: clean	

clean:
	rm -f *.o