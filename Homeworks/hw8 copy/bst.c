/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * bst.c
 */
#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "llist.h"
#include "memory.h"
#include "my_alloc.h"

/* node_new:
 *      purpose: malloc a new node and assign the data pointer to its data field
 * inputs:
 *      void *data: a void pointer pointing to the input
 * return:
 *      a pointer pointing to the node;
 */
node* node_new(void* data)
{
	node *nPtr = NULL;

	nPtr = (node *)malloc(sizeof(node));

	nPtr->data = data;
	nPtr->left = NULL;
	nPtr->right = NULL;

	return nPtr;
}

/* bst_new:
 *      Purpose: create a new bst, initialize its root to be NULL
 * inputs:
 *      int (*cmp)(const void* x, const void* y) a pointer to a comparing
 *              function
 * return value:
 *      a bst pointer 
 */
bst* bst_new(int (*cmp)(const void* x, const void* y))
{
	bst *bstPtr = NULL;

	bstPtr = (bst *)malloc(sizeof(bst));

	bstPtr->root = NULL;
	bstPtr->cmp = cmp;

	return bstPtr;
}

/* node_insert:
 *      purpose: Insert a node to to a subtree with a root node as parameter
 *              Insertion is in sorted order. 
 * inputs:
 *      node *root: a pointer pointing to the root of the tree
 *      void *data: a new value to be added into the tree
 *      comparison function: a function that compares the data with the data
 *              already in the tree
 * return value:
 *      the new root of the modified subtree.  
 */
node* node_insert(node* root, void* data,
		int (*cmp)(const void* x, const void* y))
{
	// check to see if the root is NULL
	if(root == NULL)
	{
		return node_new(data);
	}
	// if the data we are inserting is greater than the current root
	else if(cmp(data, root->data) > 0)
	{
		root->right = node_insert(root->right, data, cmp);
	}
	// if the data we are inserting is less than the current root
	else if(cmp(data, root->data) <= 0)
	{
		root->left = node_insert(root->left, data, cmp);
	}

	return root;
}

/* bst_insert:
 *      purpose: insert a new node to the bst
 * inputs:
 *      bst* b: a pointer to the root of the bst
 *      void *data: a node holding data to be inserted into the bst
 * return value:
 *      none, just changes the bst
 */
void bst_insert(bst* b, void* data)
{
	b->root = node_insert(b->root, data, b->cmp);
}

/* tree_min
 *      purpose: finds the predecessor to replace the removed node with
 * inputs;
 *      node* root: a pointer to the head of the bst
 * return value:
 *      the minimum value in the whole bst
 */
node *tree_min(node *root)
{
	node *holder;
	holder = root;
	
	// iterate through the tree and find the successor
	for(holder = root; holder != NULL && holder->left != NULL; 
		holder = holder->left)
		;

	return holder;

}


/* node_delete:
 *      purpose: delete a node from a subtree with a given root node the 
 *      comparison function to search the node and delete it when a matching
 *      node is found. This function only deletes the first occurrence of the
 *      node, i.e, if multiple nodes contain the data we are looking for, only
 *      the first node we found is deleted. 
 * inputs:
 *      node* root: a pointer pointing to the root node
 *      void* data: the data in the node
 *      a comparison function
 * return value:
 *       the new root node after deletion.
 */
node* node_delete(node* root, void* data,
		int (*cmp)(const void* x, const void* y))
{
	node *to_delete;

	// check to see if the bst is empty
	if(root == NULL)
	{
		return root;
	}

	// if data is bigger than the current node data
	if(cmp(data, root->data) > 0)
	{
		root->right = node_delete(root->right, data, cmp);
	}
	// go down the left side of the tree if data is smaller than
	// the root
	else if(cmp(data, root->data) < 0)
	{
		root->left = node_delete(root->left, data, cmp);
	}
	// what happens once we find the node to delete
	else
	{
		// if we are dealing with a leaf
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return root;
		}
		// if only the left side of a node is empty
		else if(root->left == NULL)
		{
			free(root);
			root = root->right;

			root->right = node_delete(root->right, root->data, cmp);

		}
		// if only the right side of a node is empty
		else if(root->right == NULL)
		{
			free(root);
			root = root->left;
			root->left = node_delete(root->left, root->data, cmp);
		}
		// if we are dealing with a full node
		else
		{
			to_delete = tree_min(root->right);

			root->data = to_delete->data;
			root->right = node_delete(root->right, 
				to_delete->data, cmp);
			free(to_delete);
		}
	}
	return root;
}

/* bst_delete: 
 *	purpose: delete a node containing data from the bst
 * inputs: 
 *      bst* b: a pointer pointing to the root of the bst
 *      void *data: the data value in the bst to be deleted
 * return value:
 *      none
 */
void bst_delete(bst* b, void* data)
{
	b->root = node_delete(b->root, data, b->cmp);
}

