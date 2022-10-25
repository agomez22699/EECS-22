#include "DIPs.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Image.h"

/* Example of DIP */
/* make the picture color black & white */

/* make the picture color black & white */
BlackNWhite(IMAGE *image)
{
    int x, y;
    unsigned char tmpR, tmpG, tmpB;
    int z;
    for (x = 0; x < WIDTH; x++)
    {   for(y = 0; y < HEIGHT; y++)
        {
	tmpR = GetPixelR(image, x, y);
	tmpG = GetPixelG(image, x, y);
	tmpB = GetPixelB(image, x, y);
	z = (tmpR + tmpB + tmpG) / 3;

	SetPixelR(image, x, y, z);
	SetPixelG(image, x, y, z);
	SetPixelB(image, x, y, z);
        }
    }
}

// Sharpen function
Sharpen(IMAGE *image)
{
    int x, y;
    int tmpr = 0, tmpg = 0, tmpb = 0;
    unsigned char R_temp[WIDTH][HEIGHT];
    unsigned char G_temp[WIDTH][HEIGHT];
    unsigned char B_temp[WIDTH][HEIGHT];
    for (x = 0; x < WIDTH; x++)
    {   for(y = 0; y < HEIGHT; y++)
        {   R_temp[x][y] = R[x][y];
            G_temp[x][y] = G[x][y];
            B_temp[x][y] = B[x][y];
        }
    }
    for (x = 1; x < WIDTH - 1; x++)
    {   for (y = 1; y < HEIGHT - 1; y++)
        {   tmpr = 9 * R[x][y] - R[x-1][y-1] - R[x-1][y] - R[x-1][y+1] - R[x][y-1] - R[x][y+1] - R[x+1][y-1] - R[x+1][y] - R[x+1][y+1];
            tmpg = 9 * G[x][y] - G[x-1][y-1] - G[x-1][y] - G[x-1][y+1] - G[x][y-1] - G[x][y+1] - G[x+1][y-1] - G[x+1][y] - G[x+1][y+1];
            tmpb = 9 * B[x][y] - B[x-1][y-1] - B[x-1][y] - B[x-1][y+1] - B[x][y-1] - B[x][y+1] - B[x+1][y-1] - B[x+1][y] - B[x+1][y+1];
        R_temp[x][y] = (tmpr > 255)?255:(tmpr < 0)?0:tmpr;
        G_temp[x][y] = (tmpg > 255)?255:(tmpg < 0)?0:tmpg;
        B_temp[x][y] = (tmpb > 255)?255:(tmpb < 0)?0:tmpb;
        tmpr = tmpg = tmpb = 0;
        }
    }
    for (x = 0; x < WIDTH; x++)
    {   for(y = 0; y < HEIGHT; y++)
        {   R[x][y] = R_temp[x][y];
            G[x][y] = G_temp[x][y];
            B[x][y] = B_temp[x][y];
        }
    }
}


// Hue function
Hue(IMAGE *image, int degree)
{
    int x, y;
    double a, b, r;
    double d = degree * PI / 180.0;
    double tmp_r, tmp_g, tmp_b;
    unsigned char j,k,l;
    unsigned char u,f,n;
    

    a = (2 * cos(d) + 1.0) / 3.0;
    b = (1.0 - cos(d)) / 3.0 - sin(d) / sqrt(3.0);
    r = (1.0 - cos(d)) / 3.0 + sin(d) / sqrt(3.0);

    for (x = 0; x < WIDTH; x++)
    {   for (y = 0; y < HEIGHT; y++)
        {   
	    j = GetPixelR(image, x, y);
	    k = GetPixelG(image, x, y);
	    l = GetPixelB(image, x, y);



	    tmp_r = j * a + k * b + l * r;
            tmp_g = j * r + k * a + l * b;
            tmp_b = j * b + k * r + l * a;

            u = (tmp_r > 255)?255:(tmp_r < 0)?0:tmp_r;
            f = (tmp_g > 255)?255:(tmp_g < 0)?0:tmp_g;
            n = (tmp_b > 255)?255:(tmp_b < 0)?0:tmp_b;

	    SetPixelR(image, x, y, u);
	    SetPixelG(image, x, y, f);
	    SetPixelB(image, x, y, n);
        }
    }
}



/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */
