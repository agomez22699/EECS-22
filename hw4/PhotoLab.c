/*********************************************************************/
/* PhotoLab.c: homework assignment #3, for EECS 22,  Fall 2017       */
/*                                                                   */
/* Author: Mina Moghadam                                                */
/* Date:   11/8/2017                                                */
/*                                                                   */
/* Comments: */
/*                                                                   */
/* Please use this template to submit your hw3.                      */
/*********************************************************************/

#include <stdio.h>
#include <string.h>

#include "DIPs.h"
#include "Advanced.h"
#include "FileIO.h"
#include "Constants.h"
#include "Test.h"
#include "Image.h"

/*** function declarations ***/

/* print a menu */
void PrintMenu();

int main()
{

#ifdef DEBUG
    AutoTest();
#else
    int rc;

    int enlargeT; //enlarge register
    int Xoff; //x offset
    int Yoff; //y offset
    int Squaresize; //square size
    int briT; // brightness
    int conT; //contrast

    int option;            /* user input option */
    char fname[SLEN];        /* input file name */

    rc = 1;
    PrintMenu();
    scanf("%d", &option);

    /* Hue() parameter */
    int hue;

    /* Posterize() parameter */
    unsigned char rbits, gbits, bbits;

    /* Noise() parameter */
    int n;

    /* MotionBlur() parameter */
    int blur_amount;


    while (option != EXIT) {
        if (option == 1) {
            printf("Please input the file name to load: ");
            scanf("%s", fname);
            rc = LoadImage(fname, image);
        }

        /* menu item 2 - 14 requires image is loaded first */
	// changed for homework 4
        else if (option >= 2 && option < 11) {
            if (rc != SUCCESS)     {
                printf("No image to process!\n");
            }
            /* now image is loaded */
            else {
                switch (option) {
                    case 2:
                        printf("Please input the file name to save: ");
                        scanf("%s", fname);
                        SaveImage(fname, IMAGE *image);
                        break;
                    case 3:
                        image = BlackNWhite(IMAGE *image);
                        printf("\"Black amd White\" operation is done!\n");
                        break;
                    case 4:
                        image = Sharpen(IMAGE *image);
                        printf("\"Sharpen\" operation is done!\n");
                        break;
                    case 5:
                        printf("Please input the degree of changing hue: ");
                        scanf("%d", &hue);
                        image = Hue(IMAGE *image, hue);
                        printf("\"Hue\" operatin is done!\n");
                    case 6:
                        printf("Please input noise percentage: ");
                        scanf("%d", &n);
                        image = Noise(n,IMAGE *image);
                        printf("\"Noise\" operation is done!\n");
                        break;
                    case 7:
                        printf("Enter the number of posterization bits for R chennel (1 to 8):");
                        scanf("%hhu", &rbits);
                        printf("Enter the number of posterization bits for G chennel (1 to 8):");
                        scanf("%hhu", &gbits);
                        printf("Enter the number of posterization bits for B chennel (1 to 8):");
                        scanf("%hhu", &bbits);
                        image = Posterize(IMAGE *image , rbits, gbits, bbits);
                        printf("\"Posterize\" operation is done!\n");
                        break;
                    case 8:
                        printf("Please input motion blur amount: ");
                        scanf("%d", &blur_amount);
                        image = MotionBlur(blur_amount, IMAGE  *image);
                        printf("\"Motion Blur\" operation is done!\n");
                        break;
		    case 9:
			printf("Please input the enlarging percentage (integer between 100 - 200):");
			scanf("%d", &enlargeT);
			image = Enlarge(IMAGE *image, enlargeT);
			printf("\"Enlarge\" operation is done!\n");
			break;
		    case 10:
			printf("Please enter the X offset value:");
			scanf("%d", &Xoff);
			printf("Please enter the Y offset value:");
			scanf("%d", &Yoff);
			printf("Please input the cropped square size:");
			scanf("%d", &Squaresize);
			image = Square(IMAGE *image, Xoff, Yoff, Squaresize);
			printf("\"Square\" operation is done!\n"); 
			break;
		    case 11:
			printf("Please input the brightness level (integer between -255 to 255):");
			scanf("%d", &briT);
			printf("Please input the contrast level (integer between -255 to 255):");
			scanf("%d", &conT);
			image = BrightnessAndContrast(IMAGE *image, briT, conT);
			printf("\"Brightness and Constrast\" is done!\n");
			break;
		    default:
                        break;

                }
            }
        }

        else if (option == 12) {
            AutoTest();
            rc = SUCCESS;    /* set returned code SUCCESS, since image is loaded */
        }
        else {
            printf("Invalid selection!\n");
        }

        /* Process finished, waiting for another input */
        PrintMenu();
        scanf("%d", &option);
    }
    printf("You exit the program.\n");
#endif

    return 0;
}


/*******************************************/
/* Function implementations should go here */
/*******************************************/

/* Menu */
void PrintMenu()
{

    printf("\n-------------------------\n");
    printf("1: Load a PPM image\n");
    printf("2: Save the image in PPM and JPEG format\n");
    printf("3: Change the color image to black and white\n");
    printf("4: Sharpen the image\n");
    printf("5: Change the hue of image\n");
    printf("6: Add Noise to an image\n");
    printf("7: Posterize an image\n");
    printf("8: Add Motion Blur to an image\n");
    printf("9: Enlarge the picture by a percentage\n");
    printf("10: Crop a square portion of the image\n");
    printf("11: Adjust the Brightness and Contrast of an image\n");
    printf("12: Test all fuctions\n");
    printf("13: Exit\n");
    printf("\n-------------------------\n");
    printf("Please make your choise: ");
}
/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */

/* EOF */
