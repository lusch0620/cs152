/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * bst.h
 */
#ifndef BST_H
#define BST_H

typedef struct _node{
	void* data;
	struct _node* left;
	struct _node* right;
}node;

typedef struct{
	node* root;
	int (*cmp)(const void* x, const void* y);
}bst;


/* ******* BST ******** */
/* These functions are what programmers using the BST would use */

/* bst_new:                                                                     
 *      Purpose: create a new bst, initialize its root to be NULL               
 * inputs:                                                                      
 *      int (*cmp)(const void* x, const void* y) a pointer to a comparing       
 *              function                                                        
 * return value:                                                                
 *      a bst pointer                                                           
 */
bst* bst_new(int (*cmp)(const void* x, const void* y));

/* bst_insert:                                                                  
 *      purpose: insert a new node to the bst                                   
 * inputs:                                                                      
 *      bst* b: a pointer to the root of the bst                                
 *      void *data: a node holding data to be inserted into the bst             
 * return value:                                                                
 *      none, just changes the bst                                              
 */ 
void bst_insert(bst* b, void* data);

/* bst_search
 *   purpose: search for a node wih data in a bst
 *.inputs:
 *   bst *b: a pointer pointing to the root of the bst
 *   void *data: the data to be found
 * return value:
 *   the data in the node if found
 */
void* bst_search(bst* b, void* data);

/* inorder_traversal
 *   purpose: traverse a subtree with root in ascending order, apply func 
 *        to the data of each node. 
 * inputs:
 *   node *root: a pointer to the head of the bst
 *   a function to be applied to the bst
 * return values:
 *   none, just applies to function to the 
 */
void bst_inorder_traversal(bst* b, void(*func)(void* data));

/* bst_free
 *   purpose:free the bst with 
 * inputs:
 *   bst* b: the root of the bst to be freed
 * return values:
 *   none, just frees the bst
 */
void bst_free(bst* b);

/* bst_delete:                                                                  
 *      purpose: delete a node containing data from the bst                     
 * inputs:                                                                      
 *      bst* b: a pointer pointing to the root of the bst                       
 *      void *data: the data value in the bst to be deleted                     
 * return value:                                                                
 *      none                                                                    
 */   
void bst_delete(bst* b, void* data);


/* ******* Node ****** */
/* These functions are only in the .h file so you can 
 * call them for testing purposes. Normally,they would
 * not be in the .h because they aren't intended to be 
 * called from outside bst.c
 */

/* node_new:                                                                    
 *      purpose: malloc a new node and assign the data pointer to its data field
 * inputs:                                                                      
 *      void *data: a void pointer pointing to the input                        
 * return:                                                                      
 *      a pointer pointing to the node;                                         
 */ 
node* node_new(void* data);

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
		int (*cmp)(const void* x, const void* y));

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
		int (*cmp)(const void* x, const void* y));

/* node_search:                                                                 
 *      purpose: search for a node containing data in a subtree with a given    
 *      root node. Use recursion to search that node.                           
 * inputs:                                                                      
 *      node* root: a pointer pointing to the root                              
 *      void *data: the data value to be searched up                            
 *      comparison function                                                     
 * return value:                                                                
 *       the first occurrence of node.                                          
 */ 
void* node_search(node* root, void* data, 
		int (*cmp)(const void* x, const void* y));

/* inorder_traversal
 *   purpose: traverse a subtree with root in ascending order, apply func 
 *        to the data of each node. 
 * inputs:
 *   node *root: a pointer to the head of the bst
 *   a function to be applied to the bst
 * return values:
 *   none, just applies to function to the 
 */
void inorder_traversal(node* root, void(*func)(void* data));

#endif
