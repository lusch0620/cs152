#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup2.h"  // note this new include file!!!

// TODO: Write a test function for each exercise

/* test_print_asterisk_letter
 *	purpose: tests the print_asterisk_letter function
 * inputs: 
 *	char letter - the letter to be printed with asterisks
 * return value:
 *	nothing returned, just prints to the screen
 */
void test_print_asterisk_letter(char letter)
{
	printf("print_asterisk_letter(%c): \n", letter);
	print_asterisk_letter(letter);
	printf("\n\n");
}

/* test_draw_asterisk_rows
 *	purpose: tests the draw_asterisk_rows function 
 * inputs:
 *	unsigned int length - the number of asterisks to be printed
 * return value:
 *	nothing returned, just prints to the screen
 */
void test_draw_asterisk_rows(unsigned int length)
{
	printf("draw_asterisk_rows(%d): \n", length);
	draw_asterisk_rows(length);
	printf("\n\n");
}

/* test_space
 *   purpose: tests the space function
 * inputs:
 *   unsigned int space_num - the number of spaces to be created
 * outputs:
 *   nothing returned, just printed to the screen
 * Note: due to the fact that these are spaces, I've added an asterisk at the
 *       very end to ensure that the correct number of spaces have been printed
 */
void test_space(unsigned int space_num)
{
	printf("test_space(%d): \n", space_num);
	spaces(space_num);
	printf("*");
	printf("\n\n");
}

/* test_draw_hourglass_rec_helper
 *	purpose: tests the hourglass rec helper function
 * inputs:
 *   unsigned int height - the height for the hourglass
 *	unsigned int offset - amount of space that should be to the left 
 *					  of the hourglass
 * return value:
 *	nothing returned, just prints to the screen
 */
void test_draw_hourglass_rec_helper(unsigned int height, unsigned int offset)
{
	printf("draw_hourglass_rec_helper(%d, %d): \n", height, offset);
	draw_hourglass_rec_helper(height, offset);
	printf("\n\n");
}

/* test_draw_hourglass_rec
 * 	purpose: tests the hourglass rec function
 * inputs:
 * 	unsigned int height - the height of the hourglass
 * outputs:
 * 	nothing returned, just prints to the screen
 */
void test_draw_hourglass_rec(unsigned int height)
{
	printf("draw_hourglass_rec(%d): \n", height);
	draw_hourglass_rec(height);
	printf("\n\n");
}

/* test_draw_hourglass_iter
 *	purpose: tests the draw_hourglass_itr function
 * inputs:
 * 	unsigned int height - the height of the hourglass
 * outputs:
 * 	nothing returned, just prints to the screen
 */
void test_draw_hourglass_iter(unsigned int height)
{
	printf("draw_hourglass_iter(%d): \n", height);
	draw_hourglass_iter(height);
	printf("\n\n");
}

/* Principle 2: Design a good set of test cases
 * they check the base case (0), right above the base case (1), well
 * above the base case (5, 8), and error conditions (-1, -5).
 * -1, 0, 1 are the boundary test cases - base, base+1, base-1.
 */
int main()
{

	// I am only putting one line in for each to make sure it compiles
	// you need to write your own test code

	// TODO: Write 3+ good test cases. 
	// TODO: Replace these calls with call to test function
	printf("TESTS\n\n");
	
	printf("print_asterisk_letter tests:\n");
		test_print_asterisk_letter('s');
		test_print_asterisk_letter('t');
		test_print_asterisk_letter('u');
		test_print_asterisk_letter('v');
	printf("draw_asterisk_rows tests\n");
		test_draw_asterisk_rows(0);
		test_draw_asterisk_rows(4);
		test_draw_asterisk_rows(9);
		test_draw_asterisk_rows(2);
	printf("spaces tests\n");
		test_space(0);
		test_space(3);
		test_space(5);
		test_space(6);
	printf("draw_hourglass_rec_helper tests\n");
		test_draw_hourglass_rec_helper(3,0);
		test_draw_hourglass_rec_helper(4,0);
		test_draw_hourglass_rec_helper(5,0);
		test_draw_hourglass_rec_helper(6,0);
	printf("draw_hourglass_rec tests\n");
		test_draw_hourglass_rec(3);
		test_draw_hourglass_rec(4);
		test_draw_hourglass_rec(5);
		test_draw_hourglass_rec(6);
		test_draw_hourglass_rec(10);
	printf("draw_hourglass_itr tests\n");
		test_draw_hourglass_iter(3);
		test_draw_hourglass_iter(4);
		test_draw_hourglass_iter(5);
		test_draw_hourglass_iter(6);
		test_draw_hourglass_iter(7);
		test_draw_hourglass_iter(8);
		test_draw_hourglass_iter(9);
		test_draw_hourglass_iter(10);
}


