/*********************************************************************/
/* PhotoLab.c: Assignment 2 for EECS 22, Winter 2020                 */
/* 								     */
/* modifications: 						     */
/* 09/27/17 	RD	adjusted for lecture usage		     */
/* 10/1/18  	MC  	adjusted for F18			     */
/* 01/11/20 	Wendy	adjusted for W20			     */
/*********************************************************************/
/* Enter your name, last name and UCInet ID below:
 * ***************************************************************** *
 * First Name:	Adrian 
 * Last Name:	Gomez
 * UCInet ID:	agomez12
 */

/*** header files ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*** global definitions ***/

#define WIDTH  600		/* image width */
#define HEIGHT 400		/* image height */
#define SLEN    64		/* maximum length of file names */
#define pical 3.14159265358979323846 // pi
/*** function declarations ***/

/* print a menu */
void PrintMenu(void);

/* read image from a file */
/* written for you; should not been modified */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
/* written for you; should not been modified */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* aging the photo */
/* sample function to get you started */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);


/* change a color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* chaneg the image hue */
void Hue(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int degree);

/* test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

int main(void)
{
    /* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];

    /* Please replace the following code with proper menu  */
    /* with function calls for DIP operations	           */
	int running = 1; // variable for while loop
	char input;
	char openfile[64 + 1];
	char closefile[64 +1];
	int userDegree = 0;
	while (running)
	{
	PrintMenu();
	scanf("%c", &input);
	switch (input)
	{
		case '1'://This case is the load image portion of the code
		printf("Please input the file name to load!:\n");
		scanf("%s", openfile);
		LoadImage(openfile, R, G, B);
		break;
		
		case '2'://This case is the save image portion of the code
		printf("Please input the file name to save!:");
		scanf("%s", closefile);
		SaveImage(closefile, R, G, B);
		break;

		case '3':// Black and White Filter
		BlackNWhite(R, G, B);
		printf("'Black and White' operation is done!\n\n");
		break;

		case '4':// Perform Sharpen
		Sharpen(R,G,B);
		printf("Sharpen operation is done!\n\n");
		break;

		case '5':// perform hue
		printf("Please input the Degree of Hue to change:\n");
		scanf("%d", &userDegree);
		Hue(R,G,B, userDegree);
		printf("'Hue' operation is done!\n\n");
		break;

		case '6':// perform hue
		AutoTest(R,G,B);
		printf("AutoTest operation is done!\n\n");
		break;

		case '7':
		printf("Exiting PhotoLab\n");
		running = 0;
		break;
	}// end of Switch
	} // end of While Loop
   // AutoTest(R, G, B);
    /* End of replacing */
    return 0;
}
void PrintMenu(void)
{
printf("-------------------------------------------\n");
printf("1: Load a PPM Image\n");
printf("2: Save the Image in PPM and JPEG format\n");
printf("3: Change the Color of the Image to Black and White\n");
printf("4: Sharpen the Image\n");
printf("5: Change the Hue of the Image\n");
printf("6: Test ALL Functions\n");
printf("7: Exit\n");
printf("-------------------------------------------\n");
printf("Please make a choice:\n");
}

/* takes in a file name without extension */
/* writes file into R, G, B arrays */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char Type[SLEN];
    int  Width, Height, MaxValue;
    int  x, y;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "r");
    if (!File) {
        printf("\nCannot open file \"%s\" for reading!\n", fname);
        return 1;
    }
    fscanf(File, "%79s", Type);
    if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0) {
        printf("\nUnsupported file format!\n");
        return 2;
    }
    fscanf(File, "%d", &Width);
    if (Width != WIDTH) {
        printf("\nUnsupported image width %d!\n", Width);
        return 3;
    }
    fscanf(File, "%d", &Height);
    if (Height != HEIGHT) {
        printf("\nUnsupported image height %d!\n", Height);
        return 4;
    }
    fscanf(File, "%d", &MaxValue);
    if (MaxValue != 255) {
        printf("\nUnsupported image maximum value %d!\n", MaxValue);
        return 5;
    }
    if ('\n' != fgetc(File)) {
        printf("\nCarriage return expected!\n");
        return 6;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            R[x][y] = fgetc(File);
            G[x][y] = fgetc(File);
            B[x][y] = fgetc(File);
        }
    }
    if (ferror(File)) {
        printf("\nFile error while reading from file!\n");
        return 7;
    }
    printf("%s was read successfully!\n", fname_ext);
    fclose(File);
    return 0;
}

/* takes R, G, B arrays and writes it in a file */
/* filename (fname) has no extension */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];
    char SysCmd[SLEN * 5];
    int  x, y;

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "w");
    if (!File) {
        printf("\nCannot open file \"%s\" for writing!\n", fname);
        return 1;
    }
    fprintf(File, "P6\n");
    fprintf(File, "%d %d\n", WIDTH, HEIGHT);
    fprintf(File, "255\n");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fputc(R[x][y], File);
            fputc(G[x][y], File);
            fputc(B[x][y], File);
        }
    }

    if (ferror(File)) {
        printf("\nFile error while writing to file!\n");
        return 2;
    }
    fclose(File);
    printf("%s was saved successfully. \n", fname_ext);

    /*
     * rename file to image.ppm, convert it to ~/public_html/<fname>.jpg
     * and make it world readable
     */
    sprintf(SysCmd, "~eecs22/bin/pnmtojpeg_hw2.tcsh %s", fname_ext);
    if (system(SysCmd) != 0) {
        printf("\nError while converting to JPG:\nCommand \"%s\" failed!\n", SysCmd);
        return 3;
    }
    printf("%s.jpg was stored for viewing. \n", fname);

    return 0;
}

