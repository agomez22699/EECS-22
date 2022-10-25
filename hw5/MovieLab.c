/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Winter 2020                   */
/*                                                                   */
/* Author: Bo Tsai                                                   */
/*                                                                   */
/* MovieLab.c: source file for the main function                     */
/*                                                                   */
/* Please use this template for your HW5.                            */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileIO.h"
#include "DIPs.h"
#include "Movie.h"
#include "Constants.h"
#include "Image.h"
#include "MovieIO.h"
#include "IterativeFilter.h"

int main(int argc, char *argv[])
{
    IMAGE *input = NULL;
    int importFlag = 0;
    // allocate necessary variables

    // loop through each argument for the main function
    for(int n = 0; n < argc; n++)
    {
        // If the user wants to import an image
        if(!strcmp(argv[n], "-i"))
        {
            // If they are at the last argument
            if(n == argc - 1)
            {
                printf("\n\tPlease provide the name of the image you want to import\n");
                return 0;
            }

            input = LoadImage(argv[++n]);

            if(!input)
            {
                printf("\n\tThe image file %s could not be read\n", argv[n]);
                return 0;
            }

            // Let the program know an image has succesfully been imported
            importFlag = 1;
        }

        // If the user wants to import a movie
        else if(!strcmp(argv[n], "-m"))
        {        
            // to be implemented
            

            // Let the program know a movie has succesfully been imported
            importFlag = 2;
        }
        // other arguments to be implemented
        
    }

    // Load the default image if no argument was specified
    if(!importFlag)
    {
        printf("\nNo -i nor -m for input file to read\n");
        return 0;
    }
    else if(importFlag == 1)
    {
        // to be implemented
    }
    else if(importFlag == 2)
    {
    
        // to be implemented
    }
    return 0;
}

/* EOF */
