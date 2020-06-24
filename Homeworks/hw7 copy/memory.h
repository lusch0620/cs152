#ifndef MEMORY_H
#define MEMORY_H

/* This file contains the structs and function signatures for 
 * memory. A memory structure stores the memory address as 
 * well as the size of a memory slot. It has a constructor 
 * (memory_new), and two comparison functions, so they can be 
 * scored in a sorted data structure either by the memory 
 * address or by memory size. 
 */

typedef struct {
	unsigned int addr;
	unsigned int size;
}memory;

/* memory_new                                                                   
 *   purpose:create a new memory struct, initialze its address and size         
 * inputs:                                                                      
 *   uint addr: the address                                                     
 *   uint size: the size                                                        
 * return value:                                                                
 *    a new memory struct                                                       
 */  
memory* memory_new(unsigned int addr, unsigned int size);

/* memory_free                                                                  
 *   purpose: free the dynamically allocated memory struct                      
 * inputs:                                                                      
 *   void* p: a pointer to the node holding the memory struct                   
 * return values:                                                               
 *   none                                                                       
 */  
void memory_free(void* p);

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
int memory_addr_cmp(const void* x, const void* y);

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
int memory_size_cmp(const void* x, const void* y);

/* memory_print                                                                 
 *   purpoes: print the memory address and size                                 
 * inputs:                                                                      
 *   void *data: a pointer pointing to the memory struct                        
 * return values:                                                               
 *   none, just prints to screen                                                
 */  
void memory_print(void* data);
#endif
