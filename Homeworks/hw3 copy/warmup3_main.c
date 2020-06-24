/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup3_main.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "warmup3.h"

/* test_print_array                                                                  
 *   purpose: tests the print_array function                                          
 * inputs:                                                                      
 *   int array[]: the inputted array                                            
 *   unsigned int length: the length of the inputted array                      
 * return value:                                                                
 *   no return value -- just prints out a given array                           
 */                                                                             
void test_print_array(int array[], unsigned int length)
{
	printf("print_array(array):\n");
	print_array(array,length);
	printf("\n");

}   

/* test_remove_max
 *   purpose: tests the remove_max function
 * inputs:
 *   int array - the inputted array
 *	unsigned int length - the length of the inputted array
 *   unsigned int expected - the expected output
 * return value
 *   unsigned int - 1 for success, 0 for failure
 */
unsigned int test_remove_max(int array[], unsigned int length, int expected)
{
	int answer = remove_max(array, length);
	
	// if the answer is what was expected
	if(answer == expected)
	{
		printf("remove_max(array, %d): %d Success.\n", length, answer);
		return 1;
	}
	// if the answer is not what was expected
	else
	{
		printf("remove_max(array,%d): %d Expected: %d FAILURE\n", length,
			  answer, expected);
		return 0;
	}

}

/* test_init_board
 *	purpose: tests the init_board function
 * inputs:
 * 	char board[NUM_ROWS][NUM_COLS]: the board with its dimensions
 * return value:
 *	no return value -- just prints to screen
 */
void test_init_board(char board[NUM_ROWS][NUM_COLS])
{
	printf("init_board(board[%d][%d]:\n", NUM_ROWS, NUM_COLS);
	init_board(board);
	printf("\n");
}

/* test_is_empty
 *	purpose: tests the is_empty function
 * inputs:
 *	char board[NUM_ROWS][NUM_COLS] - the current status of the board
 *   unsigned int row - the destination row value
 *   unsigned int col - the destination column value
 *	unsgined int expected - the expected output
 * return value:
 *	unsigned int - 1 for success, 0 for failure
 */
unsigned int test_is_empty(char board[NUM_ROWS][NUM_COLS], unsigned int row,         
	unsigned int col, unsigned int expected)
{
	int answer = is_empty(board, row, col);

	// if the answer is what was expected 
	if(answer == expected)
	{
		printf("is_empty(array, %d, %d): %d Success\n", row, col, answer);
		return 1;
	}
     // if the answer is not what was expected 
	else
	{
		printf("is_empty(array, %d, %d): %d Expected: %d FAILURE\n", row,
			  col, answer, expected);
		return 0;
	}
}

/* test_place_piece
 *	purpose: tests the place_piece function
 * inputs:
 *   char board[NUM_ROWS][NUM_COLS]: the state of the current board
 *   char player - denotes who the current player is
 *   unsigned int row - the destination row value
 *   unsigned int col - the destination column value
 *	unsigned int expected - the expected output of the function
 * return value:
 *	unsigned int - 1 for success, 0 for failure
 */
unsigned int test_place_piece(char board[NUM_ROWS][NUM_COLS], char player,           
     unsigned int row, unsigned int col, unsigned int expected) 
{
	int answer = place_piece(board, player, row, col);

	// if the answer is what was expected
     if(answer == expected)
     {
          printf("place_piece(array, %c, %d, %d): %d Success\n", player, row, 
			  col, answer);
          return 1;
     }
     // if the answer is not what was expected
     else
     {
          printf("place_piece(array, %c, %d, %d): %d Expected: %d FAILURE\n",
                 player, row, col, answer, expected);
          return 0;
     }
}

/* test_area_and_perimeter                                                           
 *   purpose: tests the area_and perimeter function 
 * input:                                                                       
 *   double height - the height of a given rectangle                            
 *   double length - the length of a given rectangle                            
 *   double *area - a pointer pointing to the address of the area that will     
 *                  be returned                                                 
 *   double *perimeter - a pointer pointing to the address of the perimeter     
 *                       that will be returned                                  
 * return value                                                                 
 *   no return value                                                                  
 */                                                                             
