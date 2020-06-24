/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw4.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"
#include "hw4_provided.h"
#define ROWS 50
#define COLS 50
//==========================FUNCTIONS=========================================
/* hide_image
 * 	purpose: encodes an image inside of another image using their array of 
 *		    pixels
 * inputs:
 *	uint ref_r[ROWS][COLS]: reference image's array of red values
 *	uint ref_g[ROWS][COLS]: reference image's array of green values
 *	uint ref_b[ROWS][COLS]: reference image's array of blue values
 *	uint hid_r[ROWS][COLS]: hidden image's arrray of red values
 *	uint hid_g[ROWS][COLS]: hidden image's array of blue values
 *	uint hid_b[ROWS][COLS]: hidden image's array of green values
 *	uint res_r[ROWS][COLS]: resulting image's array of red values
 * 	uint res_g[ROWS][COLS]: resulting image's array of green values
 *	uint res_b[ROWS][COLS]: resulting image's array of blue values
 *	uint height: the height of the image
 *	uint width: the width of the image
 * return values:
 *	all of the resulting arrays
 */

void hide_image(unsigned int ref_r[ROWS][COLS], unsigned int ref_g[ROWS][COLS],
	unsigned int ref_b[ROWS][COLS], unsigned int hid_r[ROWS][COLS],
	unsigned int hid_g[ROWS][COLS], unsigned int hid_b[ROWS][COLS],
	unsigned int res_r[ROWS][COLS], unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS], unsigned int height, unsigned int width)
{
	int i, j;
	
	// return an error if the parameters are invalid
	if(height > ROWS ||width > COLS)
	{
		fprintf(stderr, "ERROR\n");
		return;
	}
	// iteratively loop through each row of the array
	for(i = 0; i < ROWS; i++)
	{
		// iteratively loop through each column of each row
		for(j = 0; j < ROWS; j++)
		{
			// if the hidden red is greater than or equal to 128
			// and the reference red is even
			if(hid_r[i][j] >= 128 && ref_r[i][j] % 2 == 0) 
			{
				res_r[i][j] = ref_r[i][j] + 1;
			}
			// if the hidden red is less than 128 and the 
			// reference image is odd
			else if(hid_r[i][j] < 128 && ref_r[i][j] % 2 == 1)
			{
				res_r[i][j] = ref_r[i][j] - 1;
			}
			// the cases for red where no change should be made
			else
			{
				res_r[i][j] = ref_r[i][j];
			}
			// if the hidden green is greater than or equal to 128
			// and the reference green is even
			if(hid_g[i][j] >= 128 && ref_g[i][j] % 2 == 0)
			{
				res_g[i][j] = ref_g[i][j] + 1;
			}
			// if the hidden green is less than 128 and the
			// reference image is odd
			else if(hid_g[i][j] < 128 && ref_g[i][j] % 2 == 1)
			{
				res_g[i][j] = ref_g[i][j] - 1;	
			}
			// the cases for red where no change should be made
			else
			{
				res_g[i][j] = ref_g[i][j];
			}
			// if the hidden blue is greater than or equal to 128
			// and the reference blue is even
			if(hid_b[i][j] >= 128 && ref_b[i][j] % 2 == 0)
			{
				res_b[i][j] = ref_b[i][j] + 1;
			}
			// if the hidden blue is less than 128 and the 
			// reference image is odd
			else if(hid_b[i][j] < 128 && ref_b[i][j] % 2 == 1)
			{
				res_b[i][j] = ref_b[i][j] - 1;
			}
			// the cases for blue where no change should be made
			else
			{
				res_b[i][j] = ref_b[i][j];
			}
		}
	}
}

/* extract_image
 *	purpose: decode an image and extract the hidden image
 * inputs:
 *   uint res_r[ROWS][COLS]: resulting image's array of red values
 *   uint res_g[ROWS][COLS]: resulting image's array of green values
 *   uint res_b[ROWS][COLS]: resulting image's array of blue values
 *   uint hid_r[ROWS][COLS]: hidden image's arrray of red values
 *   uint hid_g[ROWS][COLS]: hidden image's array of blue values
 *   uint hid_b[ROWS][COLS]: hidden image's array of green values
 * return values:
 * 	none, changes the hidden arrays
 */
void extract_image(unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], unsigned int res_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], unsigned int height,
	unsigned int width)
{
	int i , j;
	
	// raise an error if the parameters are incorrect
	if(height > ROWS || width > COLS)
	{
		fprintf(stderr, "ERROR\n");
		return;
	}
	
	// iteratively loop through each row
	for(i = 0; i < ROWS; i++)
	{
		// iteratively loop through each column
		for(j = 0; j < COLS; j++)
		{
			// if res_r is odd change to white
			if(res_r[i][j] % 2 == 1)
			{
				hid_r[i][j] = 255;
			}
			// if res_r is even change to black
			else
			{
				hid_r[i][j] = 0;
			}
			// if res_g is oodd change to white
			if(res_g[i][j] % 2 == 1)
			{
				hid_g[i][j] = 255;
			}
			// if res_g is even change to black
			else
			{
				hid_g[i][j] = 0;
			}
			// if res_b is odd change to white
			if(res_b[i][j] % 2 == 1)
			{
				hid_b[i][j] = 255;
			}
			// if res_b is even change to black
			else
			{
				hid_b[i][j] = 0;
			}
		}
	}

}

/* encode
 *	purpose; encode an image into a another image
 * inputs:
 *	char *ref_filename: the reference picture to hide the image into
 *	char *hid_filename: the picture to be hidden into the reference picture
 *	char *enc_filename: the resulting encoded image
 * return value:
 *	none, just creates a new encoded png file
 */
void encode(char *ref_filename, char *hid_filename, char *enc_filename)
{
	unsigned int ref_r[ROWS][COLS], ref_g[ROWS][COLS], ref_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS], res_g[ROWS][COLS], res_b[ROWS][COLS];
	unsigned int hid_r[ROWS][COLS], hid_g[ROWS][COLS], hid_b[ROWS][COLS];
	unsigned int ref_width, ref_length, hid_width, hid_length
	
	// checks to see if the dimensions are the same return an error if not
	if(ref_width == hid_width && ref_length == hid_length)
	{
		provided_read_png(ref_filename, ref_r, ref_g, ref_b, 
			          &width, &length);
	
		provided_read_png(hid_filename, hid_r, hid_g, hid_b, 
		                  &width, &length);

		hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, 
		           res_g, res_b, width, length); 
	
		provided_write_png(enc_filename, res_r, res_g, res_b, 
			           width, length);
	}
	else
	{
		fprintf(stderr, "ERROR\n");
		return;
	}

}

/* decode
 *	purpose: decode a given image to reveal the hidden image
 * inputs:
 * 	char *enc_filename: the image with a hidden image inside of it
 *	char *hid_filename: the decoded hidden image
 * return value:
 *	none, just creates a new file of the decoded hidden image
 */
void decode(char *enc_filename, char *hid_filename)
{
	unsigned int ref_r[ROWS][COLS], ref_g[ROWS][COLS], ref_b[ROWS][COLS];
	unsigned int hid_r[ROWS][COLS], hid_g[ROWS][COLS], hid_b[ROWS][COLS];
	unsigned width, length;

	provided_read_png(enc_filename, ref_r, ref_g, ref_b, &width, &length);
	
	extract_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, width, length);

	provided_write_png(hid_filename, hid_r, hid_g, hid_b, width, length);

}
//=========================TEST FUNCTIONS=====================================
/* print_array
 *	purpose: prints a given 2D array
 * inputs:
 *	unsigned int array[ROWS][COLS]: the array to print out
 * return values:
 *	none, just prints to screen
 */
void print_array(unsigned int array[ROWS][COLS])
{
	int i , j;
	
	// iteratively loops through each row
	for(i = 0; i< ROWS; i++)
	{
		printf("\n");
		// iteratively loops through each column of each row
		for(j = 0; j < COLS; j++)
		{
			printf("%d ", array[i][j]);
		}
	}
}

