/* Name Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw6.h
 */

#ifndef HW6_H
#define HW6_H

typedef unsigned int uint;

enum Category { GROCERY=0, OFFICE, PHARMACY, HOBBY};
#define NUM_CATEGORIES 4

typedef struct {
	enum Category category;
	char name[40];
	uint productID;
	uint current_stock;
	uint min_for_restock;
	uint max_after_restock;
} product_info;

// for the linked list, we will use the following struct
typedef struct _node node;

struct _node{
	product_info *product;
	node *next;
};

extern char *category_strings[];
void print_product(product_info *g, FILE *fp);
void print_list(node *head, FILE *fp);

/* create_product
 *      purpose: allocates memory and fills in the fields for a product
 * inputs:
 *      char *name: the name of the product 
 *      char *category: the category of the product
 *      uint id: the product ID
 *      uint curent_stock: how many are currently in stock
 *      uint min_for_restock: the minimum amount need to restock
 *      uint max_after_restock: how many are in stock after restocking
 * return values:
 *      a product_info pointer pointing to the newly allocated and initialized
 *      memory
 */
product_info *create_product(char *name, char *category, uint id, 
		uint current, uint mn, uint mx);

/* insert_head
 *      purpose: adds a product to the beginning of a list
 * inputs:
 *      node *head: a pointer pointing to the head of the list
 *      product_info: product to be added to the fron t of the list
 * return values:
 *      a pointer to the beginning of a linked list of products
 */
node* insert_head(node *head, product_info *pinfo);

/* find
 *      purpose: given a productID, finds the record for the product
 * inputs
 *      node *head: a pointer pointing to the head of the linked list
 *      uint pID: the product ID
 * return values:
 *      a pointer pointing to the record of the product
 */
product_info *find(node *head, uint pID);

/* record_restocked_single
 *      purpose: given a productID, replace the current number of items
 *               with the max number of items after restocking
 * inputs:
 *      node *head: a pointer pointing to the linked list of products
 *      uint pID: the product ID
 * return values:
 *	none, just changes the list
 */
void record_restocked_single(node *head, uint pID);

/* product_sold
 *   purpose: given a productid, find the record for the product a decrement
 *        the number of items currently in stock for that item
 * inputs:
 *   node *head: a pointer pointing to the head of the linked list
 *   uint pID: the product ID
 * return values:
 *   none just changes the list
 */
void product_sold(node *head, uint pID);

/* add_sorted_productID
 *   purpose: add a product into a list based on only its ID
 * inputs:
 *   product_info *pinfo: the new product to be added into the list
 *   node *head: the pointer pointing to the beginnign of the linked list
 * return value:
 *   a new list with the item added in the right spot
 */
node *add_sorted_productID(product_info *pinfo, node *head);

/* add_sorted_categoryID
 *   purpose: add a product into a list based first on its category and then 
 *	its ID
 * inputs:
 *   product_info *pinfo: the new product to be added into the list
 *   node *head: the pointer pointing to the beginnign of the linked list
 * return value:
 *   a new list with the item added in the right spot
 */
node *add_sorted_categoryID(product_info *pinfo, node *head);

/* make_restock_list
 *   purpose: make a list of the products that need to be restocked
 * inputs:
 *   node *head: a pointer pointing to the beginning of a list of products
 * return values:
 *   a pointer pointing to the beginnning of a list of products that need 
 *   to be restocked
 */
node *make_restock_list(node *head);












#endif
