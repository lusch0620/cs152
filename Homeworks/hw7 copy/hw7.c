/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw7.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw7.h"
#include "memory.h"
#include "bst.h"

/* node_search
 * 	purpose: search for the data in a subtree using the given comparison func
 * inputs;
 *	node* root: a pointer pointing to the root of the tree
 * 	void* data: the data to be found in the tree
 *	a comparison function
 * return value:
 *	the first node data  that is found having the data fields equal
 */
void* node_search(node* root, void* data, 
	int (*cmp)(const void* x, const void* y))
{
	
	// if the tree is empty	
	if(root== NULL)
	{
		fprintf(stderr, "The value you are looking for is not in the bst\n");
		return NULL;
		//fprintf(stderr, "not in tree\n");
	}

	int result = cmp(data, root->data);
	// if the tree is not empty
	// if the data is greater than the root go down the right side
	if(result > 0)
	{
		return node_search(root->right, data, cmp);
	}
	// if the data is less than the root go down the left side
	else if(result < 0)
	{
		return node_search(root->left, data, cmp);
	}
	// return the data in the node if they're equal
	else if(result == 0) 
	{
		return root->data;
	}
	return NULL;
}

/* bst_search
 *	purpose: search for a node wih data in a bst
 *.inputs:
 *	bst *b: a pointer pointing to the root of the bst
 *	void *data: the data to be found
 * return value:
 *	the data in the node if found
 */
void* bst_search(bst *b, void* data)
{
		return node_search(b->root, data, b->cmp);
}

/* read_memory_blocks
 *	purpose:takes in a filename and splits the file into memory blocks
 * inputs:
 *	char *filename: a pointer pointing to the file
 *	a comparison function
 * return values:
 *	a pointer to the root of a binary search tree
 */
bst *read_memory_blocks(char *filename, 
	int (*cmp)(const void* x, const void* y))
{
	memory *mem;
	bst *tree;
	tree = bst_new(cmp);

	FILE *fp = fopen(filename, "r");
	
	// if no file was inputted
	if(fp == NULL)
	{
		printf("Could not open file %s for reading\n", filename);
		exit(1);
	}
	// this code was taken from hw6
	char buffer[BUFSIZ];
	// loop through the file and retrieve the data from it
	while(!feof(fp) && (fgets(buffer, 500, fp) != NULL))
	{
		unsigned int address, size;
		char *tmp_s;
		tmp_s = strtok(buffer, " ,\n\r");
		address = atoi(tmp_s);
		tmp_s = strtok(NULL, " ,\n\r");
		size = atoi(tmp_s);
		
		printf("Read in record: %u, %u\n", address, size);

		mem = memory_new(address, size);
		
		bst_insert(tree, mem);
	}
	//fclose(fp);
	
	return tree;
}
