# Makefile
# Lorenz Gerber and Steve!
# Assignment 6 5DV088 HT16
# Makefile for electrotest
CC=gcc
CFLAGS= -Wall -pedantic

all: electrotest_local

install: electrotest

lib: libpower.so libresistance.so libcomponent.so

electrotest_local: electrotest.o libresistance.so libpower.so libcomponent.so
	sudo mkdir ./lib
	sudo mv libresistance.so libpower.so libcomponent.so ./lib
	$(CC) $(CFLAGS) -o electrotest electrotest.o -L./lib -lresistance -lpower -lcomponent -Wl,-rpath,./lib

electrotest: electrotest.o libresistance.so libpower.so libcomponent.so
	sudo mv libresistance.so libpower.so libcomponent.so /usr/lib
	$(CC) $(CFLAGS) -o electrotest electrotest.o -L/usr/lib -lresistance -lpower -lcomponent
	sudo mv ./electrotest /usr/bin

electrotest.o: electrotest.c
	$(CC) $(CFLAGS) -c electrotest.c

libcomponent.so: libcomponent.o
	$(CC) $(CFLAGS) -shared -o libcomponent.so libcomponent.o -lm

libresistance.so: libresistance.o
	$(CC) $(CFLAGS) -shared -o libresistance.so libresistance.o

libpower.so: libpower.o
	$(CC) $(CFLAGS) -shared -o libpower.so libpower.o

libcomponent.o: libcomponent.c libcomponent.h
	$(CC) $(CFLAGS) -c -fPIC libcomponent.c

libresistance.o: libresistance.c libresistance.h
	$(CC) $(CFLAGS) -c -fPIC libresistance.c

libpower.o: libpower.c libpower.h
	$(CC) $(CFLAGS) -c -fPIC libpower.c

clean:
	 sudo rm -f rm *.o

uninstall:
	sudo rm -f rm /usr/bin/electrotest
	sudo rm -f rm /usr/lib/libresistance.so
	sudo rm -f rm /usr/lib/libpower.so
	sudo rm -f rm /usr/lib/libcomponent.so
	sudo rm -fr rm ./lib
	sudo rm -f rm ./electrotest
	sudo rm -f rm ./libcomponent.so ./libresistance.so ./libpower.so
	#sudo rm -f rm ./*.o
