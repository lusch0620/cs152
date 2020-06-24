/* Name: Lucius Gao
 *CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw7.h
 */

#ifndef HW7_H
#define HW7_H
#include "bst.h"

void* node_search(node* root, void* data, int (*cmp)(const void* x, const void* y)); 

void* bst_search(bst* b, void* data);

node* node_delete(node* root, void* data, int (*cmp)(const void* x, const void* y));

bst *read_memory_blocks(char *filename, int (*cmp)(const void* x, const void* y));

void bst_delete(bst* b, void* data);
#endif

