/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup4_main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "warmup4.h"
#define ROWS 50
#define COLS 50
int main()
{
	// declare variables
	unsigned int r[ROWS][COLS];
        unsigned int g[ROWS][COLS];
        unsigned int b[ROWS][COLS];
	test_warmup();

/*
	// read in ppm file
	// note that r, g, b, width, length are all out parameters
	// that means we need to declare the variables here and send
	// the locations to the function, as seen below.

	// note that for the warmup, you do not need to read in a png.
	provided_read_png("sample.png",r,g,b,&width,&length);
*/


	// put in arrays
	make_horizontal_stripes(r, g, b, 5, 30, 144, 255, ROWS, COLS);
	// print to html to view
	provided_print_image_to_html("my_horiz_stripes.html",r,g,b,ROWS, COLS);

	// put in arrays
	make_checker_board(r,g,b,5,30,144,255, ROWS, COLS);
	// print to html to view
	provided_print_image_to_html("my_checkboard.html",r,g,b, ROWS, COLS);

}
