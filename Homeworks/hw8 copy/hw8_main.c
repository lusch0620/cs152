/* Name: Lucius Gao
 * CNET: luciusgao2001
 * cs 152, Winter 2020
 * hw8_main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "llist.h"
#include "my_alloc.h"

extern bst* avail_mem;

/* read_memory_blocks
 *	purpose: parses a text file
 * inputs:
 *	char *filename: the filename
 *	bst* tree: initially an empty bst
 *	a compare function to organize the bst by
 * return values:
 *	none, just fills up a bst
 */
void read_memory_blocks(char *filename, bst* tree,
	int (*cmp)(const void* x, const void* y))
{
	memory *mem;

	FILE *fp = fopen(filename, "r");

	//if no file was inputted
	if(fp == NULL)
	{
		printf("Could not open file %s for reading\n", filename);
		exit(1);
	}
	//this code was taken from hw6
	char buffer[BUFSIZ];
	//loop through the file and retrieve the data from it
	while(!feof(fp) && (fgets(buffer, 500, fp) != NULL))
	{
		unsigned int address, size;
		char *tmp_s;
		tmp_s = strtok(buffer, " ,\n\r");
		address = atoi(tmp_s);
		tmp_s = strtok(NULL, " ,\n\r");
		size = atoi(tmp_s);

		printf("Read in record: %u, %u\n", address, size);

		mem = memory_new((void *)address, size);

		bst_insert(tree, mem);
	}
}

/* test_actual_alloc_size
 * 	purpose: test the actual_alloc_size function
 * inputs:
 *	int num_bytes: the number of bytes wanted to be allocated
 *	int expected: a number larger than num_bytes that is also a multiple of 8
 * return values:
 *	1 for success, 0 for failure
 */
unsigned int test_actual_alloc_size(int num_bytes, int expected)
{
	int result = actual_alloc_size(num_bytes);
	
	// if the result is the same as expected
	if(result == expected)
	{
		printf("actual_alloc_size(%d) = %d", num_bytes, result);
		printf(" Success!\n");
		return 1;
	}
	// if the result is not the same as expected
	else
	{
		printf("actual_alloc_size(%d) = %d Expected: %d", num_bytes, 
			result, expected);
		printf(" Failure\n");
		return 0;
	}
}

/* test_bst_iterate
 *	purpose: tests the bst_iterate function
 * inputs:
 *	bst *b: a pointer to the  bst to be iterated through
 * return values:
 * 	none
 */
void test_bst_iterate(bst *b)
{
	void *test;
	// loop through and call bst_iterate to show it works
	for(test = bst_iterate(b); test != NULL; test = bst_iterate(NULL))
		memory_print((memory*)test);
}

/* test_bst_item_or_successor
 *	purpose: test the bst_item_or_successor function
 * inputs:
 * 	bst *b: a pointer pointing to the bst under question
 * 	int size: the size we want
 * return value
 *	none
 */
void test_bst_item_or_successor(bst *b, int size)
{
	memory *m1 = memory_new(size, (unsigned int) size);
	void *chunk = bst_item_or_successor(b, m1);
	if(chunk == NULL)
	{
		printf("Chunk is NULL\n");
	}
	else
	{
		printf("Chunk of memory found is: \n");
		memory_print(chunk);
	}
}

int main()
{

  bst *tree = bst_new(memory_size_cmp); 	



  printf("TESTFILE.TXT VALUES\n");
  	read_memory_blocks("testfile.txt", tree, memory_size_cmp);
	printf("\tOriginal\n\t");
	bst_inorder_traversal(tree, memory_print);
  
  printf("\nACTUAL_ALLOC_SIZE TESTS\n");
    test_actual_alloc_size(1, 24);
    test_actual_alloc_size(27, 32);
    test_actual_alloc_size(43, 48);
  
  printf("\nBST_ITERATE TESTS\n");
    printf("This is an inorder traversal of the inputted tree\n");
    bst_inorder_traversal(tree, &memory_print);
    printf("\n");
    test_bst_iterate(tree);

  printf("\nBST_ITEM_OR_SUCCESSOR TESTS\n");
	test_bst_item_or_successor(tree, 20);
	test_bst_item_or_successor(tree, 4020);
	test_bst_item_or_successor(tree, 4087);
	test_bst_item_or_successor(tree, 5000);
  	
  printf("\nMY_MALLOC TESTS\n");
	char *arr = (char *)my_malloc(40);
		printf("\n\n");		
	char *arr1 = (char *)my_malloc(3000);
		printf("\n\n");
	char *arr2 = (char *)my_malloc(2004);
		printf("\n\n");		
	char *arr3 = (char *)my_malloc(4);
		printf("\n\n");		
	char *arr4 = (char *)my_malloc(1029);
		printf("\n\n");		
	char *arr5 = (char *)my_malloc(3680);
		printf("\n\n");		
	char *arr6 = (char *)my_malloc(2000);
		printf("\n\n");		
	char *arr7 = (char *)my_malloc(1000);
		printf("\n\n");		
	char *arr8 = (char *)my_malloc(0);
		printf("\n\n");		

	arr = "sad";
	arr1 = "I can't do this anymore";
	arr2 = "coronaaaaaa";
	arr3 = "two";
	arr4 = "I got this";
	arr5 = "super duper long string";
	arr6 = "I'm losing brain cells";
	arr7 = "so done";
	arr8 = "twenty four";

  printf("\nMY_FREE TESTS\n");
    my_free(arr);
    my_free(arr1);
    my_free(arr2);
    my_free(arr3);
    my_free(arr4);
    my_free(arr5);
    my_free(arr6);
    my_free(arr7);
    my_free(arr8);
    
  printf("\nCOMPACT_MEMORY TESTS\n");
    compact_memory();

}

