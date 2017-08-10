# Makefile
# Lorenz Gerber and Steve!
# Assignment 6 5DV088 HT16
# Makefile for electrotest
CC=gcc
CFLAGS= -Wall -std=c11 -pedantic -g

all: electrotest_local

install: electrotest

lib: power.so resistance.so component.so

electrotest_local: electrotest.o resistance.so power.so component.so
	mkdir ./lib
	mv resistance.so power.so component.so ./lib
	$(CC) $(CFLAGS) -o electrotest electrotest.o -L./lib -lresistance -lpower -lcomponent -Wl,-rpath,./lib

electrotest: electrotest.o resistance.so power.so libcomponent.so
	mv resistance.so power.so component.so /usr/lib
	$(CC) $(CFLAGS) -o electrotest electrotest.o -L/usr/lib -lresistance -lpower -lcomponent
	mv ./electrotest /usr/bin

electrotest.o: electrotest.c
	$(CC) $(CFLAGS) -c electrotest.c

component.so: component.o
	$(CC) $(CFLAGS) -shared -o component.so component.o -lm

resistance.so: resistance.o
	$(CC) $(CFLAGS) -shared -o resistance.so resistance.o

power.so: power.o
	$(CC) $(CFLAGS) -shared -o power.so power.o

component.o: component.c component.h
	$(CC) $(CFLAGS) -c -fPIC component.c

resistance.o: resistance.c resistance.h
	$(CC) $(CFLAGS) -c -fPIC resistance.c

power.o: power.c power.h
	$(CC) $(CFLAGS) -c -fPIC power.c

clean:
	rm -f rm *.o *.so
	rm -fr rm ./lib
	rm -f rm ./electrotest

uninstall:
	rm -f rm /usr/bin/electrotest
	rm -f rm /usr/lib/resistance.so
	rm -f rm /usr/lib/power.so
	rm -f rm /usr/lib/component.so
