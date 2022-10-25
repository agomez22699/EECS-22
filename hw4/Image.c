/* Image.c : Handles basic operations on the image */

#include "Image.h"
#include "Constants.h"

#include <stdio.h>
/* Get the R intensity of pixel (x, y) in image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x,  unsigned int y);

/* Get the G intensity of pixel (x, y) in image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x,  unsigned int y);

/* Get the B intensity of pixel (x, y) in image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x,  unsigned int y);

/* Set the R intensity of pixel (x, y) in image to r */
void SetPixelR(IMAGE *image, unsigned int x,  unsigned int y, unsigned char r);

/* Set the G intensity of pixel (x, y) in image to g */
void SetPixelG(IMAGE *image, unsigned int x,  unsigned int y, unsigned char g);

/* Set the B intensity of pixel (x, y) in image to b */
void SetPixelB(IMAGE *image, unsigned int x,  unsigned int y, unsigned char b);

/* Allocate dynamic memory for the image structure and its R/G/B values */
/* Return the pointer to the image, or NULL in case of error */
IMAGE *CreateImage(unsigned int Width, unsigned int Height){

	int allocSize = 0;
	allocSize = 6 * sizeof(int) * Width * Height; // The SetPixel and GetPixel allocation
	allocSize += 2 * sizeof(int);

	IMAGE *image = malloc(allocSize);

	if (image == NULL){
		printf("\nCouldn't allocate memory\n");
		exit(532);
				}
	
								}
/* Free the memory for the R/G/B values and IMAGE structure */
void DeleteImage(IMAGE *image){
	free(image);
				}

/* Return the image's width in pixels */
unsigned int ImageWidth(const IMAGE *image){
	image->W = W;
	return image; 
						}

/* Return the image's height in pixels */
unsigned int ImageHeight(const IMAGE *image){
	image->H = H;
	return image;
						}


