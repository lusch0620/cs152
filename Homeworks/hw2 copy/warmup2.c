#include <stdlib.h>
#include <stdio.h>
#include "warmup2.h"

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. The letter can be anything from 'N' to 'R'. 
 */
void print_asterisk_letter(char letter)
{
	//switch statement to decide which case to print out
	switch(letter)
	{
		case('s'):
		case('S'):
		{
			printf(" ****\n*\n ***\n    *\n****\n");
			break;
		}
		case('t'):
		case('T'):
		{
			printf("*****\n  *\n  *\n  *\n  *\n");
			break;
		}
		case('u'):
		case('U'):
		{
			printf("*   *\n*   *\n*   *\n*   *\n ***\n");
			break;
		}
		case('v'):
		case('V'):
		{
			printf("*   *\n*   *\n*   *\n * *\n  *\n");
			break;
		}
			
	}
}


/* draw_astersisk_rows
 * draws a row with a given amount of asterisks
 * inputs:
 *   unsigned int length - number of asterisks to draw
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_asterisk_rows(unsigned int length)
{
	//draws asterisks only if the input is at least 1
	if(length >= 1)
	{
		draw_asterisk_rows(length - 1);
		printf("*");
	}
}

/* spaces
 * prints out a specific amount of spaces
 * inputs:
 *   unsigned int space_num - number of spaces to create
 * ouputs:
 *   nothing returned, just printed to the screen
 */

void spaces(unsigned int space_num)
{	
	//prints spaces if the numbers of spaces desired is at least 1
	if(space_num >= 1)
	{
		spaces(space_num - 1);
		printf(" ");
	}
}



/* draw_hourglass_rec_helper
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 *   uint offset - amount of spaces that should be to the left of this hourglass
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec_helper(unsigned int height, unsigned int offset)
{
	//if the height of the hourglass is odd
	if((height % 2) == 1)
	{	
		//base case
		if(height == 1)
		{
			spaces(offset);
			draw_asterisk_rows(1);
			return;
		}
		//recursively prints out an hourglass of an odd height
		spaces(offset);
		draw_asterisk_rows(height);
		printf("\n");
		//general case
		draw_hourglass_rec_helper(height - 2, offset + 1);
		printf("\n");
		spaces(offset);
		draw_asterisk_rows(height);
	}
	//if the height of the hourglass is even
	else
	{
		//base case
		if(height == 2)
		{
			spaces(offset);
			draw_asterisk_rows(1);
			printf("\n");
			spaces(offset);
			draw_asterisk_rows(1);
			return;
		}
		//recursively prints out an hourglass 
		spaces(offset);
		draw_asterisk_rows(height - 1);
		printf("\n");
		//general case
		draw_hourglass_rec_helper(height - 2, offset + 1);
		printf("\n");
		spaces(offset);
		draw_asterisk_rows(height - 1);
	}
}

/* draw_hourglass_rec
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec(unsigned int height)
{ 
	draw_hourglass_rec_helper(height,0);
}

/* draw_hourglass_iter
 * draws a hourglass with asterisks. Implemented iteratively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_iter(unsigned int height)
{ 
	int i , j = 0, k=height, j_temp,  k_temp,  h = height;
	
	//if the height of the hourglass is odd
	if((height % 2) == 1)
	{
		//iteratively looping through to print the top half
		//of the hourglass
		while(j <= (height / 2))
		{
			k_temp = k;
			
			//iteratively looping to print out spaces
			while((height  - k) != 0)
			{
				printf(" ");
				k++;
			}
			
			//iteratively looping to print asterisks
			for(i = 0; i < h; i++)
			{
				printf("*");	
			}
			printf("\n");
			//variable updates
			j++;
			h =  h - 2;
			k = k_temp - 1;
		}
		//variable update
		h = h + 2;
		
		//iteratively looping through to print the bottom half 
		//of the hourglass
		while((j > (height / 2)) && (j < height))
		{
			k_temp = k;
			h = h + 2;
			
			//iteratively looping to print out spaces
			while((k - 1) != 0)
			{
				printf(" ");
				k--;
			}
			//iteratively looping to print out the asterisks
			for(i = 0; i < h; i++)
			{
				printf("*");
			}
			printf("\n");
			//variable updates
			j++;
			k = k_temp - 1;
		}
	}
	//if the height of the hourglass is even
	else
	{
		//iteratively looping through to print the top half
		//of the hourglass
		while(j < (height / 2))
		{
			k_temp = k;
			
			//iteratively looping to print out the spaces
			while((height - k) != 0)
			{
				printf(" ");
				k++;
			}
			
			//iteratively looping to print out the astierisks
			for(i = 1; i < h; i++)
			{
				printf("*");
			}
			printf("\n");
			//variable updates
			j++;
			h = h - 2;
			k = k_temp - 1;
		}
		//variable update
		h = h + 2;	
		//iteratively looping through to print the bottom half
		//of the hourglass
		while((j >= (height / 2)) && (j < height))
		{
			k_temp = k;
			h = h+2;
			
			//iteratively looping to print out the spaces
			while((k - 1) != 0)
			{
				printf(" ");
				k--;
			}

			//iteratively looping to print out the asterisks
			for(i = 3; i< h; i++)
			{
				printf("*");
			}
			printf("\n");
			//variable update
			j++;
			k = k_temp - 1;
		}
	}
	
}


