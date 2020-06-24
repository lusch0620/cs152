/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup3.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "warmup3.h"
#define NUM_ROWS 8
#define NUM_COLS 8

/* print_array
 *	purpose: prints out a given array
 * inputs:
 *	int array[]: the inputted array
 *	unsigned int length: the length of the inputted array
 * return value:
 *	no return value -- just prints out a given array
 */
void print_array(int array[], unsigned int length)
{
	int i;
	
	printf("{");
	
	for(i = 0; i < length; i++)
	{
		if(i == length - 1)
     	{
          	printf("%d}\n", array[length - 1]);
     	}
		else
		{
			printf("%d, ", array[i]);
		}
	}
}	


/* remove_max
 *   purpose: finds the maximium item, removes all instances of that value from
 *            the array , and returns the value
 * inputs:
 *   int array[]: the inputted array with values in it
 *   unsigned int length: the length of the array
 * return value:
 *   the max value found in the array / also note that the array changes
 */
int remove_max(int array[], unsigned int length)
{
	int i, j, max = array[0], acc = 0;
	
	if(length == 0)
	{
		return INT_MIN;
	}

	//iteratively loop through the array to find a max value
	for(i = 0; i < length; i++)
	{
		// assign the current value of the array to max if the current value 
		// of the array is larger than the current max
		if(array[i] >=  max)
		{
			max = array[i];
		}
	}
	
	//check how many times the max occurs in the array
	for(i = 0; i< length; i++)
	{
		if(array[i] == max)
		{
			acc++;
		}
	}

	while(acc > 0)
	{
		// iteratively loop through the array to find the index of the max value
		for(i = 0; i < length; i++)
		{
			// break if the the current value of the array is the max value so
			// that the index of max is captured
			if(array[i] == max)
			{
				break;
			}
		}
	
		for(j = i; j < length; j++)
		{
			array[j] = array[j+1];
		}
	acc--;
	}
	return max;
}

/* init_board
 * initializes the contents of the checkerboard.
 * The blue pieces occupy rows 0 to (NUM_ROWS/2 - 2), and
 * the white pieces occupy rows (NUM_ROWS / 2 + 1) to NUM_ROWS-1
 * An 8x8 board looks like this:
   * b * b * b * b
   b * b * b * b *
   * b * b * b * b
   * * * * * * * *
   * * * * * * * *
   w * w * w * w *
   * w * w * w * w
   w * w * w * w *
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void init_board(char board[NUM_ROWS][NUM_COLS])
{
	int row, col, i;
	
	// iteratively loop through all the rows
	for(row = 0; row < NUM_ROWS; row++)
	{	
		//places the blue pieces in the proper place
		if(row >= 0 && row <= (NUM_ROWS/2 - 2))
		{
			//odd rows
			if((row % 2) == 1)
			{	
				// iteratively loops through each column
				for(col = 0; col < NUM_COLS; col++)
				{
					//odd columns
					if((col % 2) == 1)
					{
						board[row][col] = '*';
					
					}
					//even columns
					if((col % 2) == 0)
					{
						board[row][col] = 'b';
					}
				}
				//printf("\n");
			} 
			//even rows
			if((row % 2) == 0)
			{	
				// iteratively loops through each column
				for(col = 0; col < NUM_COLS; col++)
				{
					// odd columns
					if((col % 2) == 1)
					{
						//printf("b ");
						board[row][col] = 'b';
					}
					// even columns
					if((col % 2) == 0)
					{
						//printf("* ");
						board[row][col] = '*';
					}	
				}
				//printf("\n");
			}
		}
		// the middle part of the board
		if(row > (NUM_ROWS/2 - 2) && row < (NUM_ROWS/2 +1))
		{
			// iteratively loops through the columns adding stars
			for(col = 0; col < NUM_COLS; col++)
			{
				// every column except the last one prints an
				// asterisk
				if(col != NUM_COLS )
				{
					//printf("* ");
					board[row][col] = '*';
				}
				// the last column prints an asterisk and also
				// starts a new line
				//else
				//{
				//	printf("*\n");
				//}
			}
		}
		// places the white pieces in the proper place 
		if(row >= (NUM_ROWS/2 + 1) && row <= (NUM_ROWS - 1))
		{
			// odd rows
			if((row % 2) == 1)
			{
				// iteratively loops through each column
				for(col = 0; col < NUM_COLS; col++)
				{
					// if the column is odd
					if((col % 2) == 1)
					{
						//printf("* ");
						board[row][col] = '*';
					}
					// if the column is even
					if((col % 2) == 0)
					{
						//printf("w ");
						board[row][col] = 'w';
					}
				}
				//printf("\n");
			}
			// even rows
			if((row % 2) == 0)
			{
				// iteratively loops through each column
				for(col = 0; col < NUM_COLS; col++)
				{
					// if the column is odd
					if((col % 2) == 1)
					{
						//printf("w ");
						board[row][col] = 'w';
					}
					// if the column is even
					if((col % 2) == 0)
					{
						//printf("* ");
						board[row][col] = '*';
					}
				}
				//printf("\n");
			}
		}
	}
}	

/* is_empty
 *	purpose: decides if a selected cell in on the board is empty
 * inputs:
 *	char board[NUM_ROWS][NUM_COLS] - the current status of the board
 *   unsigned int row - the destination row value
 *	unsigned int col - the destination column value
 * return value:

 *	unsigned int - 1 if empty, 2 if not
 */
