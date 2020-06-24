/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw6.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"


char *category_strings[] = { "Grocery", "Office", "Pharmacy", "Hobby"};

void print_product(product_info *p, FILE *fp)
{
	fprintf(fp,"%s (%u) %s ",p->name, p->productID,
			category_strings[p->category]);
	// remember to take out category number
	fprintf(fp, "Current: %u Min: %u Max: %u Category Number: %d\n",
			p->current_stock, p->min_for_restock, 
			p->max_after_restock, p->category);
}

void print_list(node *head, FILE *fp)
{
	node *tmp;
	printf("Product Status:\n");
	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		print_product(tmp->product,fp);
		printf("\n");
	}
}
/* copy
 *   purpose: copies one array into another
 * inputs:
 *   char *arr: a pointer to the array being copied
 *   int arr_length: the length of *arr
 *   char *arr_copy: the array *arr is being copied into
 * return values:
 *   none; the pointer is just changed
 */
void copy(char *arr, int arr_length, char *arr_copy)
{
	// iteratively loop through the array and copy it into *arr_copy
	for(int i = 0; i < arr_length; i++)
	{
		*(arr_copy + i) = *(arr + i);
	}
}
/* create_product
 *	purpose: allocates memory and fills in the fields for a product
 * inputs:
 *	char *name: the name of the product 
 *	char *category: the category of the product
 *	uint id: the product ID
 *	uint curent_stock: how many are currently in stock
 *	uint min_for_restock: the minimum amount need to restock
 *	uint max_after_restock: how many are in stock after restocking
 * return values:
 *	a product_info pointer pointing to the newly allocated and initialized
 *	memory
 */

product_info *create_product(char *name, char *category, uint id, uint current,
		uint mn, uint mx)
{
	//enum cat;

	product_info *prodPtr = NULL;

	prodPtr = (product_info *)malloc(sizeof(product_info));
	//prodPtr->name = (char *)malloc(strlen(name) * sizeof(char));

	//return error if string length is greater than 40
	if(strlen(name) > 40)
	{
		fprintf(stderr, "Name is too long\n");
	}


	// multiple if statements to decide which category the product is
	if(strcmp(category, "Grocery") == 0)
	{
		prodPtr->category = GROCERY;
	}
	else if(strcmp(category, "Office") == 0)
	{
		prodPtr->category = OFFICE;
	}
	else if(strcmp(category, "Pharmacy") == 0)
	{
		prodPtr->category = PHARMACY;
	}
	else if( strcmp(category, "Hobby") == 0)
	{
		prodPtr->category = HOBBY;
	}
	else
	{
		fprintf(stderr, "didn't enter a correct category");
	}

	copy(name, strlen(name), prodPtr->name);
	// should i free the name ptr? probably
	prodPtr->productID = id;
	prodPtr->current_stock = current;
	prodPtr->min_for_restock = mn;
	prodPtr->max_after_restock = mx;

	return prodPtr;
}

/* insert_head
 *	purpose: adds a product to the beginning of a list
 * inputs:
 *	node *head: a pointer pointing to the head of the list
 *	product_info: product to be added to the fron t of the list
 * return values:
 * 	a pointer to the beginning of a linked list of products
 */
node* insert_head(node *head, product_info *pinfo)
{
	node *newNode;

	newNode = (node *)malloc(sizeof(node));

	newNode->product = pinfo;
	newNode->next = head;
	head = newNode;

	return head;
}

/* find
 *	purpose: given a productID, finds the record for the product
 * inputs
 *	node *head: a pointer pointing to the head of the linked list
 *	uint pID: the product ID
 * return values:
 *	a pointer pointing to the record of the product
 */
product_info *find(node *head, uint pID)
{
	product_info *prodPtr;
	node *temp = head;
	
	// iteratively loop through the list to find the specific product
	for(temp = head; temp->product->productID != pID; temp = temp->next)
	{
		;
	}
	prodPtr = temp->product;
	
	return prodPtr;
	
}

/* record_restocked_single
 *	purpose: given a productID, replace the current number of items
 *	         with the max number of items after restocking
 * inputs:
 *	node *head: a pointer pointing to the linked list of products
 *	uint pID: the product ID
 * return values:
 *	none, just changes the list
 */
void record_restocked_single(node *head, uint pID)
{
	//product_info *prodPtr;
	node *temp;

	// iteratively loop through the list to find the specific product to
	// restock
	for(temp = head; temp->product->productID != pID; temp = temp->next)
	{
		;
	}

	temp->product->current_stock = temp->product->max_after_restock;

}

/* product_sold
 *	purpose: given a productid, find the record for the product a decrement
 *		the number of items currently in stock for that item
 * inputs:
 *	node *head: a pointer pointing to the head of the linked list
 *	uint pID: the product ID
 * return values:
 *	none just changes the list
 */
void product_sold(node *head, uint pID)
{
	node *temp;

	// iteratively loop through the list to find the specific product
	for(temp = head; temp->product->productID != pID; temp = temp->next)
	{
		;
	}

	// error case if the current stock is already at 0
	if(temp->product->current_stock == 0)
	{
		fprintf(stderr, "Current stock of product is 0\n");
	}
	// if stock is > than zero decrement by 1
	else
	{
		temp->product->current_stock = temp->product->current_stock - 1;
	}
}

