/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup5.h
 */

#ifndef WARMUP5_H
#define WARMUP5_H
#include "warmup5_provided.h"
typedef struct{
	unsigned int allocated_size;
	int *array;
} int_vector;

/* safe_str_concat                                                              
 *   purpose: second string is concatenated onto the first safely               
 * inputs:                                                                      
 *   char *str1: a pointer pointing to the first inputted string                
 *   char *str2: a pointer pointing to the second inputted string               
 * return value                                                                 
 *   a char pointer to a new string                                             
 */  
char *safe_str_concat(char *str1, char *str2);

/* print_array
 *	purpose: prints out an integer array
 * inputs:
 *	int array[]: the integer array to be printed out
 *	int length: the length of the array
 * return values
 *	none, just prints to screen
 */
void print_array(int array[], int length); 

/* make_init_array                                                              
 *   purpose: creates a pointer to a structure that holds an array and          
 *            its allocated length                                              
 * input:                                                                       
 *   none                                                                       
 * return values:                                                               
 *   an int_vector pointer pointing to the struct                               
 */   
int_vector* make_init_array();

/* write_value
 *   purpose: allows a person to write into an array
 * inputs:
 *   int_vector *vector: a pointer to the int_vector struct
 *   uint index: the index where the value should be placed
 *   int value: the value to be placed at the specific index
 * return value:
 *   none, the struct just changes
 */
void write_value(int_vector *vector, unsigned int index, int value);

/* read_value                                                                   
 *   purpose: reads out the value from an array                                 
 * inputs:                                                                      
 *   int_vector *vector: a pointer pointing to the int_vector struct            
 *   uint index: the index to read out the value from                           
 * return values:                                                               
 *   the integer stored at the specific index                                   
 */ 
int read_value(int_vector *vector, unsigned int index);

/* make_and_init_image
 *   purpose: creates an image given pixels and dimensions
 * inputs:
 *   int height: the height of the resulting image
 *   int width: the width of the resulting image
 *   pixel color: the rgb color
 * return value:
 *   a double pointer storing the information of the image
 */
pixel** make_and_init_image(int height, int width, pixel color);

#endif
