/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * bst.c
 */
#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

/* node_new:
 * 	purpose: malloc a new node and assign the data pointer to its data field
 * inputs:
 *	void *data: a void pointer pointing to the input
 * return:
 *	a pointer pointing to the node;
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
 * 	Purpose: create a new bst, initialize its root to be NULL
 * inputs:
 *	int (*cmp)(const void* x, const void* y) a pointer to a comparing
 *		function
 * return value:
 *	a bst pointer 
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
 *	purpose: Insert a node to to a subtree with a root node as parameter
 * 		Insertion is in sorted order. 
 * inputs:
 *	node *root: a pointer pointing to the root of the tree
 *	void *data: a new value to be added into the tree
 *	comparison function: a function that compares the data with the data
 *		already in the tree
 * return value:
 * 	the new root of the modified subtree.  
 */
node* node_insert(node* root, void* data, 
		int (*cmp)(const void* x, const void* y))
{	
	if(root == NULL)
	{
		return node_new(data);
	}
	else if(cmp(data, root->data) > 0)
	{
		root->right = node_insert(root->right, data, cmp);
	}
	else
	{
		root->left = node_insert(root->left, data, cmp);
	}

	return root;
}

/* bst_insert:
 * 	purpose: insert a new node to the bst
 * inputs:
 *	bst* b: a pointer to the root of the bst
 *	void *data: a node holding data to be inserted into the bst
 * return value:
 *	none, just changes the bst
 */
void bst_insert(bst* b, void* data)
{
	b->root = node_insert(b->root, data, b->cmp);
}

/* tree_min
 *	purpose: finds the predecessor to replace the removed node with
 * inputs;
 *	node* root: a pointer to the head of the bst
 * return value:
 *	the minimum value in the whole bst
 */
node *tree_min(node *root)
{
	node *holder;
	holder = root;
	
	for(holder = root; holder != NULL && holder->left != NULL; holder = holder->left)
		;

	return holder;

}


/* node_delete:
 *	purpose: delete a node from a subtree with a given root node the 
 *	comparison function to search the node and delete it when a matching
 * 	node is found. This function only deletes the first occurrence of the
 *	node, i.e, if multiple nodes contain the data we are looking for, only
 *	the first node we found is deleted. 
 * inputs:
 *	node* root: a pointer pointing to the root node
 *	void* data: the data in the node
 *	a comparison function
 * return value:
 * 	 the new root node after deletion.
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
	else 
	{
		// if we are dealing with a leaf
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return NULL;
			/*free(root->left);
			free(root->right);
			root = NULL;*/
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
			free(root->right);
			root->right = NULL;
			//root->right = node_delete(root->right, to_delete->data, cmp);
			//free(to_delete);
		}
	}
	return root;
	
}

/* bst_delete:
 *	purpose: delete a node containing data from the bst
 * inputs: 
 *	bst* b: a pointer pointing to the root of the bst
 *	void *data: the data value in the bst to be deleted
 * return value:
 *	none
 */
void bst_delete(bst* b, void* data)
{
		node_delete(b->root, data, b->cmp);		
}

/* inorder_traversal
 * 	purpose: traverse a subtree with root in ascending order, apply func 
 *		to the data of each node. 
 * inputs:
 *	node *root: a pointer to the head of the bst
 * 	a function to be applied to the bst
 * return values:
 *	none, just applies to function to the 
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
 *	purpose:traverse a bst in ascending order.apply func to 
 * 		the data of each node. 
 * inputs:
 *	bst* b: a pointer to the root of the bst
 *	a function to be appleid to the bst
 * return values:
 *	none, just applies to function to the BST
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

void node_free(node *n)
{
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
 *	purpose:free the bst with 
 * inputs:
 *	bst* b: the root of the bst to be freed
 * return values:
 *	none, just frees the bst
 */
void bst_free(bst* b)
{
	node_free(b->root);
	free(b);
}






