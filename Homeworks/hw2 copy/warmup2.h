#ifndef WARMUP2_H
#define WARMUP2_H

/* print_asterisk_letter
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. The letter can be 'S', 'T', 'U', 'V'.
 * input: 
 *   char letter - the letter to print out
 * output: 
 *   nothing returned, just printed to the screen.
 */
void print_asterisk_letter(char letter);

/* draw_asterisk_rows
 * draws a row with a given amount of asterisks
 * inputs:
 *   unsigned int length - number of asterisks to draw horizontally
 * outputs:
 *   nothing returned, just printed to the scren
 */

void draw_asterisk_rows(unsigned int length);

/* spaces
 * prints out a specific amount of spaces
 * inputs:
 *   unsigned int space_num - number of spaces to print
 * outputs:
 *   nothing returned, just printed to the screen
 */

void spaces (unsigned int space_num);

/* draw_hourglass_rec_helper
 *	draws an hourglass with asterisks, implemented recursively
 * inputs:
 *	uint height - the number of rows to print of the wedge
 * 	uint offset - amount of spaces that should be to the left of this hourglass
 * outputs:
 * 	nothing returend, just printed to the screen
 */
void draw_hourglass_rec_helper(unsigned int height, unsigned int offset);

/* draw_hourglass_rec
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the hourglass
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec(unsigned int height);

/* draw_hourglass_iter
 * draws a hourglass with asterisks. implemented iteratively.
 * inputs:
 *   uint height - the number of rows to print of the hourglass
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_iter(unsigned int height);



#endif



