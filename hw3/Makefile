# Makefile:


CFLAGS = -Wall -ansi -std=c99


PhotoLab: Constants.h FileIO.o DIPs.o Advanced.o PhotoLab.o
	gcc $(CFLAGS) -g -DNDEBUG FileIO.o DIPs.o Advanced.o PhotoLab.o -lm  -o PhotoLab

PhotoLabTest: Constants.h FileIO.o DIPs.o Advanced.o PhotoLabTest.o
	gcc $(CFLAGS) -g -DNDEBUG FileIO.o DIPs.o Advanced.o PhotoLab.o -lm  -o PhotoLabTest

FileIO.o: FileIO.c FileIO.h Constants.h
	gcc -c $(CFLAGS) FileIO.c -o FileIO.o

DIPs.o: DIPs.c DIPs.h Constants.h
	gcc -c $(CFLAGS) DIPs.c -lm -o DIPs.o

Advanced.o: Advanced.c Advanced.h Constants.h
	gcc -c $(CFLAGS) Advanced.c -o Advanced.o

PhotoLab.o: PhotoLab.c FileIO.h DIPs.h Advanced.h Constants.h
	gcc -c $(CFLAGS) -g -DNDEBUG PhotoLab.c -lm  -o PhotoLab.o

PhotoLabTest.o: PhotoLab.c FileIO.h DIPs.h Advanced.h Constants.h
	gcc -c $(CFLAGS) -g -DDEBUG PhotoLab.c -lm  -o PhotoLab.o

clean:
	rm *.o
	rm PhotoLab
	rm PhotoLabTest
	rm bw.ppm
	rm sharpen.ppm
	rm hue.ppm
	rm noise.ppm
	rm posterize.ppm