/* test_hide_image
 *	purpose: tests the hide_image function
 * inputs:
 *	uint ref_r[ROWS][COLS]: reference image's array of red values
 *	uint ref_g[ROWS][COLS]: reference image's array of green values
 *	uint ref_b[ROWS][COLS]: reference image's array of blue values
 *	uint hid_r[ROWS][COLS]: hidden image's arrray of red values
 *	uint hid_g[ROWS][COLS]: hidden image's array of blue values
 *	uint hid_b[ROWS][COLS]: hidden image's array of green values
 *	uint res_r[ROWS][COLS]: resulting image's array of red values
 * 	uint res_g[ROWS][COLS]: resulting image's array of green values
 *	uint res_b[ROWS][COLS]: resulting image's array of blue values
 *	uint height: the height of the image
 *	uint width: the width of the image
 * return values:
 *	all of the resulting arrays
 */
void test_hide_image(unsigned int ref_r[ROWS][COLS], 
	unsigned int ref_g[ROWS][COLS],unsigned int ref_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS],unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS],unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS],unsigned int res_b[ROWS][COLS], 
	unsigned int height, unsigned int width)
{
	hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, 
		res_b, height, width);
}
/* test_extract_image                                                                
 *   purpose: tests the extract_image function                      
 * inputs:                                                                      
 *   uint res_r[ROWS][COLS]: resulting image's array of red values              
 *   uint res_g[ROWS][COLS]: resulting image's array of green values            
 *   uint res_b[ROWS][COLS]: resulting image's array of blue values             
 *   uint hid_r[ROWS][COLS]: hidden image's arrray of red values                
 *   uint hid_g[ROWS][COLS]: hidden image's array of blue values                
 *   uint hid_b[ROWS][COLS]: hidden image's array of green values               
 * return values:                                                               
 *   none, changes the hidden arrays                                            
 */  
void test_extract_image(unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], unsigned int res_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], unsigned int height,
	unsigned int width)
{
	extract_image(res_r, res_g, res_b, hid_r, hid_g, hid_b, height, width);
}

/* test_hw4
 *	purpose: tests all the functions written in hw4
 * inputs:
 *	none
 * retrn values:
 *	none
 */ 
void test_hw4()
{
	unsigned int ref_r[ROWS][COLS], ref_g[ROWS][COLS], ref_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS], res_g[ROWS][COLS], res_b[ROWS][COLS];
	unsigned int hid_r[ROWS][COLS], hid_g[ROWS][COLS], hid_b[ROWS][COLS];
	unsigned int ref_image_width, ref_image_length;
	unsigned int hid_image_width, hid_image_length;

	// The test here is to see every step of encoding
	provided_read_png("happyface.png", ref_r, ref_g, ref_b, 
				   &ref_image_width, &ref_image_length);
	
	printf("REF_R\n");
	print_array(ref_r);
		printf("\nREF_G\n");
	print_array(ref_g);
		printf("\nREF_B\n");
	print_array(ref_b);
		printf("\n");
	
	provided_read_png("uchicago.png", hid_r, hid_g, hid_b, 
			        &hid_image_width, &hid_image_length);
	
	printf("HID_R\n");
	print_array(ref_r);
		printf("\nHID_G\n");
	print_array(ref_g);
		printf("\nHID_B\n");
	print_array(ref_b);
		printf("\n");

	hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, 
		   res_b,ref_image_width, ref_image_length);

	printf("ref_r[24][34]: %d\tref_g[24][34]: %d\tref_b[24][34]: %d\n"
		  "hid_r[24][34]: %d\thid_g[24][34]: %d\thid_b[24][34]: %d\n"
		  "res_r[24][34]: %d\tres_r[24][34]: %d\tres_b[24][34]: %d\n", 
		  ref_r[24][34], ref_g[24][34], ref_b[24][34], hid_r[24][34], 
		  hid_g[24][34], hid_b[24][34], res_r[24][34], res_g[24][34], 
		  res_b[24][34]);

	encode("happyface.png", "uchicago.png", "uchicago_into_happyface.png");
	
	encode("uchicago.png", "happyface.png", "happyface_into_uchicago.png");

	// Tests to make sure that encode and decode both work correctly
	decode("uchicago_into_happyface.png", "decoded1.png");

	decode("happyface_into_uchicago.png", "decoded2.png");

}





































