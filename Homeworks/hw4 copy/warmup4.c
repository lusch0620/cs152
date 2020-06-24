/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup4.c 
 */

#include <stdio.h>
#include <stdlib.h>
#include "warmup4.h"
#define ROWS 50
#define COLS 50
//========================FUNCTION IMPLEMENTATIONS=============================

/* count_vowels
 * 	purpose: search through str and count the number of vowels.
 * input: 
 *	char *str - a string
 * return value:
 *	int - the number of vowels in the string str
 */
int count_vowels(char *str)
{
	int acc = 0, i = 0;

	printf("%s\n", str);
	// iteratively loop through the array of characters until the special
	// end character
	while(*(str + i) != '\0')
	{	
		// if the char is a lower case or upper case vowel
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
		   str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
		   str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
		   str[i] == 'U')
		{
			acc++;
		}
		i++;
	}
	return acc;
}

/* make_lowercase
 * modify str such that all alphabetic characters are lower case
 * input: char *str - a string
 * output: no return value - str is out parameter
 */
void make_lowercase(char *str)
{
	int i = 0;

	// iteratively loop through the string until the special
	// end character
	while(str[i] != '\0')
	{
		// change to upper case if the current value is lowercase
		if(str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}

/* make_horizontal_stripes
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains black and colored stripes. All stripes are
 *   stripe_height. The stripe colors are indicated by stripe_color.
 *   The top stripe is colored. The image is heightxwidth.
 * inputs:
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int stripe_height,  - height of a single stripe
 *   unsigned int stripe_red,  - red component of stripe pixel
 *   unsigned int stripe_green,  - green component of stripe pixel
 *   unsigned int stripe_blue,  - blue component of stripe pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * return value:
 * 	none, just changes the arrays
 */
void make_horizontal_stripes(unsigned int red[ROWS][COLS], 
	unsigned int green[ROWS][COLS], unsigned int blue[ROWS][COLS],
	unsigned int stripe_height, unsigned int stripe_red, 
	unsigned int stripe_green, unsigned int stripe_blue, 
	unsigned int width,unsigned int height)
{
	int i = 0, j = 0, num_blocks, b_counter, i_holder = 0;
	int holder;
	
	// decides how many lines to print out based on whether to total 
	// number of lines is evenly divisible by stripe_height
	if(height % stripe_height == 0)
	{
		num_blocks = (height / stripe_height);
	}
	// the remaining case
	else
	{
		num_blocks = (height / stripe_height) + 1;
	}

	// print an error if parameters are incorrect
	if(width > COLS || height > ROWS)
	{
		fprintf(stderr, "ERROR\n");
	}
	// print an all black screen if stripe_height is 0
	else if(stripe_height == 0)
	{
		// iteratively loop through each row
		for(i = 0; i < ROWS; i++)
		{
			// iteratively loop through each column of each row
			for(j = 0; j < COLS; j++)
			{
				red[i][j] = 0;
				green[i][j] = 0;
				blue[i][j] = 0;
			}
		}	
	}
	// print the board if all parameters are valid
	else
	{
		// iteratively loops through the number of lines to print
		for(b_counter = 0; b_counter < num_blocks; b_counter++)
		{	
			// if the line is even and it is not the last line
			if(b_counter % 2 == 0 && b_counter != num_blocks - 1)
			{	
				// iteratively loop through the rows within 
				// the line
				for(i = 0; i < stripe_height; i++)
				{
					// iteratively loop through the columns
					// of each row in each line
					for(j = 0; j < COLS; j++)
					{
						red[i_holder][j]=stripe_red;
						green[i_holder][j]=stripe_green;
						blue[i_holder][j]=stripe_blue;

					}
					i_holder++;
				}
				holder = i_holder;
			}
			// if the line is odd and it is not the last line
			else if(b_counter % 2 == 1 && 
				b_counter != num_blocks - 1)
			{
				// iteratively loop through the rows within
				// each line
				for(i = 0; i < stripe_height; i++)
				{
					// iteratively loop through the columns
					// of each row in each line
					for(j = 0; j < COLS; j++)
					{
						red[i_holder][j] = 0;
						green[i_holder][j] = 0;
						blue[i_holder][j] = 0;
					}
					i_holder++;
				}
				holder = i_holder;
			}
			// if the line is even and it is the last line
			else if(b_counter % 2 == 0 &&
				b_counter == num_blocks - 1)
			{
				// iteratively loop through the remaining rows
				for(i = 0; i < height - holder;i++)
				{
					// iteratively loop through each column
					// of each remaining row in the last
					// line
					for(j = 0; j < COLS; j++)
					{
						red[i_holder][j]=stripe_red;
						green[i_holder][j]=stripe_green;
						blue[i_holder][j]=stripe_blue;
					}
					i_holder++;
				}
			}
			// if the line is odd and it is the last line
			else
			{
				// iteratiely loop through the remaining rows
				for(i = 0; i < height - holder; i++)                                                   
				{                                         
					// iteratively loop through each column
					// of each remaining row in the last
					// line
					for(j = 0; j < COLS; j++)                              
					{                                                      
						red[i_holder][j] = 0;                    
						green[i_holder][j] = 0;                
						blue[i_holder][j] = 0;                  
					}                                                      
					i_holder++;                                            
				}
			}
		}
	}
}

/* make_checker_board
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains white and colored squares. All squares are
 *   square_width x square_width. The square colors are indicated by
 *   square_color. The image is heightxwidth. The top-left square is colored.
 * inputs:
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int square_width,  - height of a single square
 *   unsigned int square_red,  - red component of square pixel
 *   unsigned int square_green,  - green component of square pixel
 *   unsigned int square_blue,  - blue component of square pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * return value:
 *	none, just changes the arrays
 */
void make_checker_board(unsigned int red[ROWS][COLS],
	unsigned int green[ROWS][COLS], unsigned int blue[ROWS][COLS],
	unsigned int square_width, unsigned int square_red,
	unsigned int square_green,unsigned int square_blue, unsigned int width,
	unsigned int height)
{
	int i = 0, j = 0, b_counter = 0, c_counter = 0, num_blocks;
	int i_holder = 0,  j_holder = 0;
	
	// decides the number of lines to be drawn if height is evenly 
	// divided by square_width
	if(height % square_width == 0)                                            
	{                                                                          
		num_blocks = (height / square_width);                                
	}                         
	// decides the number of lines to be drawn if height is not evenly
	// divided by square width
	else                                                                       
	{                                                                          
		num_blocks = (height / square_width) + 1;                            
	}                                                                          
	
	// print an error if the inputs are invalid
	if(width > COLS || height > ROWS)                                          
	{                                                                          
		fprintf(stderr, "ERROR\n");                                           
	}                 
	// print an all white screen if square_width is 0
	else if(square_width == 0)                                                
	{                                                
		// iteratively loop through the rows of each array
		for(i = 0; i < ROWS; i++)                                             
		{                                                 
			// iteratively loop through each column of each row
			// of each array
			for(j = 0; j < COLS; j++)                                        
			{                                                                
				red[i][j] = 255;                                              
				green[i][j] = 255;                                            
				blue[i][j] = 255;                                             
			}                                                                
		}                                                                     
	}                               
	// if all the inputs are valid change the arrays
	else 
	{
		// iteratively loop through each line to be printed
		for(b_counter = 0; b_counter < num_blocks; b_counter++)
		{
			// if the line is even
			if(b_counter % 2 == 0)
			{
				// iteratively loop through each row
				for(i = 0; i < square_width; i++)
				{
					// iteratively loop through each 
					// column block of each line 
					for(c_counter = 0;
					    c_counter < num_blocks; 
				    	    c_counter++)
					{
						// if the column block is
						// even
						if(c_counter % 2 == 0)
						{	
							// iteratively loop
							// through each
							// row in each
							// block
							for(j = 0;
							    j < square_width;
							    j++)
							{
								red[i_holder][j_holder] = square_red;
								green[i_holder][j_holder] = square_green;
								blue[i_holder][j_holder] = square_blue;
								j_holder++;
							}
						}
						// if the column block is 
						// odd
						else
						{
							// iteratively loop
							// through each
							// row in each block
							for(j = 0; 
							    j < square_width;
							    j++)
							{
								red[i_holder][j_holder] = 0;
								green[i_holder][j_holder] = 0;
								blue[i_holder][j_holder] = 0;
								j_holder++;
							}
						}
					}
					i_holder++;
					j_holder = 0;
				}
			}
			// else if the line is odd
			else
			{
				// iteratively loop through each row
				for(i = 0; i < square_width; i++)
				{
					// iteratively loop through each 
					// column block of each line
					for(c_counter = 0; 
					    c_counter < num_blocks;
					    c_counter++)
					{
						// if the column block is even
						if(c_counter % 2 == 0)
						{
							// iteratively loop
							// through each
							// row in each block
							for(j = 0;
							    j < square_width;
							    j++)
							{
								red[i_holder][j_holder] = 0;
								green[i_holder][j_holder] = 0;
								blue[i_holder][j_holder] = 0;
								j_holder++;
							}
						}
						// if the column block is odd
						else
						{
							// iteratively loop 
							// through each row
							// in each block
							for(j = 0; 
							    j < square_width;
							    j++)
							{
								red[i_holder][j_holder] = square_red;
								green[i_holder][j_holder] = square_green;
								blue[i_holder][j_holder] = square_blue;
								j_holder++;
							}
						}
					}
					i_holder++;
					j_holder = 0;
				}

			}
		}
	}
}

//=========================FUNCTION TESTS=====================================
/* print_array
 *	purpose: prints a 2D array
 * inputs:
 *	array[ROWS][COLS]: the array to print out
 * return value:
 *	none, just prints to screen
 */
void print_array(unsigned int array[ROWS][COLS])
{
	int i, j;
	// iteratively loop through each row of the array
	for(i = 0; i < ROWS; i++)
	{
		printf("\n");
		// iteratively loop through each column of each row
		for(j = 0; j < COLS; j++)
		{
			printf("%d ", array[i][j]);
		}
	}
}

/* test_count_vowels
 * 	purpose: tests the count_vowels function
 * inputs:
 *	char *str - the string
 *	uint expected - the expected return value
 * return value
 *	unsigned int - 1 for success 0 for failure
 */
unsigned int test_count_vowels(char *str, unsigned int expected)
{
	unsigned int answer = count_vowels(str);

	// if the answer is what was expected
	if(answer == expected)
	{
		printf("count_vowels(string): %d Success\n", answer);
		return 1;
	}
	// if the answer is not what was expected
	else
	{
		printf("count_vowels(string): %d Expected: %d FAILURE\n", 
				answer, expected);
		return 0;
	}
}

/* test_make_lowercase
 *	purpose: tests the make_lowercase function
 * inputs:
 * 	int *str - a pointer to the string
 * return values:
 *	changes the string and prints the string with its new values
 */
void test_make_lowercase(char *str)
{
	make_lowercase(str);
	printf("%s\n", str);
}

/* test_make_horizontal_stripes
 *	purpose: tests the make_horizontal stripes function
 * inputs:
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int stripe_height,  - height of a single stripe
 *   unsigned int stripe_red,  - red component of stripe pixel
 *   unsigned int stripe_green,  - green component of stripe pixel
 *   unsigned int stripe_blue,  - blue component of stripe pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * return value:
 * 	none
 */
void test_make_horizontal_stripes(unsigned int red[ROWS][COLS],                      
	unsigned int green[ROWS][COLS], unsigned int blue[ROWS][COLS],             
	unsigned int stripe_height, unsigned int stripe_red,                       
	unsigned int stripe_green, unsigned int stripe_blue, 
	unsigned int width, unsigned int height)                                                       
{                                                                               
	make_horizontal_stripes(red, green, blue, stripe_height, stripe_red,
			stripe_green, stripe_blue, width, height);

}  

/* test_warmup
 *	purpose: tests all the functions in the warmup
 * inputs: 
 *	technically no inputs, but it holds all of the functions
 * return value:
 * 	just prints to screen
 */
void test_warmup()
{
	char string1[] = "Hello";
	char string2[] = "Lucius";
	char string3[] = "sesquipedalian";
	char string4[] = "sO mAnY cApS";
	char str1[] = {'H', 'o','w','d','y',' ', 'T','H','E','R','E','!','\0'};
	unsigned int red_array[ROWS][COLS], green_array[ROWS][COLS];
	unsigned int blue_array[ROWS][COLS];


	printf("TESTS\n");
	printf("\ncount_vowels tests:\n");
		test_count_vowels(&str1, 3);
		test_count_vowels(&string1, 2);
		test_count_vowels(&string2, 3);
		test_count_vowels(&string3, 7);
		test_count_vowels(&string4, 3);
	printf("\nmake_lowercase tests:\n");
		printf("Original:%s\nNew:", str1);
			test_make_lowercase(&str1);
		printf("Original:%s\nNew:", string1);
			test_make_lowercase(&string1);
		printf("Original:%s\nNew:", string2);	
			test_make_lowercase(&string2);
		printf("Original:%s\nNew:", string3);
			test_make_lowercase(&string3);
		printf("Original:%s\nNew:", string4);
			test_make_lowercase(&string4);
	printf("\nmake_horizontal_stripes tests:\n");
		test_make_horizontal_stripes(red_array, green_array, 
			blue_array, 5, 1, 2, 3, ROWS, COLS);
		print_array(red_array);
		printf("\n\n\n");
		print_array(green_array);
		printf("\n\n\n");
		print_array(blue_array);
		printf("\n");			
	printf("\nmake_checker_board tests:\n");
		make_checker_board(red_array, green_array, blue_array, 
			5, 1, 2, 3, ROWS, COLS);
		print_array(red_array);
		printf("\n\n\n");
		print_array(green_array);
		printf("\n\n\n");
		print_array(blue_array);
		printf("\n");
}

