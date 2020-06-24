/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * my_alloc.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"
#include "llist.h"
#include "memory.h"
#include "my_alloc.h"

/* Global variables
 * By declaring these outside of a function:
 *   Scope: Every function inside of this file may use them. 
 *   		No functions in other files may use them.
 *   Lifetime: They exist for the entire program - they are created
 *		when the program begins and exist until the program
 *		ends.
 */   		

/* This is the tree that holds the available memory. */
bst *avail_mem = NULL;

/* This includes all of the functions for the memory allocator.
 * The last two functions (my_malloc and my_free) are public 
 * functions with prototypes in the header function. The rest of the
 * functions are helper functions only called by my_malloc and 
 * my_free. You must implement these helper functions. If you wish,
 * you may add helper functions we did not define.
 */

/* print_available_memory
 *   purpose: print out all available memory in ascending order by size.
 * inputs:
 *   none
 * return values:
 *   none, just prnits to screen
 */
void print_memory()
{
     bst_inorder_traversal(avail_mem, &memory_print);
}
/* compact_memory
 *
 * Search through all available memory and attempt to merge memory
 * that is stored next to each other.
 * This uses global variable avail_mem, so it does not need any
 * input parameters. Look at the bst functions and memory functions.
 */
 // NOTE: collaborated with peers on the logic for this function
void compact_memory()
{
	bst *address_tree = bst_new(memory_addr_cmp);
	llist *tree_list = create_llist();
	
	void *holder;
	// iterate through avail_mem and create a tree organized by address
	for(holder = bst_iterate(avail_mem); holder != NULL; 
		holder = bst_iterate(NULL))
	{
		bst_insert(address_tree, holder);
	}
	
	// iterate through the address tree and turn it into an inorder list
	for(holder = bst_iterate(address_tree); holder != NULL;
		holder = bst_iterate(NULL))
	{
		insert_tail(tree_list, holder);
	}
	llist_node *n;
	
	//go through the list and merge the memory if we can
	for(n = tree_list->head; n->next != NULL; n = n->next)
	{
		memory *mem = merge_memory((memory *)n->item, (memory*)n->next->item);
		
		if(mem != NULL)
		{
			n->next->item = (void *)mem;
		}
	}

	bst *new_tree = bst_new(better_cmp);
	// recreate a proper BST
	for(n = tree_list->head; n->next != NULL; n = n->next)
	{
		void *temp = n->item;
		bst_insert(new_tree, temp);
	}
	
	bst *avail_mem_holder = avail_mem;
	bst_free(avail_mem_holder);
	avail_mem = new_tree;
	free(new_tree);

}


/* init_alloc
 *	purpose: initializes the data structures. This initializes avail_mem so 
 * 	that, instead of being a NULL pointer, it points to a valid bst
 * 	struct whose root pointer is NULL.
 * inputs:
 *	none
 * return values:
 *	none
 */
void init_alloc()
{
	avail_mem = bst_new(memory_size_cmp);
}

/* actual_alloc_size
 * 	purpose: make num_bytes into a rounded up factor of 8
 * inputs:
 * 	int num_bytes: the number of bytes requested
 * return values:
 *	an integer that is a multiple of 8
 */
int actual_alloc_size(int num_bytes)
{
	// if the number of bytes is out of the bounds of a page
	if(num_bytes < 0 || num_bytes > 4088)
	{
		fprintf(stderr, "ERROR: num_bytes is invalid\n");
		return -1;
	}
	// if number of bytes request is less than 24
	else if(num_bytes < 24)
		return 24;
	// if number of bytes requested is already a factor of 8
	else if(num_bytes % 8 == 0)
		return num_bytes;
	// if the number of bytes is not a factor of 8 and greater than 24
	else
		return(8 * ((num_bytes / 8) + 1));
}

/* size_calc
 * 	purpose: takes care of the restrictions in my_malloc
 * inputs:
 * 	int avail_size: the available size left
 *	int desired_size: how much memory is desired
 * return values:
 *	an integer of the actual size to be allocated
 */
unsigned int size_calc(unsigned int avail_size, unsigned int desired_size)
{
	if(avail_size >= (2* desired_size))
		return desired_size;
	else
		return avail_size;
}

/* my_malloc
 * 	purpose: function that finds a piece of available memory that is at least
 * num_bytes size. A pointer to the beginning of the usable piece of
 * that chunk is returned.
 */
void *my_malloc(int num_bytes)
{
	unsigned int allocate_size = actual_alloc_size(num_bytes);
	void *chunk;
	// print out how much we want and the amount actually allocated
	printf("\t\tNum Bytes: %d Allocate_Size: %d\n", num_bytes, allocate_size);
	
	// check to see if avail_mem is null
	if(avail_mem == NULL)
	{	
		init_alloc();
		memory *m1;
		m1 = allocate_memory_page();
		node *n;
		n = node_new(m1);
		avail_mem->root = n;
	}

	printf("\t\tBefore Call: \n");
	print_memory();
	unsigned int max = UINT_MAX;
	memory *mem = memory_new((void*)(&max), allocate_size);
	chunk = bst_item_or_successor(avail_mem, (void *)mem);
	
	// check to see if the chunk we are looking for is null
	if(chunk == NULL)
	{
		memory *m1 = allocate_memory_page();
		unsigned int size = size_calc(m1->size, allocate_size);
		void *ret_val = split_memory(m1, size);
		printf("\nprint4:");
		print_memory();
		bst_insert(avail_mem, m1);
		printf("\t\tAfter Call:\n");
		print_memory();
		return ret_val;
	}
	// if we found a chunk not null that we can allocate memory to
	else
	{
		memory *mem_chunk = memory_new(((memory *)chunk)->addr,
			((memory *)chunk)->size);
		unsigned int size = size_calc(mem_chunk->size, allocate_size);
		void *ret_val = split_memory(mem_chunk, size);
		bst_delete(avail_mem, chunk);
		bst_insert(avail_mem, (void *)mem_chunk);
	
		printf("\t\tAfter Call:\n");
		print_memory();
		return ret_val;
	
	}
}

/* advance_by_x
 * 	purpose: advance a void pointer by an x amount
 * inputs:
 *	void *v: the pointer to advance
 *	int x: how much to advance the pointer by
 * return values:
 *	none
 */
void* advance_by_x(void *v, int x)
{
	char *pc = (char*)v;
	pc += x;
	return (void*)pc;
}

/* my_free
 * 	purpose: returns the memory chunk whose usable piece starts at that 
 *	address back to the set of available memory so that it can  be reused 
 *	in a subsequent free call
 * inputs:
 *	void *address: a void pointer to the address to be freed
 * return values:
 *	none, just frees the memory at that address
 */
void my_free(void *address)
{
	// check to see if the address is null
	if(address == NULL)
	{
		return;
	}
		
	unsigned int *sz = (unsigned int *)advance_by_x(address, -8);
	unsigned int sz_holder = *sz;
	memory *mem = memory_new(address, sz_holder);
	bst_insert(avail_mem, mem);
	print_memory(avail_mem);
}











 