void test_area_and_perimeter(double height, double length, double *area,             
     double *perimeter)
{
	area_and_perimeter(height, length, area, perimeter);
}	


unsigned int test_remove_max_int_out(int array[], unsigned int *length, 
	unsigned int expected)
{
	int answer = remove_max_int_out(array, length);

	// if the answer is what was expected                                         
     if(answer == expected)                                                        
     {                                                                             
          printf("remove_max_int_out(array, %d): %d Success\n", *length,   
                 answer);                                                     
          return 1;                                                                
     }                                                                             
     // if the answer is not what was expected                                     
     else                                                                          
     {                                                                             
          printf("remove_max_in_out(array,%d): %d Expected: %d FAILURE\n",   
                 *length, answer, expected);                              
          return 0;                                                                
     }               

}
/* main function
 *	purpose: tests all functions
 */
int main()
{
	int test_arr1[5] = {3,2,8,5,4}, test_arr2[3] = {7,7,7};
	int test_arr3[10] = {5,6,12,6,78,2,4,6,3,8}; 
	int test_arr4[4] = {9,1,2,7}, test_arr5[0];
	char start[NUM_ROWS][NUM_COLS];
	char test[12][12];
	double area, height;
	int remove_array[6] = {3,2,8,5,8,4};
	int length;

	printf("TESTS\n");
	printf("\nprint_array tests\n");
		test_print_array(test_arr1, 5);
		test_print_array(test_arr2, 3);
		test_print_array(test_arr3, 10);
		test_print_array(test_arr4, 4);
	printf("remove_max tests\n");
		print_array(test_arr1, 5);
			test_remove_max(test_arr1, 5, 8);
		print_array(test_arr1, 5);
		print_array(test_arr2, 3);
			test_remove_max(test_arr2, 3, 7);
		print_array(test_arr2, 3);
		print_array(test_arr3, 10);
			test_remove_max(test_arr3, 10, 78);
		print_array(test_arr3, 10);
		print_array(test_arr4, 4);
			test_remove_max(test_arr4, 4, 9);
		print_array(test_arr4, 4);
		print_array(test_arr5, 0);
			test_remove_max(test_arr5, 0, INT_MIN);
		print_array(test_arr5, 0);
	printf("\ninit_board tests\n");
		test_init_board(start);
		print_board(start);
	printf("\nis_empty test\n");
		test_is_empty(start, 0, 1, 0);
		test_is_empty(start, 4, 6, 1);
	printf("\nplace_piece tests\n");
		test_place_piece(start, 'w', 4, 6, 1);
		print_board(start);
		test_place_piece(start, 'b', 3, 2, 1);
		print_board(start);
		test_place_piece(start, 'b', 5, 4, 0);
		print_board(start);
	printf("\narea_and_perimeter tests\n");
		test_area_and_perimeter(5, 3, &area, &height);
		printf("area_and_perimeter(5, 3, &area, &height):\n"
		       "The area is %.2f and the perimeter is %.2f\n", area, height);
		test_area_and_perimeter(2.4, 8.6, &area, &height);                        
          printf("area_and_perimeter(2.4, 8.6, &area, &height):\n"                  
                 "The area is %.2f and the perimeter is %.2f\n", area, height); 
		test_area_and_perimeter(10.56, 80.12, &area, &height);                        
          printf("area_and_perimeter(10.56, 80.12, &area, &height):\n"                  
                 "The area is %.2f and the perimeter is %.2f\n", area, height);
	printf("\nremove_max_int_out tests\n");
		int arr1[5] = {3,2,8,5,4}, arr2[3] = {7,7,7};
		int arr3[10] = {5,6,12,6,78,2,4,6,3,8}, arr4[4] = {9,1,2,7},arr5[0];
		unsigned int a = 5, b = 3, c = 10, d = 4, e = 0;
		test_remove_max_int_out(arr1, &a, 4);
		test_remove_max_int_out(arr2, &b, 0); 
		test_remove_max_int_out(arr3, &c, 9);
		test_remove_max_int_out(arr4, &d, 3);
		test_remove_max_int_out(arr5, &e, 0);

}		
