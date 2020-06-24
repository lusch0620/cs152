/* The purpose of this is to understand search tree, and binary search trees
 * better
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
	int data;
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value)
{
	if(*treePtr == NULL)
	{
		*treePtr = malloc(sizeof(TreeNode));

		if(*treePtr != NULL)
		{
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
		{
			printf("%d not inserted. No memory available.\n", value);
		}
	}
	else
	{
		if(value < (*treePtr)->data)
		{
			insertNode( &((*treePtr)->leftPtr), value);
		}
		else if(value > (*treePtr)->data)
		{
			insertNode( &((*treePtr)->rightPtr), value);
		}
		else
		{
			printf("dup");
		}
	}
}

int main()
{
	int i, item;
	TreeNodePtr rootPtr = NULL;
	
	for(i = 1; i <= 10; i++)
	{
		item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}
	printf("\n");
}