unsigned int is_empty(char board[NUM_ROWS][NUM_COLS], unsigned int row,
	unsigned int col)
{
	// if the destination location in the array/board is empty/is an asterisk
	if(board[row][col] == '*')
	{
		return 1;
	}
	// if the destination location is a player or anything else
	else
	{
		return 0;	
	}
}

/* place_piece
 *	purpose: checks the validity of the destination location and places a 
 *		    player's piece there
 * inputs:
 *	char board[NUM_ROWS][NUM_COLS]: the state of the current board
 *	char player - denotes who the current player is
 *	unsigned int row - the destination row value
 *	unsigned int col - the destination column value
 * return value:
 *	unsigned int - 1 if a checker has been correctly added to the board
 *			   - 0 if the destination location is invalid
 */
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player,
	unsigned int row, unsigned int col)
{
	// proceed as long as the destination location is on the board
	if(row <= NUM_ROWS || col <= NUM_COLS)
	{
		// if the destination location is empty
		if(is_empty(board, row, col) == 1)
		{
			board[row][col] = player;
			return 1;
		}
		// if the destination location is not empty
		else
		{
			return 0;
		}


	}
	// error if the inputted destination location is not on the board
	else
	{
		return 0;
	}
}

/* print_board
 * prints the contents of the checkerboard.
 * The pieces are 'b', 'w', the kinged ones
 * are 'B'and 'W', and empty spaces are '*'
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void print_board( char board[NUM_ROWS][NUM_COLS] )
{
        unsigned int i, j;
        printf("   ");
        for(j=0;j<NUM_COLS;j++)
        {
                printf("%u ",j);
        }
        printf("\n");
        for(i=0;i<NUM_ROWS;i++)
        {
                printf("%u: ",i);
                for(j=0;j<NUM_COLS;j++)
                {
                        printf("%c ",board[i][j]);
                }
                printf("\n");
        }
}

/* area_and_perimeter
 *   purpose: given the height and length, the area and height will be
 *           calculated and returned
 * input:
 *   double height - the height of a given rectangle
 *   double length - the length of a given rectangle
 *   double *area - a pointer pointing to the address of the area that will
 *                  be returned
 *   double *perimeter - a pointer pointing to the address of the perimeter
 *                       that will be returned
 * return value
 *   changes the value of area and perimeter that was originally stored at the
 *   address
 */
void area_and_perimeter(double height, double length, double *area,
     double *perimeter)
{
     *area = height * length;
     *perimeter = (2 * height) + (2 * length);
}

/* remove_max_int_out
 *	purpose: removes the max value found in an array and also returns the 
 *		    current length of the array with the max(es) removed
 * input:
 *	int array[] - an array of a specified length
 *	unsigned int *length - a pointer pointing to the address of the variable
 *					   storing the length of the array
 * return value:
 *	the new updated length
 */
int remove_max_int_out(int array[], unsigned int *length)
{
	int max= 0, i, j, acc;
	
	//iteratively loop through the array to find a max value
	for(i = 0; i < *length; i++)                                                
     {        
		// assign the current value of the array to max if the current value  
		// of the array is larger than the current max                      
		if(array[i] >=  max)                                                 
		{                                                                    
			max = array[i];                                                
		}                                                                     
     } 
	
	// if the length is 0
	if(*length == 0)
	{
		return 0;
	}
	// if the length > 0
	else
	{
	     //check how many times the max occurs in the array                         
     	for(i = 0; i< *length; i++)                                                 
     	{              
			// if the current value of the array is the same as the max
          	if(array[i] == max)                                                   
          	{                                                                     
               	acc++;                                                           
          	}                                                                     
     	}                                                                          
          *length = *length - acc;                                       
		
		// the acc is how many times we need to go through the array to 
		// remove an acc number of maxes
     	while(acc > 0)                                                 
     	{                                                                          
          	// iteratively loop through the array to find the index of 
			// the max value
          	for(i = 0; i < *length; i++)                                           
          	{                                                                     
              		// break if the the current value of the array is the max
               	// value so that the index of max is captured                             
               	if(array[i] == max)                                              
               	{                                                                
                   		break;                                                      
               	}                                                                
          	}                                                                     
               // shift all the values of the array back by 1 once the max 
			// has been removed
          	for(j = i; j < *length; j++)                                           
          	{                                                                     
               	array[j] = array[j+1];                                           
          	}                                                                     
     	acc--;                                                                     
    	 	}	 
	}
	return *length;
}
