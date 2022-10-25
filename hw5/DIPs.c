/*********************************************************************/
/* 02/27/20 Bo Tsai      updated for EECS22 assignment Winter2020    */
/* Author: Tim Schmidt Date: 11/09/2017                              */
/*                                                                   */
/* DIPs.c: source file for DIP operations                            */
/*                                                                   */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DIPs.h"
#include "Constants.h"
#include <math.h>

IMAGE *BlackNWhite(IMAGE *image, int percent)
{
    /* To be modified, solution from hw4 is given
    assert(image);
    int x, y, average;
    for (x = 0; x < image->W; x++)
    {
        for(y = 0; y < image->H; y++)
        {
            average = (GetPixelR(image, x, y) + GetPixelG(image, x, y) + GetPixelB(image, x, y)) / 3;
            SetPixelR(image, x, y, average);
            SetPixelG(image, x, y, average);
            SetPixelB(image, x, y, average);
        }
    }*/

    return image;
}

IMAGE *HueRotate(IMAGE *image, int percent)
{
    double degree; // modified this line to make it work
    double a, b, r;
    double d = degree * PI / 180.0;
    double tmpr, tmpg, tmpb;

    a = (2 * cos(d) + 1.0) / 3.0;
    b = (1.0 - cos(d)) / 3.0 - sin(d) / sqrt(3.0);
    r = (1.0 - cos(d)) / 3.0 + sin(d) / sqrt(3.0);

    for (int x = 0; x < image->W; x++)
    {   for (int y = 0; y < image->H; y++)
        {
            tmpr = GetPixelR(image, x, y) * a + GetPixelG(image, x, y) * b + GetPixelB(image, x, y) * r;
            tmpg = GetPixelR(image, x, y) * r + GetPixelG(image, x, y) * a + GetPixelB(image, x, y) * b;
            tmpb = GetPixelR(image, x, y) * b + GetPixelG(image, x, y) * r + GetPixelB(image, x, y) * a;

            SetPixelR(image, x, y, (tmpr > MAX_PIXEL)?MAX_PIXEL:(tmpr < 0)?0:tmpr);
            SetPixelG(image, x, y, (tmpg > MAX_PIXEL)?MAX_PIXEL:(tmpg < 0)?0:tmpg);
            SetPixelB(image, x, y, (tmpb > MAX_PIXEL)?MAX_PIXEL:(tmpb < 0)?0:tmpb);
        }
    }
    return image;
}

/* EOF */
