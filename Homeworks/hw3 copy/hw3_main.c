/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw3_main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"
#define NUM_ROWS 8
#define NUM_COLS 8

int main()
{	
	int option;
	printf("1 to test, 2 to play, 0 to quit:\n");
		scanf("%d", &option);
	switch(option)
	{
		case(1): test_checkers(); break;
		case(2): play_checkers(); break;
		case(0): break;
	}

/*
	char board[NUM_ROWS][NUM_COLS];
	init_board(board);
	printf("you're stupid\n");
	available_move('W', 5, 0, board);
*/
}


