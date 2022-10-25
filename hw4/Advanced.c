#include "Advanced.h"
#include "Image.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* Add noise to an image */
Noise(int n, IMAGE *image)
{
	int x, y, i;
	int num; /* number of noise added */
	num = ( n*HEIGHT*WIDTH )/100;
	srand(time(NULL));

	for ( i = 0; i < num; i++ ) {
		x = ( (double)rand()/RAND_MAX )*(WIDTH-1);
		y = ( (double)rand()/RAND_MAX )*(HEIGHT-1);
		SetPixelR(image, x, y, 255);
		SetPixelG(image, x, y, 255);
		SetPixelB(image, x, y, 255);
	}
}

/* make the image posterized */
Posterize(IMAGE *image, unsigned int rbits, unsigned int gbits, unsigned int bbits)
{
	int x, y;
	for(x=0; x<WIDTH; x++) {
		for(y=0; y<HEIGHT; y++) {
			unsigned char one = 1;
			int i;
			for(i=0; i<rbits-1; i++) {
				GetPixelR(image, x, y); |= one;
				one <<= 1;
			}
			one = ~one;
			GetPixelR(image, x, y); &= one;

			one = 1;
			for(i=0; i<gbits-1; i++) {
				GetPixelG(image, x, y); |= one;
				one <<= 1;
			}
			one = ~one;
			GetPixelG(image, x, y); &= one;

			one = 1;
			for(i=0; i<bbits-1; i++) {
				GetPixelB(image, x, y); |= one;
				one <<= 1;
			}
			one = ~one;
			GetPixelB(image, x, y); &= one;
		}
	}
}

/* add motion blur to the image */
MotionBlur(int BlurAmount, IMAGE *image)
{
	int x,y,m;
	int temp_r , temp_g , temp_b;
	int e, q, s;

	for (x = 0; x < WIDTH; x++)
	{
        	for (y = HEIGHT - 1; y >= 0 ; y--)
		{
			int count = 0;
			temp_r = temp_g = temp_b = 0.0;
			for (m = 1; m<=BlurAmount ; m++)
			{
				//if ((x-m) >= 0)
				if((y-m) >= 0)
				{
					temp_r += GetPixelR(image, x, y-m);;
					temp_b += GetPixelB(image, x, y-m);
					temp_g += GetPixelG(image, x, y-m);
					count++;
				}
			}
			count = (count==0)?1:count;
			e = temp_r / 2.0 / count + R[x][y] / 2.0;
			q = temp_b / 2.0 / count + B[x][y] / 2.0;
			s = temp_g / 2.0 / count + G[x][y] / 2.0;

			SetPixelR(image, x, y, e);
			SetPixelG(image, x, y, q);
			SetPixelB(image, x, y, s);
		}
	}
		
}

Enlarge(IMAGE *image, int enlarge_percentage){

}

Square(IMAGE *image, int x_offset, int y_offset, int square_size){

}

BrightnessAndContrast(IMAGE *image, int brightness, int contrast){
	int x,y;
	unsigned char a,b,c, d,e,f;
	unsigned char factor;
	
	for (x = 0; x < WIDTH; x++){
		for (y = 0; x < WIDTH; y++){

			a = GetPixelR(image, x, y);
			b = GetPixelG(image, x, y);
			c = GetPixelB(image, x, y);	
			
			a += brightness;
			b += brightness;
			c += brightness;

			a = (a > 255)?255:(a < 0)?0:a;
		        b = (b > 255)?255:(b < 0)?0:b;
		        c = (c > 255)?255:(c < 0)?0:c;
			
			factor = (double)(259 * (contrast + 255)) / (double)(255 * (259 - contrast));
			d = (int)(factor * (a - 128) + 128);
			e = (int)(factor * (b - 128) + 128);
			f = (int)(factor * (c - 128) + 128);

			SetPixelR(image, x, y, d);
			SetPixelR(image, x, y, e);
			SetPixelR(image, x, y, f);

			
				
						}
					}
}
/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */
