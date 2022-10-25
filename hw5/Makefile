#######################################################################
# Homework Assignment 5, for EECS 22, Winter 2020
#
#
# Makefile: Makefile for HW 5
#
#######################################################################

# Variables
FLAGS = -ansi -std=c99 -Wall -g

# Default target
all: MovieLab

######################### Generate object files #######################
# Target for FileIO.o
FileIO.o: FileIO.h FileIO.c Image.h
	gcc -c FileIO.c -o FileIO.o $(FLAGS)
# Target for DIPs.o
DIPs.o: DIPs.h DIPs.c Image.h
	gcc -c DIPs.c -o DIPs.o $(FLAGS)
# Target for Image.o

Image.o: Image.h Image.c
	gcc -c Image.c -o Image.o $(FLAGS)
	
# Target for other object files
ImageList.o: ImageList.h Image.h
	gcc -c ImageList.c -o ImageList.o $(FLAGS)

IterativeFilter.o: IterativeFilter.h Movie.h Image.h
	gcc -c IterativeFilter.c -o IterativeFilter.o $(FLAGS)

Movie.o: Movie.h ImageList.h
	gcc -c Movie.c -o Movie.o $(FLAGS)

MovieIO.o: MovieIO.h FileIO.h Movie.h
	gcc -c MovieIO.c -o MovieIO.o $(FLAGS)

MovieLab.o: IterativeFilter.h MovieIO.h Image.h Constants.h Movie.h DIPs.h FileIO.h
	gcc -c MovieLab.c -o MovieLab.o $(FLAGS)

######################### Generate the executable #####################
# Target for MovieLab

MovieLab: MovieLab.o MovieIO.o IterativeFilter.o ImageList.o Image.o DIPs.o FileIO.o
	gcc $(FLAGS) MovieLab.o -o MovieLab -lm

###############################  others  ##############################
# Target for clean
clean:
	rm -f *.o *.jpg *.yuv
