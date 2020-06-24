/* This is meant to help understand the functionality of linked lists 
 * Everything in here should be crystal clear
 */

#include <stdio.h>
#include <stdlib.h>

// creates a linked list structure that holds characters
typedef struct listNode{
	char data; // data holds the value that the node stores
	struct listNode *nextPtr; // nextPtr is a pointer to the node after it
}ListNode;

// defines ListNodePtr as a pointer to ListNode
typedef ListNode *ListNodePtr; 

// print the instructions
void instructions(void)
{
	printf("Enter your choice:\n"
		  "	1 to insert an element into the list.\n"
		  "	2 to delete an element from the list.\n"
		  "	3 to end.\n");
}


/* printList
 *	purpose: prints out a linked list
 * input values:
 *	currentPtr: a pointer pointing to the beginning of a linked list
 * return values:
 *	none, just prints the linked list to the screen
 */
void printList(ListNodePtr currentPtr) 
{
	// checks to see if the list that currentPtr points to is empty
	if(currentPtr == NULL) 
	{
		printf("List is empty\n\n");
	}
	else
	{
		printf("The list is:\n");
		// as long as currentPtr is pointing to a node with values in it
		while(currentPtr != NULL)
		{
			printf("%c --> ", currentPtr->data);
			// make currentPtr point to the next node
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n\n");
	}
}

/* insert
 *	purpose: insert a new value into the list in alphabetized order
 * inputs:
 *	ListNodePtr *sPtr: a pointer to a pointer pointing to start of the 
 *				    pre-existing linked list
 *	char value: the letter to be added into the linked list
 * return values:
 *	none, just a changed linked list
 */
 void insert(ListNodePtr *sPtr, char value)
 {
 	ListNodePtr newPtr, prevPtr, currPtr;

	newPtr = malloc(sizeof(ListNode));
	
	// if space is available
	if(newPtr != NULL)
	{
		// fill in newPtr with the correct value data
		newPtr->data = value;
		// we dont know whether the value passed in will be the last in 
		// the linked list, and we also don't know where to point it yet
		// so it nextPtr is just set to NULL
		newPtr->nextPtr = NULL;

		// initialize prevPtr to be NULL
		prevPtr = NULL;
		// pass in all the data held in *sPtr to currPtr
		currPtr = *sPtr;

		// while currPtr is a node with data in it and the value to be 
		// inserted is greater than the current value held in the node
		while(currPtr != NULL && value > currPtr->data)
		{
			// pass currPtr's data into prevPtr
			prevPtr = currPtr;
			// make currPtr point to the next node
			currPtr = currPtr->nextPtr;
		}
		
		// if previousPointer is now pointing at the very last node
		if(prevPtr == NULL)
		{
			// put all the data in *sPtr to the last node
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			prevPtr->nextPtr = newPtr;
			newPtr->nextPtr = currPtr;
		}
	}
	else
	{
		printf("%c not inserted. No memory available.\n", value);
	}
 }


int main()
{
	ListNodePtr startPtr = NULL;
	int choice;
	char item;

	instructions();
	scanf("%d", &choice);

	while(choice != 3)
	{
		switch(choice)
		{
			case 1:
			{
				printf("Enter a character: ");
					scanf("\n%c", &item);
				insert(&startPtr, item);
				printList(startPtr);
				break;
			}
		}
	}
}



















































