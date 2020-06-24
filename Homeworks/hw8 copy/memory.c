/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * memory.c
 */

#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

/* memory_new
 *   purpose:create a new memory struct, initialze its address and size
 * inputs:
 *   uint addr: the address
 *   uint size: the size
 * return value:
 *    a new memory struct
 */
memory* memory_new(void *addr, unsigned int size)
{
	memory* m = (memory*)malloc(sizeof(memory));
	m->addr = addr;
	m->size = size;
	return m;
}

/* memory_free
 *   purpose: free the dynamically allocated memory struct
 * inputs:
 *   void* p: a pointer to the node holding the memory struct
 * return values:
 *   none
 */
void memory_free(void* p)
{
	memory* m = (memory*)p;
	free(m);
}

/* memory_addr_cmp
 *   purpose: compare two memory variables x and y by address 
 * inputs:
 *   const void* x: a pointer to the first memory block's address
 *   const void* y: a pointer to the second memory block's address
 * return values:
 *   if x is less than y, return -1
 *   if x is greater than y, return 1
 *   if they are equal, return 0
 */
int memory_addr_cmp(const void* x, const void* y)
{
	memory *m1 = (memory *)x;
	memory *m2 = (memory *)y;

	// return 1 if m1 > m2
	if(m1->addr > m2->addr)
	{
		return 1;
	}
	// return -1 if m1 < m2
	else if(m1->addr < m2->addr)
	{
		return -1;
	}
	// return 0 if equal
	else
	{
		return 0;
	}
}

/* memory_size_cmp 
 *   purpose:compare two memory variables x and y by size 
 * inputs:
 *   const void *x: a pointer to the first memory block's address
 *   const void *y: a pointer to the second memory block's address
 * return values:
 *   if x is less than y, return -1
 *   if x is greater than y, return 1
 *   if they are equal, return 0
 */
int memory_size_cmp(const void* x, const void* y)
{
	memory *m1 = (memory *)x;
	memory *m2 = (memory *)y;

	// return 1 if m1 > m2
	if(m1->size > m2->size)
	{
		return 1;
	}
	// return -1 if m1 < m2
	else if(m1->size < m2->size)
	{
		return -1;
	}
	// return 0 if m1 = m2
	else
	{
		return 0;
	}
}

/* better_cmp
 * 	purpose: this compare function is a mixture of memory_size_cmp and
 *	address_size_cmp
 */
int better_cmp(const void* x, const void* y)
{
        int size_cmp = memory_size_cmp(x, y);
        if(size_cmp == 0)
        {
                int addr_cmp = memory_addr_cmp(x,y);
                return addr_cmp;
        }
        return size_cmp;
}

/* memory_print
 *   purpoes: print the memory address and size
 * inputs:
 *   void *data: a pointer pointing to the memory struct
 * return values:
 *   none, just prints to screen
 *
 */
void memory_print(void* data)
{
	// return once there's nothing left to print
	if (data == NULL)
	{
		return;
	}
	memory* m = (memory*)data;
	printf("\taddress: %u, size: %u\n", ((unsigned int)m->addr), m->size);
}


/* allocate_memory_page
 * 	purpose: call malloc to request a page of data - 4096 bytes. Create a 
 *	memory struct and initialize it to store the resulting large chunk of 
 *	data that was allocated
 * inputs:
 *	none
 * return value:
 *	a pointer to the memory struct
 */
memory *allocate_memory_page()
{
	memory *ret_val;
	ret_val= memory_new(malloc(4096),4088);
	return ret_val;
}

/* split_memory
 * 	purpose: given a memory struct and a desire size of memory, perform the
 *	operations necessary to remove the desired size of memory from the end 
 *	of the chunk and record the new information for the smaller chunk
 * inputs:
 * 	memory* data: a memory pointer
 *	uint size_desired: the desired size for the memory
 * return value:
 *	a pointer to the beginning of the chunk you are handing out
 */
void *split_memory(memory* data, unsigned int size_desired)
{
	memory *ret_val;
	ret_val = data;
	
	// check to see if data and data->address are null
	if(data == NULL || data->addr == NULL)
		fprintf(stderr, "ERROR");
	
	char *address = (char *)(data->addr);
	
	// if there's not enough space left to give
	if(data->size < size_desired)
		fprintf(stderr, "Error");
	
	address[data->size - size_desired] = size_desired;
	
	//a corner case where there is just enough for the size desired
	if(data->size == size_desired)
	{
		data->size = 0;
	}
	// if there is enough size left make the necessary adjustments
	else
	{
		data->size = data->size - (size_desired + 8);
	}
	return ((void *)(address[data->size + 16]));
}

/* merge_memory
 *	purpose: given 2 memory structs, check to see if the two can be merged
 * inputs:
 *	memory *first: a pointer to the first memory struct
 *	memory *second: a pointer to the second memory struct
 * return value:
 *	If they can be merged, return a memory struct pointer to a struct
 *	containing the information for a single memory chunk containing the
 *	old two chunks
 *
 *	If they cannot be merged, then return NULL
 * collaborated with peers at harper tutors
 */
memory *merge_memory(memory *first, memory *second)
{
	// if anything is NULL
	if(first == NULL || second == NULL || first->addr == NULL 
	|| second->addr == NULL)
	{
		fprintf(stderr, "error");
		return NULL;
	}
	
	int mem_first_size = first->size;
	int mem_second_size = second->size;

	char* first_addr_holder = (first->addr);
	first_addr_holder = first_addr_holder - 8;
	
	void *first_size = (void*)first_addr_holder;
	printf("original first size:%d\n", *(int*)(first_size));
	first_addr_holder = first_addr_holder + (mem_first_size + 8);
	
	void *mem1_end_addr = (void*)first_addr_holder;
	printf("first address: %d\n", ((int)mem1_end_addr));
	first_addr_holder = first_addr_holder + 8;
	
	void *merge_check = (void*)first_addr_holder;
	void *tmp_second = second->addr;
	
	printf("merge_check address: %d\n", (int)merge_check);
	printf("second address: %d\n\n", ((int)tmp_second));
	
	// if merge_check is the same is tmp_second
	if((int)merge_check == (int)tmp_second)
	{
		free(second);
		first->size = first->size + (mem_second_size + 8);
		*((int*)first_size) = first->size;
		printf("size of resulting memory: %d\n", *((int*)first_size));
		return first;
	}
	// return NULL if else
	else
		return NULL;

}
