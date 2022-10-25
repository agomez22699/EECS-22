/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Tim Schmidt                                               */
/* Date: 11/09/2017                                                  */
/*                                                                   */
/* Movie.c: source file for basic movie manipulations                */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <assert.h>
#include "Movie.h"

/* Allocate the memory space for the movie and the memory space */
/* for the frame list. Return the pointer to the movie. */
MOVIE *CreateMovie(void)
{
	MOVIE *movie = malloc(sizeof(MOVIE));
	movie->Frames = CreateImageList();
	return movie;
}

/* Release the memory space for the frame list. */
/* Release the memory space for the movie. */
void DeleteMovie(MOVIE *movie)
{
	ILIST *s;
	assert(movie);
	s = movie->ImageList;
	DeleteImageList(s);
	free(movie);
}

/* Convert a YUV movie to a RGB movie */
void YUV2RGBMovie(MOVIE *movie)
{

}

/* Convert a RGB movie to a YUV movie */
void RGB2YUVMovie(MOVIE *movie)
{

}

int MovieLength(const MOVIE *movie)
{
    return movie->Frames->length;
}

int MovieHeight(const MOVIE *movie)
{
    if(movie->Frames->First->RGBImage)
    {
        return movie->Frames->First->RGBImage->H;
    }//fi

    else if(movie->Frames->First->YUVImage)
    {
        return movie->Frames->First->YUVImage->H;
    }//fi esle

    else
    return 0;
}

int MovieWidth(const MOVIE *movie)
{
    if(movie->Frames->First->RGBImage)
        {
                return movie->Frames->First->RGBImage->W;
        }//fi

        else if(movie->Frames->First->YUVImage)
        {
                return movie->Frames->First->YUVImage->W;
        }//fi esle

        else
        return 0;
}

/* EOF */
