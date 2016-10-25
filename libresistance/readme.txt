"libresistance" 

How to compile and execute test code and libresistance as shared library:

gcc -c -Wall -Werror -fpic libresistance.c
gcc -shared -o libresistance.so libresistance.o
gcc -Wall -o test test.c -lresistance
sudo cp libresistance.so /usr/lib
sudo chmod 0755 /usr/lib/libresistance.so
sudo ldconfig
./test
