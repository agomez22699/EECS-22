/********DO NOT MODIFY THIS SECTION************
 * 
 * EECS 22 : Advanced C Programming
 * Winter 2020, Prof. Quoc-Viet Dang
 * 
 * HW1  : Bingo Simulator
 * Template file : Bingo.c
 * 
 * Created on Jan 5, 2020, 10:56 PM by Bo Tsai <bo.tsai@uci.edu>
 */
/**********************************************
 
// Enter your name, last name and UCInet ID below://
 * 
 * *****************************
 * First Name : Adrian 
 * Last Name: Gomez
 * UCInet ID: agomez12
 * ID: 20119988
 */

#include <stdio.h>
#include <stdlib.h>
/*Declare your function definitions in the section below*/
/*You may add other functions if needed*/
/*********************************************************/



/*********************************************************/

/*Declare your global variables below (if any)*/
/**************************************************/



/**************************************************/

/*Colors (you can add or remove from this list*/
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define max_name_length 64 /*defines max number of characters */

#define NOT_CALLED 0
#define THIS_ROUND 1
#define PREV_ROUNDS 2

typedef struct {
	char *name;
	int **check;
	int **board;
	int win;
		}player_t;


int has_called(int  *called ,int c,  int b){
	for (int i = 0; i < c; i++){
		if (called[i] == b){
			return(PREV_ROUNDS);
					} /* fi */
					} /* rof */
	if (called[c] == b){
		return(THIS_ROUND);
				} /* fi */
return(NOT_CALLED);
		
}

void in_board(player_t player, int c, int dim){
	for (int row = 0; row < dim; row++){
		for (int col = 0; col < dim; col++){
			if (player.board[row][col] == c){
				player.check[row][col] = 1;
							} /* fi */
						   } /* rof */
					   } /* rof */
					      } /* end of in board */
int  is_winner(int ** board, int dim){
	/* Horizontal Check */
	for (int row = 0; row < dim; row++){
		int a = 0;
		for(int col = 0; col < dim; col++){
			a += board[row][col];
			if (a == dim){
			return 1;
				     } /* fi */	
						  } /* rof */
					    } /* rof */
	/* Vertical Check */ 
	for (int col = 0; col < dim; col++){
		int a = 0;
		for (int row = 0; row < dim; row++){
			a += board[row][col];
			if (a == dim){
				return 1;
					} /* fi */
							} /* fi */
						} /* rof */
	/* Diagonal Check 1 */
	int a1 = 0;
	for (int row = 0; row < dim; row++){
		for (int col = 0; col < dim; col++){
			if (row == col){
				a1 += board[row][col];
				if ( a1 == dim){
					return 1;
						} /* fi */
					} /* fi */
							} /* rof */
						} /* rof */
	/* Diagonal Check 2 */
	int i = 0;
	int a2 = 0;
	for (int row = dim - 1; row >= 0; row--){
		for (int col = 0; col < dim; col++){
			if (col == i){
				a2 += board[row][col];
				     } /* fi */
						   } /* rof */
		i += 1;
						} /* rof */
	if (a2 == dim){
		return 1;
		      }
	return 0;
				} /* end of is_winner */
void print_board(player_t player, int * called, int c, int dim){
	for (int row = 0; row < dim; row++){
		for (int col = 0; col < dim; col++){
			switch(has_called(called, c, player.board[row][col])){
				// The Number has never been called before
				case NOT_CALLED:
					printf("%d", player.board[row][col]);
					if (col == dim - 1){
						printf("\n");
							   } /* fi */
					else {
						printf(" ");
					     } /* esle */
					break;
				case THIS_ROUND:
					printf("%s%d%s", KGRN, player.board[row][col], KNRM);
					if (col == dim - 1){
						printf("\n");
							   } /* fi */
					else{
						printf(" ");
					    } /* esle */
					break;
				case PREV_ROUNDS:
					printf("%s%d%s", KRED, player.board[row][col], KNRM);
					if (col == dim - 1){
						printf("\n");
							   } /* fi */
					else {
						printf(" ");
					     } /* esle */
					break;
									     } /* hctiws */
						   } /* rof */
					   } /* rof */
								} /* end of print board */
/* Main Function */
int main(int argc, char** argv) {

	/* opens the sample file */
	FILE *infile;
 	infile = fopen("BingoSampleInput1.txt", "r");
		if (infile == NULL){
			fprintf(stderr, "Cannot open input file \n");
			return 1;
					} /* fi */
	/*Reads first line of input file */
	int playerc, dim;
	fscanf(infile, "%d %d\n", &playerc, &dim);

	/* allocating player structures */
	/* The Board is an array of pointers to rows */
	/* Each row is an array of integers */	
	player_t *players = malloc(playerc * sizeof(player_t));
		for (int p = 0; p < playerc; p++) {
			players[p].name = malloc((max_name_length + 1) * sizeof(char));
			players[p].check = (int **)malloc(dim *sizeof(int *));
				for (int row = 0; row < dim; row++)
				players[p].check[row] = (int *)malloc(dim * sizeof(int));
			players[p].board = (int **)malloc(dim * sizeof(int *));
				for (int row = 0; row < dim; row++)
				players[p].board[row] = (int *)malloc(dim * sizeof(int));
						}				
	/* Populate the player structure with name and board */
		for (int p = 0; p < playerc; p++) {
			fscanf(infile, "%s\n", players[p].name);
			for (int row = 0; row < dim; row++) {
				for (int col = 0; col < dim; col++) {
					fscanf(infile, "%d ", &players[p].board[row][col]);
									} /* rof */
				//fscanf(infile, "%d\n", &players[p].board[row][dim - 1]);
							   } /* rof */
						   } /* rof */
	/* Get the called numbers list */
	int numberc = dim * dim;
	int *called = malloc(numberc * sizeof(int)); 
	int i;
		for (i = 0; i < numberc - 1; i++) {
			fscanf(infile, "%d ", &called[i]);
							} /* rof  */
		fscanf(infile, "%d\n", &called[numberc - 1]);
	fclose(infile);

	/* example of accessing data strcuture to print out player */
	int p; /* number of player to print */
	printf("Start of the game\n");
	for (p = 0; p < playerc; p++) {
		printf("*** %s ***\n", players[p].name);
			for (int row = 0; row < dim; row++){
				for (int col = 0; col < dim - 1; col++) {
					printf("%d ", players[p].board[row][col]);
								} /* rof */
			printf("%d\n", players[p].board[row][dim - 1]);
						   } /*rof*/
					} /* rof */
	/* Start of the bingo simulation */ 
	int c;
	int  winner = 0;
	for (c = 0; c < numberc; c++) {
		printf("Caller called %d\n", called[c]);
		/* Checks Caller and prints */ 
		for (int p = 0; p < playerc; p++){
			in_board(players[p], called[c], dim);
			if (is_winner(players[p].check, dim) == 1){
				players[p].win = 1;
				winner = 1;
				printf("*** %s Bingo! ***\n", players[p].name);
			/* code for printing board */
			print_board(players[p], called, c, dim);
							} /* fi */
			else {
				printf("*** %s***\n", players[p].name);
				print_board(players[p], called, c, dim);	
			     } /*esle */
						} /* rof */ 
		if (winner == 1){
			printf("%d ", called[c]);
			/* print list of winners */
			for (int i = 0; i < playerc; i++){	
				if (players[i].win == 1){
					printf("%s ", players[i].name);
							} /* fi */
						     } /* rof */
			printf("\n");
			break;
				} /* fi */

					} /* rof */
	} /* end of main */	
/* EOF */
