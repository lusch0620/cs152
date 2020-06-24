/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw7_main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw7.h"
#include "bst.h"
#include "memory.h"

int main(int argc, char *argv[])
{
	memory *memHolder;
	bst *ogAddrTree, *ogSizeTree, *addr, *size, *dummyTree = NULL;

	ogAddrTree = read_memory_blocks(argv[1], memory_addr_cmp);
	ogSizeTree = read_memory_blocks(argv[1], memory_size_cmp);
	addr = ogAddrTree;
	size = ogSizeTree;


	printf("Address Tree:\n");
	bst_inorder_traversal(ogAddrTree, memory_print);
	printf("Size Tree:\n");
	bst_inorder_traversal(ogSizeTree, memory_print);

	printf("\nBST_INSERT Tests\n");	
		printf("Original Address Tree:\n");
			bst_inorder_traversal(addr, memory_print);
		printf("Original Size Tree:\n");
			bst_inorder_traversal(size, memory_print);
		memHolder = memory_new(12, 34);
			bst_insert(addr, memHolder);
			bst_insert(size, memHolder);
		memHolder = memory_new(72,5894);
			bst_insert(addr, memHolder);
			bst_insert(size, memHolder);
		memHolder = memory_new(74, 9284);
			bst_insert(addr, memHolder);
			bst_insert(size, memHolder);
		printf("New Address Tree:\n");
			bst_inorder_traversal(addr, memory_print);          
		printf("New Size Tree:\n");                                
			bst_inorder_traversal(size, memory_print); 
		// the function call below should just return and 
		// print nothing out
		bst_inorder_traversal(dummyTree, memory_print);
	
	printf("\nBST_DELETE TESTS\n");
		printf("Original Address Tree:\n");
			bst_inorder_traversal(addr, memory_print);
		printf("Original Size Tree:\n");
			bst_inorder_traversal(size, memory_print);
	
		printf("\nNew Address tree after removing (2, 50),"
			" (5, 150), and (12, 34)\n");
			memHolder = memory_new(2, 50);
				bst_delete(addr, memHolder);
			memHolder = memory_new(5, 150);
				bst_delete(addr, memHolder);
			memHolder = memory_new(12, 34);
				bst_delete(addr, memHolder);
			bst_inorder_traversal(addr, memory_print);	
		
		printf("\nNew Size tree after removing (3, 80),"
			"(5, 150), and (72, 5894)\n");
			memHolder = memory_new(3, 80);
				bst_delete(size, memHolder);
			memHolder = memory_new(5, 150);
				bst_delete(size, memHolder);
			memHolder = memory_new(72, 5894);
				bst_delete(size, memHolder);
			bst_inorder_traversal(size, memory_print);	
		
		printf("\nNODE_SEARCH TESTS\n");
			printf("If you look for something not in the bst\n");
				memHolder = memory_new(2, 50);
				memory_print(bst_search(addr, memHolder));
			printf("Search for (3, 80) in addr\n");
				memHolder = memory_new(3, 80);
				memory_print(bst_search(addr, memHolder));
			printf("Search for (72, 5894) in addr\n");
				memHolder = memory_new(72, 5894);
				memory_print(bst_search(addr, memHolder));
			printf("Search for (4, 100) in size\n");
				memHolder = memory_new(4, 100);
				memory_print(bst_search(size, memHolder));
	bst_free(addr);
	bst_free(size);
}
