#include <stdio.h>
#include <string.h>

typedef struct TNode
{
    int Key;
     TNode *pLeft, *pRight;
} TNode;

TNode* creatNewNode (int data)
{
	TNode* node = new TNode;
	node -> key = data;
	
	node -> pLeft = NULL;
	node -> pRight = NULL;
	
	return node;
}

TNode* insert(TNode *Root, int data)
{
    if(Root == NULL) 
    {
        printf ("Add %d as root \n", data);
        TNode* node = creatNewNode (data);
        
        return node;
    }
    else 
    {
    	if (data < Root -> key)
    	{
    		printf (" Add %d as left child of %d \n", data, Root -> key);
    		Root -> pLeft = insert (Root -> pLeft, data);
		}
		else
		{
				printf (" Add %d as right child of %d \n", data, Root -> key);
    		Root -> pRight = insert (Root -> pRight, data);	
		}
	}
	return Root;
}


void NLR (TNode* Root)
{
    if (Root != NULL)
    {
        NLR(Root->pLeft);
        NLR(Root->pRight);
    }
}

void LNR(TNode* Root)
{
    if (Root != NULL)
    {
        LNR(Root->Left);
        LNR(Root->Right);
    }
}

void LRN(TNode* Root)
{
    if (Root != NULL)
    {
        LRN(Root->Left);
        LRN(Root->Right);
    }
}




int getTreeHeight (TNode* Root)
{
	if (Root == NULL)
	return 0;
	
	int maxLeft = getTreeHeight (Root -> pLeft);
	
	int maxRight = getTreeHeight (Root -> pRight);
	
	if (maxLeft > maxRight)
		return maxLeft + 1;
	else 
		return maxRight + 1;
}


int main ()
{
	TNode* myTree = NULL;
	
	myTree = insert (myTree, 5);
	myTree = insert (myTree, 7);
	myTree = insert (myTree, 9);
	myTree = insert (myTree, 3);
	myTree = insert (myTree, 1);
	myTree = insert (myTree, 10);
	
	printf ("Duyet cay theo thu tu giua \n");
	NLR(myTree);
	printf ("\n\n So Node tren cay la %d \n", countNode (myTree));
	printf ("\n\n So leafNode tren cay la %d \n", countLeafNode (myTree));
	printf ("\n\n Chieu cao cua cay la %d \n", getTreeHeight (myTree));
	
	return 0;
		
} 