/* add_sorted_productID
 *	purpose: add a product into a list based on only its ID
 * inputs:
 *	product_info *pinfo: the new product to be added into the list
 *	node *head: the pointer pointing to the beginnign of the linked list
 * return value:
 *	a new list with the item added in the right spot
 */
node *add_sorted_productID(product_info *pinfo, node *head)
{
	node *newNode, *currNode, *prevNode;

	newNode = (node *)malloc(sizeof(node));

	newNode->product = pinfo;
	newNode->next = NULL;

	currNode = head;
	prevNode = NULL;

	// if the list is currently empty
	if(currNode == NULL)
	{
		head  = insert_head(head, pinfo);
		return head;
	}
	// if the list is not empty
	else
	{
		// loop through and find the spot where the new ID is greater
		// than the last node's ID but less than the next node's ID
		while(currNode != NULL && 
		newNode->product->productID > currNode->product->productID)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		// if the newNode belongs at the beginning of the list
		if(prevNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		// if the newNode belongs anywhere else
		else
		{
			prevNode->next = newNode;
			newNode->next = currNode;
		}
		return head;
	}
}


/* add_sorted_categoryID
 *   purpose: add a product into a list based first on its category and then
 *		its ID
 * inputs:
 *   product_info *pinfo: the new product to be added into the list
 *   node *head: the pointer pointing to the beginnign of the linked list
 * return value:
 *   a new list with the item added in the right spot
 */
node *add_sorted_categoryID(product_info *pinfo, node *head)
{
	node *newNode, *currNode, *prevNode;

	newNode = (node *)malloc(sizeof(node));

	newNode->product = pinfo;
	newNode->next = NULL;

	currNode = head;
	prevNode = NULL;

	// the different cases where the product would belong at the beginning
	// of the list
	if((currNode == NULL) ||                                                   
		(newNode->product->category == currNode->product->category &&   
		 newNode->product->productID < currNode->product->productID) ||  
		(newNode->product->category < currNode->product->category))     
	{                                                                       
		return insert_head(head, pinfo);                              
	}
	// if the newNode belongs anywhere else
	else                                                                       
	{                                                                          
		prevNode = currNode;                                               
		currNode = currNode->next;        

		// iteratively loop through the whole list
		while(currNode != NULL)                                            
		{                                         
			//complicated if statement, sorry for the formatting. Basically
			// checks for the different parameters of the previous node
			// and next node that the newNode belongs in between
			if(((prevNode->product->category < 
				 newNode->product->category) ||
				 ((prevNode->product->category == 
				   newNode->product->category) &&
				  (prevNode->product->productID < 
				   newNode->product->productID)))

				&&

				((currNode->product->category > 
				  newNode->product->category) ||
				 (currNode->product->category == 
				  newNode->product->category &&
				  currNode->product->productID > 
				  newNode->product->productID)))
			{                                                          
				prevNode->next = newNode;                          
				newNode->next = currNode;                          
				return head;                                       
			}                                                          

			prevNode = currNode;                                       
			currNode = currNode->next;                                 

		}                                                                  
		currNode = newNode;                                          
		prevNode->next = currNode;
		return head;                                                       
	}  

}

/* is_empty
 *	purpose: decides if a iist is empty
 * inputs:
 *	 node *head: a pointer pointing to the beginning of the linked list
 * return values
 *	1 if the list is empty, 0 if not empty
 */
int is_empty(node *head)
{
	// if the list is empty
	if(head == NULL)
	{
		return 1;
	}
	// if the list is not empty
	else
		return 0;
}
/* make_restock_list
 *	purpose: make a list of the products that need to be restocked
 * inputs:
 *	node *head: a pointer pointing to the beginning of a list of products
 * return values:
 *	a pointer pointing to the beginnning of a list of products that need 
 *	to be restocked
 */
node *make_restock_list(node *head)
{    
	node *newList, *temp;

	// return NULL if the list is empty	
	if(is_empty(head) == 1)
	{
		return NULL;
	}
	// if the list is not empty
	else
	{
		// iteratively loop through every value in the list
		for(temp = head; temp != NULL; temp = temp->next)
		{
			// if the current stock is less than the minimum for restock
			// add the product to a list
			if(temp->product->current_stock <
			temp->product->min_for_restock)
			{
				newList = add_sorted_categoryID(temp->product,
				newList);
			}	
		}
		return newList;
	}
}

/* record_restocked_list
 * 	purpose: given a list of restocked items, go through the original list
 *			and record the current_stock value to be equal to max
 * inputs:
 *	node *restocked_list: a pointer pointing to a list of restocked items
 *	node *head: a pointer poitning to the head of a list of items
 * return values:
 *	none, just changes a list
 */
void record_restocked_list(node *restocked_list, node *head)
{
	node *headTemp, *restockedTemp;

	// iteratively loop through the list
	for(headTemp = head; headTemp != NULL; headTemp = headTemp->next)
	{
		// iteratively loop through the list sto restock 
		for(restockedTemp = restocked_list; restockedTemp != NULL; 
		restockedTemp = restockedTemp->next)
		{
			// make the right changes to the right products
			if(restockedTemp->product->productID == 
			headTemp->product->productID)
			{
				headTemp->product->current_stock = 
				headTemp->product->max_after_restock;
			}
		}
	}
} 
