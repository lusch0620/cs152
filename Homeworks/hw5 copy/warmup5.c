/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup5.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup5.h"
#include "warmup5_provided.h"

//=======================IMPLEMENTATION OF FUNCTIONS==========================
/* safe_str_concat
 *	purpose: second string is concatenated onto the first safely
 * inputs:
 *	char *str1: a pointer pointing to the first inputted string
 *	char *str2: a pointer pointing to the second inputted string
 * return value
 *	a char pointer to a new string
 */
char *safe_str_concat(char *str1, char *str2)
{
	int length1, length2, i, i_holder;

	// iteratively loop through the string to find the length of the string
	for(length1 = 0; str1[length1] != '\0' ; length1++)
	{
		;
	}
	// iteratively loop through the string to find the length of the string
	for(length2 = 0; str2[length2] != '\0'; length2++)
	{
		;
	}
	printf("length1: %d, length2: %d\n", length1, length2);
	// dynamically allocate memory to an array of the right size
	char *new_str = (char *) malloc((length1 + length2) * sizeof(char));

	// iteratively loop through the new array and store the old str array's
	// chars into the new one
	for(i = 0; i < length1; i++)
	{
		new_str[i] = str1[i];
	}
	i_holder = i;
	// iteratively loop through the new array and store the old str array's
	// chars into the new one
	for(i = 0; i < length2; i++)
	{
		new_str[i_holder] = str2[i];
		i_holder++;
	}
	new_str[length1 + length2] = '\0';
	return new_str;
}

/* make_init_array
 *	purpose: creates a pointer to a structure that holds an array and
 *		    its allocated length
 * input:
 *	none
 * return values:
 *	an int_vector pointer pointing to the struct
 */
int_vector* make_init_array()
{
	int_vector *vPtr;
	vPtr = (int_vector *)malloc(sizeof(int_vector));
	vPtr->allocated_size = 0;
	vPtr->array = NULL;
	return vPtr;
}

/* copy
 *	purpose: a helper function that copies one array into another
 * inputs:
 *	int *arr: the array to be copied
 *	int arr_length: the length of the array to be copied
 *	int *arr_copy: the new array that the old array was copied into
 * return value
 *	none, just changes what was at that pointer
 */
void copy(int *arr, int arr_length, int *arr_copy)
{
	// iteratively loop through each cell in the original array
	for(int i = 0; i < arr_length; i++)
	{
		*(arr_copy + i) = *(arr + i);
	}
}

/* max
 *	purpose: returns the max int between two integers
 * inputs:
 *	int a: the first integer
 *	int b: the second integer
 * return values:
 *	the larger integer
 */
int max(int a, int b)
{
	// if a is greater than b
	if(a > b)
		return a;
	// if b is greater than a
	else
		return b;
}

/* write_value
 *	purpose: allows a person to write into an array
 * inputs:
 *	int_vector *vector: a pointer to the int_vector struct
 *	uint index: the index where the value should be placed
 *	int value: the value to be placed at the specific index
 * return value:
 *	none, the struct just changes
 */
void write_value(int_vector *vector, unsigned int index, int value)
{ 
	int new_length = max(max(index, 2 * vector->allocated_size), 16);

	// if the index requested is larger than the space originally allocated
	if(index > vector->allocated_size)
	{
		int *holder_array;
		holder_array = (int *)malloc(new_length *sizeof(int));
		
		copy(vector->array, vector->allocated_size, holder_array);

		holder_array[index] = value;
		vector->allocated_size = new_length;
		free(vector->array);
		vector->array = holder_array;
	}
	// if the index requested is within the space originally allocated
	else if(index < vector->allocated_size)
	{
		vector->array[index] = value;
	}

}

/* read_value
 *	purpose: reads out the value from an array
 * inputs:
 *	int_vector *vector: a pointer pointing to the int_vector struct
 *	uint index: the index to read out the value from
 * return values:
 *	the integer stored at the specific index
 */
int read_value(int_vector *vector, unsigned int index)
{
	// if the index requested is larger than the allocated size
	if(index >= vector->allocated_size)
	{
		return 0;
	}
	// return the value stored at the array index
	else
	{
		return vector->array[index];
	}

}

/* make_and_init_image
 *	purpose: creates an image given pixels and dimensions
 * inputs:
 *	int height: the height of the resulting image
 *	int width: the width of the resulting image
 *	pixel color: the rgb color
 * return value:
 *	a double pointer storing the information of the image
 */
pixel** make_and_init_image(int height, int width, pixel color)
{
	pixel **two_d_array;

	two_d_array = (pixel **)malloc(height * sizeof(pixel *));
	int i;
	// iteratively loop through the array of pointers
	for(i = 0; i < height; i++)
	{
		two_d_array[i] = (pixel *)malloc(width * sizeof(pixel));
		int j;
		// iteratively loop through the 2D array
		for(j = 0; j < width; j++)
		{
			two_d_array[i][j].red = color.red;
			two_d_array[i][j].green = color.green;
			two_d_array[i][j].blue = color.blue;
		}
	}

	return two_d_array;
}

