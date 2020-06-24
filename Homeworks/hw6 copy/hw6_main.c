/* Name: Lucius Gao
 * CNET: uciusgao2001
 * CS 152, Winter 2020
 * hw6_main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

int main(int argc, char *argv[])
{
	node *temphead = NULL, *head;
	product_info *product, *test;

	// make sure there are two arguments - hw5 and filename
	if (argc < 2)
	{
		printf("Usage: ./hw6 filename. Missing filename\n");
		exit(1);
	}
	char *filename = argv[1];

	// open file for reading
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s for reading\n",filename);
		exit(2);
	}

	// read in each record from the file
	char buffer[BUFSIZ];
	while (!feof(fp) && (fgets(buffer,500,fp) != NULL))
	{
		// parse the line to split up the fields
		char *category;
		char *name;
		uint pID;
		uint current_stock;
		uint min_stock;
		uint max_stock;
		char *tmp_s;

		// first field is category
		category = strtok(buffer," ,\n\r");
		// second field is name
		name = strtok(NULL," ,\n\r");
		// third is pID;
		tmp_s = strtok(NULL," ,\n\r");
		pID = atoi(tmp_s);
		// fourth is current
		tmp_s = strtok(NULL," ,\n\r");
		current_stock = atoi(tmp_s);
		// fifth is min
		tmp_s = strtok(NULL," ,\n\r");
		min_stock = atoi(tmp_s);
		// sixth is max
		tmp_s = strtok(NULL," ,\n\r");
		max_stock = atoi(tmp_s);

		printf("Read in record: %s, %s, %u, %u, %u, %u\n",
			category, name, pID, current_stock, min_stock,
			max_stock);

		// now you need to write the code to create a record
		// and put that record into the linked list
		product = create_product(name, category, pID, current_stock,
			min_stock, max_stock);
		temphead = insert_head(temphead, product);
	}
		head = temphead;
	// here you can add stuff to test your other functions
	printf("\nFunction Tests\n");	

	printf("\nCREATE_PRODUCT TESTS\n");
		product = create_product("Potato", "Grocery", 1234, 12, 34, 99);
		print_product(product, stdout);
		product = create_product("A name that is definitely very long"
			"too long for this",
			"Pharmacy", 111, 43, 93, 20);
		product = create_product("Melatonin", "Pharmacy", 859032, 45,
			10, 500);
		print_product(product, stdout);
	
	printf("\nINSERT_HEAD TESTS\n");
		printf("\t\tOriginal List\n");
		print_list(head, stdout);
		head = insert_head(head, product);
		printf("\t\tAdded Melatonin to head\n");
			print_list(head, stdout);
		product = create_product("Potato", "Grocery", 1234, 12, 34, 99);
			head = insert_head(head, product);
			printf("\t\tAdded Potatoes to head\n");
			print_list(head, stdout);
		product = create_product("Mechanical Pencils", "Office",
			859031, 44, 10, 200);
			head = insert_head(head, product);
			printf("\t\tAdded Mechanical Pencils to head\n");
			print_list(head, stdout);

	printf("\nFIND TESTS\n");
		printf("List we are finding from\n");
			print_list(head, stdout);
		printf("Find product 2956: ");
			test = find(head, 2956);
			print_product(test, stdout);
		printf("Find product 380571: ");
			test = find(head, 380571);
			print_product(test, stdout);
		printf("Find product 2653: ");
			test = find(head, 2653);
			print_product(test, stdout);
	
	printf("\nRECORD_RESTOCKED_SINGLE TESTS\n");
		printf("\t\tOriginal List\n");
		print_list(head, stdout);
		record_restocked_single(head, 8261);
		record_restocked_single(head, 92656);
		record_restocked_single(head, 3826);
		printf("\t\tAfter Restocking BandAids, Flour, and Stapler\n");
		print_list(head, stdout);
	
	head = temphead;
	printf("\nPROUDCT_SOLD TESTS\n");
		printf("\t\tOriginal List\n");
		print_list(head, stdout);
		product_sold(head, 380571);
		product_sold(head, 2956);
		product_sold(head, 38590);
		printf("\t\tAfter a single LionStuffy,"
		" Butter, and have been sold\n");
		print_list(head, stdout);
	
	head = NULL;
	printf("\nADD_SORTED_PRODUCTID TESTS\n");
		printf("\t\tOriginal List is currently empty\n");
		printf("Adding and sorting everything from product.txt\n");
		product = create_product("2%Milk", "Grocery", 38590, 17, 10, 30);
			head = add_sorted_productID(product, head);
		product = create_product("Butter", "Grocery", 2956, 20, 10, 35);
			head = add_sorted_productID(product, head);
		product = create_product("LionStuffy", "Hobby", 380571, 7, 4, 8);
			head = add_sorted_productID(product, head);
		product = create_product("Stapler", "Office", 3826, 23, 22, 30);
			head = add_sorted_productID(product, head);
		product = create_product("Printer", "Office", 23765, 5, 4, 8);
			head = add_sorted_productID(product, head);
		product = create_product("BandAids", "Pharmacy", 8261, 14, 12, 25);
			head = add_sorted_productID(product, head);
		product = create_product("BugSpray", "Pharmacy", 2653, 8, 6, 16);
			head = add_sorted_productID(product, head);
		product = create_product("Flour", "Grocery", 92656, 9, 8, 12);
			head = add_sorted_productID(product, head);
		print_list(head, stdout);
		printf("The list is now only sorted by ID\n");
	
	head = NULL;
	printf("\nADD_SORTED_CATEGORYID TESTS\n");
		printf("\t\tOriginal List is currently empty\n");
		printf("Adding and sorting everything from product.txt by"
			" category and then ID\n");
		product = create_product("2%Milk", "Grocery", 38590, 17, 10, 30);
			head = add_sorted_categoryID(product, head);
		product = create_product("Butter", "Grocery", 2956, 20, 10, 35);
			head = add_sorted_categoryID(product, head);
		product = create_product("LionStuffy", "Hobby", 380571, 7, 4, 8);
			head = add_sorted_categoryID(product, head);
		product = create_product("Stapler", "Office", 3826, 23, 22, 30);
			head = add_sorted_categoryID(product, head);
		product = create_product("Printer", "Office", 23765, 5, 4, 8);
			head = add_sorted_categoryID(product, head);
		product = create_product("BandAids", "Pharmacy", 8261, 14, 12, 25);
			head = add_sorted_categoryID(product, head);
		product = create_product("BugSpray", "Pharmacy", 2653, 8, 6, 16);
			head = add_sorted_categoryID(product, head);
		product = create_product("Flour", "Grocery", 92656, 9, 8, 12);
			head = add_sorted_categoryID(product, head);
		print_list(head, stdout);
		printf("The list is now only sorted first by category and"
			" then by ID\n");

	head = NULL;
	product = NULL;
	printf("\nMAKE_RESTOCK_LIST TESTS\n");
	
	printf("\t\tOriginal List with some stock modifications\n");
	node *t2Node;
	product= create_product("2%Milk", "Grocery", 38590, 12, 10, 30);
		head = add_sorted_categoryID(product,head);
	product = create_product("Butter", "Grocery", 2956, 2, 10, 35); 
		head = add_sorted_categoryID(product, head);
	product = create_product("LionStuffy", "Hobby", 380571, 7, 4, 8);
		head = add_sorted_categoryID(product, head);
	product = create_product("Stapler", "Office", 3826, 23, 22, 30);
		head = add_sorted_categoryID(product, head);
	product = create_product("Printer", "Office", 23765, 5, 4, 8);
		head = add_sorted_categoryID(product, head);
	product = create_product("BandAids", "Pharmacy", 8261, 1, 12, 25);
		head = add_sorted_categoryID(product, head);
	product = create_product("BugSpray", "Pharmacy", 2653, 8, 6, 16);
		head = add_sorted_categoryID(product, head);
	product = create_product("Flour", "Grocery", 92656, 7, 8, 12);
		head = add_sorted_categoryID(product, head);
				
	print_list(head, stdout);

	t2Node = make_restock_list(head);
	printf("\t\tButter, Bandaids, and Flour need to be restocked\n");
	print_list(t2Node, stdout);
					
	printf("\nRECORD_RESTOCKED_LIST TESTS\n");
	printf("\t\tOriginal List\n");
		print_list(head, stdout);
	printf("\t\tAfter restocking Butter, Flour, and BandAids\n");
		record_restocked_list(t2Node, head);
		print_list(head, stdout);
}