/* age the image to make it look like old picture */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    int x, y;

    for( y = 0; y < HEIGHT; y++ ) {
        for( x = 0; x < WIDTH; x++ ) {
	    B[x][y] = ( R[x][y]+G[x][y]+B[x][y] )/5;
            R[x][y] = (unsigned char) (B[x][y]*1.6);
            G[x][y] = (unsigned char) (B[x][y]*1.6);
	}
    }
}

void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT],unsigned char B[WIDTH][HEIGHT])
{
	int x,y,tmp1;

	for (y = 0; y < HEIGHT; y++){
		for (x = 0; x < WIDTH; x++){
			tmp1 = ( R[x][y] + G[x][y] + B[x][y])/3;
			R[x][y] = tmp1;
			G[x][y] = tmp1;
			B[x][y] = tmp1;
					   } // end of x for loop
 				    } //end of y for loop 
}

void Hue(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int degree)
{
	int x,y;
	double  alpha, beta, charlie;
	double rad;

	rad = degree * (pical/180);
	alpha = (2 * cos(rad) +1)/3;
	beta = ((1-cos(rad))/3) - ((sin(rad))/sqrt(3));
	charlie = ((1-cos(rad))/3) - ((sin(rad))/sqrt(3));
	for(y = 0; y < HEIGHT; y++){
		for(x = 0; x < WIDTH; x++){

			double tmp6,tmp7, tmp8;
			
			tmp6 = R[x][y] * alpha + G[x][y] * beta + B[x][y] * charlie; // Red New
			tmp7 = R[x][y] * charlie + G[x][y] * alpha + B[x][y] * beta; // Green New
			tmp8 = R[x][y] * beta + G[x][y] * charlie + B[x][y] * alpha; // Blue New

			if (tmp6 > 255){
				tmp6 = 255;
				       } // end if
			else if (tmp6 < 0){
				tmp6 = 0;
				     }// end if
			if (tmp7 > 255){
				tmp7 = 255;
				       }//end if
			else if (tmp7 < 0){
 				tmp7 = 0;
				     }//end if
			if (tmp8 > 255){
				tmp8 = 255;
				     }//end if
			else if (tmp8 < 0){
				tmp8 = 0;
				     }// end if
			R[x][y] =(unsigned char) tmp6;
			G[x][y] =(unsigned char) tmp7;
			B[x][y] =(unsigned char) tmp8;
					  }//end of x for loop
				   } //end of y for loop
}

void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	// Temp arrays
	unsigned char tmpR[WIDTH][HEIGHT];
	unsigned char tmpG[WIDTH][HEIGHT];
	unsigned char tmpB[WIDTH][HEIGHT];
	
	//assign values to tmp arrays
	for (int j = 0; j < HEIGHT; j++){
		for (int i = 0; i < WIDTH; i++){
			tmpR[i][j] = R[i][j];
			tmpG[i][j] = G[i][j];
			tmpB[i][j] = B[i][j];
						}
					}
	int x,y;
	int newR, newG, newB;

	//y = 1, x = 1, HEIGHT - 1, WIDTH - 1, so that it only does pixels with neigbors
	for (y = 1; y < HEIGHT - 1; y++){
		for(x = 1; x < WIDTH - 1; x++){
			newR =(unsigned char) (9*tmpR[x][y] - tmpR[x-1][y-1] - tmpR[x][y-1] - tmpR[x+1][y-1] - tmpR[x-1][y] - tmpR[x+1][y] - tmpR[x-1][y+1] - tmpR[x][y+1] - tmpR[x+1][y+1]);
			newG =(unsigned char) (9*tmpG[x][y] - tmpG[x-1][y-1] - tmpG[x][y-1] - tmpG[x+1][y-1] - tmpG[x-1][y] - tmpG[x+1][y] - tmpG[x-1][y+1] - tmpG[x][y+1] - tmpG[x+1][y+1]);
			newB=(unsigned char) (9*tmpB[x][y] - tmpB[x-1][y-1] - tmpB[x][y-1] - tmpB[x+1][y-1] - tmpB[x-1][y] - tmpB[x+1][y] - tmpB[x-1][y+1] - tmpB[x][y+1] - tmpB[x+1][y+1]);

			if (newR > 255){
				newR = 255;
					}
			else if (newR < 0){
				newR = 0;
					  }
			if (newG > 255){
				newG = 255;
					}
			else if (newG < 0){
				newG = 0;
					  }
			if (newB > 255){
				newB = 255;
					}
			else if (newB < 0){
				newB = 0;
					  }
			R[x][y] =(unsigned char) newR;
			G[x][y] =(unsigned char) newG;
			B[x][y] =(unsigned char) newB;
					      }//end x for loop
					}//end y for loop
}
/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    LoadImage("applestore", R, G, B);
    Aging(R, G, B);
    SaveImage("aging", R, G, B);
    printf("Aging tested!\n\n");
    
    /* add more tests here */
    LoadImage("applestore", R, G, B);
    BlackNWhite(R,G,B);
    SaveImage("bw", R, G, B);
    printf("Black and White tested!\n\n");      
	
	LoadImage("applestore", R, G,B);
	Sharpen(R,G,B);
	SaveImage("sharpen", R, G, B);
	printf("Sharpen tested!\n\n");

	LoadImage("applestore", R, G, B);
	Hue(R,G,B,120);
	SaveImage("hue", R, G, B);
	printf("Hue tested!\n\n");	   
}

/**************************************************************/
/* Please add your function definitions here...               */
/**************************************************************/


/* EOF */
