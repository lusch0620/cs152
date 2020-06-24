/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup5_main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup5.h"
#include "warmup5_provided.h"

/* test_safe_str_concat
 *	purpose: tests the safe_str_concat function
 * inputs:
 *	char *str1: the first string to be concatenated onto
 *	char *str2: the string to concatenate onto the first string
 *	char *expected: the expected safe string
 * return values:
 *	1 for success, 0 for failure
 */
int test_safe_str_concat(char *str1, char *str2, char *expected)
{
	char *answer = safe_str_concat(str1, str2);

	// if everything ran smoothly
	if(strcmp(answer, expected) == 0)
	{
		printf("safe_str_concat(%s, %s): %s Success\n", 
			str1, str2, answer);
		return 1;
	}
	// if the function was written incorrectly
	else
	{
		printf("safe_str_concat(%s, %s): %s Expected: %s FAILURE\n", 
				str1, str2, answer, expected);
		return 0;
	}
}

/* print_array
 *	purpose: prints a given array out
 * inputs:
 *	int array[]: an array of integers
 * return values:
 *	none, just prints to screen
 */
void print_array(int array[], int length)
{
	int i;
	// if the length is 0
	if(length == 0)
	{
		printf("length is 0\n");
	}
	// iteratively loop through and print the array
	for(i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	switch(atoi(argv[1]))
	{
		// safe_str_concat
		case 1:
		{
			switch(atoi(argv[2]))
			{
				case 1:
				{
					printf("\nsafe_str_concat dynamic test\n");
					test_safe_str_concat(argv[3], argv[4], 
							argv[5]);
					printf("\n");
						break;
				}
				case 2:
				{
					printf("\nsafe_str_concat hardcoded test\n");
					char str1[] = "Lucius", str2[] = "Gao";             
					char str3[] = "", str4[] = "space";                  

					test_safe_str_concat(str1, str2, 
							"LuciusGao");                   
					test_safe_str_concat(str3, str4, 
						"space");                       
					test_safe_str_concat(str4, str3, 
						"space"); 				
					printf("\n");
						break;
					}	
			}
			break;
		}
		printf("\n");
		// make_init_array
		case 2:
		{
			printf("\nonly possible make_init_array hardcoded test\n");

			int_vector *vPtr;
			vPtr = make_init_array();
			printf("\nallocated_size: %d\n\n", vPtr->allocated_size);
			break;
		}
		// write_value
		case 3:
		{
			printf("\nwrite_value hardcoded tests\n");
			int_vector *vPtr;
			vPtr = make_init_array();

			print_array(vPtr->array, 
				vPtr->allocated_size);
			write_value(vPtr, 12, 18);
			print_array(vPtr->array, 
				vPtr->allocated_size);
			write_value(vPtr, 24, 56);
			print_array(vPtr->array, 
				vPtr->allocated_size);
			write_value(vPtr, 0, 1);
			print_array(vPtr->array, 
				vPtr->allocated_size);
			printf("\n");
			break;
		}
		// read_value
		case 4:
		{ 
			printf("\nread_value hardcoded tests\n");

			int_vector *vPtr;                                                    
			
			vPtr = make_init_array();                                           
			write_value(vPtr, 12, 18);                                           
			write_value(vPtr, 24, 56);                                          
			write_value(vPtr, 0, 1);                                              

			printf("The value at index 12 is:%d\n", 
					read_value(vPtr, 12));               
			printf("The value at index 24 is: %d\n", 
					read_value(vPtr, 24));              
			printf("The value at index 0 is: %d\n", 
					read_value(vPtr, 0));                
			printf("The value at index 100 returns 0: %d\n", 
					read_value(vPtr, 100)); 
			printf("\n");
			break;
		}
		// make_and_init_image
		case 5:
		{
			printf("\nmake_and_init_image dynamic tests\n");
				
			int width = atoi(argv[2]), height = atoi(argv[3]);                
			pixel color;                                                         
			color.red = atoi(argv[4]);                                           
			color.green = atoi(argv[5]);                                         
			color.blue = atoi(argv[6]);  

			provided_write_png_struct(argv[7], 
				make_and_init_image(height, width, color), 
				width, height);
			printf("refer to the created files\n\n");	
			break;
		}
	}	
}
