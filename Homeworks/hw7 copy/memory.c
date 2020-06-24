#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

/* memory_new
 *	purpose:create a new memory struct, initialze its address and size
 * inputs:
 *	uint addr: the address
 *	uint size: the size
 * return value:
 *	 a new memory struct
 */
memory* memory_new(unsigned int addr, unsigned int size){
	memory* m = (memory*)malloc(sizeof(memory));
	m->addr = addr;
	m->size = size;
	return m;
}

/* memory_free
 *	purpose: free the dynamically allocated memory struct
 * inputs:
 *	void* p: a pointer to the node holding the memory struct
 * return values:
 * 	none
 */
void memory_free(void* p){
	memory* m = (memory*)p;
	free(m);
}

/* memory_addr_cmp
 *	purpose: compare two memory variables x and y by address 
 * inputs:
 *	const void* x: a pointer to the first memory block's address
 *	const void* y: a pointer to the second memory block's address
 * return values:
 * 	if x is less than y, return -1
 * 	if x is greater than y, return 1
 * 	if they are equal, return 0
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
 *	purpose:compare two memory variables x and y by size 
 * inputs:
 *	const void *x: a pointer to the first memory block's address
 *	const void *y: a pointer to the second memory block's address
 * return values:
 * 	if x is less than y, return -1
 * 	if x is greater than y, return 1
 * 	if they are equal, return 0
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

/* memory_print
 *	purpoes: print the memory address and size
 * inputs:
 *	void *data: a pointer pointing to the memory struct
 * return values:
 *	none, just prints to screen
 */
void memory_print(void* data){
	if (data == NULL) 
	{
		return;
	}
	memory* m = (memory*)data;
	printf("address: %u, size: %u\n", m->addr, m->size);
}
