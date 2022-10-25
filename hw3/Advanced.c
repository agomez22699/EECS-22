/* the module for new DIP Filters */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Constants.h"
#include "Advanced.h"


void Posterize(unsigned char R[WIDTH][HEIGHT],
		 unsigned char G[WIDTH][HEIGHT],
		 unsigned char B[WIDTH][HEIGHT], 
		 unsigned int rbits,
		 unsigned int gbits,
		 unsigned int bbits)
{
	int x, y, z;
  	for(x = 0; x < WIDTH; x++)
  	{
		for(y = 0; y < HEIGHT; y++ )
		{
 			int r, g, b = 0;
 			int i, j, k = 0;
			for(z = 0; z < rbits - 1; z++)
			{
				r = (r << 1) + 1;
			}
			R[x][y] = R[x][y] | r;
			i = 1 << (rbits - 1);
			R[x][y] = R[x][y] & ~i;

			for(z = 0; z < gbits - 1; z++)
			{
				g = (g << 1) + 1;
			}
			G[x][y] = G[x][y] | g;
			j = 1 << (gbits - 1);
			G[x][y] = G[x][y] & ~j;

			for(z = 0; z < bbits - 1; z++)
			{
				b = (b << 1) + 1;
			}
			B[x][y] = B[x][y] | b;
			k = 1 << (bbits - 1);
			B[x][y] = B[x][y] & ~k;
 		}
	}
}

void Noise( int n, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]){
	printf("\n Noise is not working... \n");
}
