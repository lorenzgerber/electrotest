# Makefile
# Lorenz Gerber
# Assignment 6 5DV088 HT16
# Makefile for electrotest
CC=gcc
CFLAGS= -Wall -pedantic -std=c11

all: electrotest_local

install: electrotest

lib: libpower.so libresistance.so

electrotest_local: electrotest.o libresistance.so libpower.so
	mkdir ./lib
	mv libresistance.so libpower.so ./lib
	$(CC) $(CFLAGS) -o electrotest electrotest.o -L./lib -lresistance -lpower -Wl,-rpath,./lib

electrotest: electrotest.o libresistance.so libpower.so
	mv libresistance.so libpower.so /usr/lib
	$(CC) $(CFLAGS) -o electrotest electrotest.o -L/usr/lib -lresistance -lpower
	mv ./electrotest /usr/bin

electrotest.o: electrotest.c
	$(CC) $(CFLAGS) -c electrotest.c

libresistance.so: libresistance.o
	$(CC) $(CFLAGS) -shared -o libresistance.so libresistance.o

libpower.so: libpower.o
	$(CC) $(CFLAGS) -shared -o libpower.so libpower.o

libresistance.o: libresistance.c libresistance.h
	$(CC) $(CFLAGS) -c -fPIC libresistance.c

libpower.o: libpower.c libpower.h
	$(CC) $(CFLAGS) -c -fPIC libpower.c

clean:
	 rm -f rm *.o

uninstall:
	rm -f rm /usr/bin/electrotest
	rm -f rm /usr/lib/libresistance.so
	rm -f rm /usr/lib/libpower.so
	rm -fr rm ./lib
	rm -f rm ./electrotest