/* inorder_traversal
 *      purpose: traverse a subtree with root in ascending order, apply func 
 *              to the data of each node. 
 * inputs:
 *      node *root: a pointer to the head of the bst
 *      a function to be applied to the bst
 * return values:
 *      none, just applies to function to the 
 */
void inorder_traversal(node* root, void(*func)(void* data))
{
	// if the bst is empty
	if(root == NULL)
	{
		return;
	}
	// apply the function to every node
	else
	{
		inorder_traversal(root->left, func);
		func(root->data);
		inorder_traversal(root->right, func);
	}
}

/* bst_inorder_traversal
 *      purpose:traverse a bst in ascending order.apply func to 
 *              the data of each node. 
 * inputs:
 *      bst* b: a pointer to the root of the bst
 *      a function to be appleid to the bst
 * return values:
 *      none, just applies to function to the BST
 */
void bst_inorder_traversal(bst* b, void(*func)(void* data))
{
	// check to see if the bst is empty
	if(b == NULL)
	{
		return;
	}
	// apply the function to the bst
	else
	{
		inorder_traversal(b->root, func);
	}
}

/* node_free
 *	purpose: free a node
 * inputs:
 *	node *n: the root node to start freeing at
 * return values:
 *	none
 */
void node_free(node *n)
{
	// return once n is NULL
	if(n == NULL)
	{
		return;
	}

	node_free(n->right);
	node_free(n->left);
	free(n->data);
	free(n);
}
/* bst_free
 *      purpose:free the bst with 
 * inputs:
 *      bst* b: the root of the bst to be freed
 * return values:
 *      none, just frees the bst
 */
void bst_free(bst* b)
{
	node_free(b->root);
	free(b);
}

/* inorder_traversal_insert_llist
 *	purpose: take a bst and create an inorder linked list out of it
 * inputs:
 *	node *root: the head of the tree
 *	llist *l: an empty list 
 * return values:
 *	no explicit return value, but the list is full 
 */
void inorder_traversal_insert_llist(node* root, llist* l)
{
	// return if root is null
	if(root == NULL)
		return;
	
	inorder_traversal_insert_llist(root->left, l);
	insert_tail(l, root->data);
	inorder_traversal_insert_llist(root->right, l);
}

/* bst_iterate
 * 	purpose: iterate through the bst in an inorder fashion
 * inputs:
 *	bst *b: the root of the bst
 * return values:
 *	a void pointer pointing to the item in the bst
 */
void* bst_iterate(bst *b)
{
	static llist *io_list = NULL;
	
	// this code heavily draws upon the iterate code given in llist.c
	// if b is not NULL
	if(b != NULL)
	{
		io_list = create_llist();
		inorder_traversal_insert_llist(b->root, io_list);
	}
	// if the list is empty
	if(io_list->head == NULL)
		return NULL;

	void *item = io_list->head->item;
	io_list->head = io_list->head->next;
	return item;
}


/* node_item_or_successor
 * 	purpose: given a size of a chunk of memory desired, it attempts to 
 *	find an available chunk of memory the same size. If there is no
 *	chunk of memory the same size, it finds the chunk of memory that is
 *	closes to that size but larger
 * inputs:
 *	node *n: a node pointer
 *	void *item: another pointer
 *	a comparison function
 * return values:
 *	a pointer to the memory struct
 */      
void *node_item_or_successor(node *n, void *item, 
	int (*cmp)(const void* x, const void* y))
 {
 	// chec to see if n is NULL
	if(n == NULL)
		return NULL;

 	node *temp;
	llist *io_list = NULL;
	inorder_traversal_insert_llist(n, io_list);
	
	// iterate through the in order list and the first time you find
	// a value bigger than it choose and return that one
	for(temp = iterate(io_list); temp != NULL; temp = iterate(NULL))
	{
		int result = cmp(temp->data, item);
		// return the first value that's bigger than our data input
		if(result >= 0)
			return temp->data;
	}

	return NULL;
 }

/* bst_item_or_successor                                                       
 *      purpose: given a size of a chunk of memory desired, it attempts to      
 *      find an available chunk of memory the same size. If there is no         
 *      chunk of memory the same size, it finds the chunk of memory that is     
 *      closes to that size but larger                                          
 * inputs:                                                                      
 *      bst *b: a bst pointer                                         
 *      void *item: another pointer                                             
 * return values:                                                               
 *      a pointer to the memory struct    
 */
void* bst_item_or_successor(bst *b, void *item)
{
	// check to see if the BST is NULL
	if(b == NULL)
		return NULL;
 	
	void *temp;
	// iterate through the bst in an inorder fashion and compare each
	// output to the data and return the first one that is bigger
	for(temp = bst_iterate(b); temp != NULL; temp = bst_iterate(NULL))
	{
		int result = b->cmp(temp, item);
		// return the first value in the tree that is bigger
		if(result >= 0)
			return temp;
	}

	return NULL;
}


