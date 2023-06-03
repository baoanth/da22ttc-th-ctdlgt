#include <stdio.h>
#include <conio.h>

typedef struct TNode
{
    int Key;
    TNode *pLeft, *pRight;
}TNode;

TNode* createNewNode(int data)
{
    TNode* node = new TNode;
    node->Key = data;

    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

TNode* insert(TNode *Root,int data)
{
    if(Root==NULL)
    {
        printf("\nAdd %d as root ", data);
        TNode* node = createNewNode(data);

        return node;
    }
    else
    {
        if(data < Root->Key)
        {
            printf("\nAdd %d as left child of %d\n",data,Root->Key);
            Root->pLeft = insert(Root->pLeft,data);
        }
        else
        {
            printf("\nAdd %d as right child of %d\n",data,Root->Key);
            Root->pRight = insert(Root->pRight,data);
        }
    }
    return Root;
}

void NLR(TNode* Root)
{
   if (Root != NULL)
   {
    printf("%d", Root->Key);
    NLR (Root->pLeft);
    NLR (Root->pRight);
   } 
}

int countNode(TNode *Root)
{
    int count = 0;
    if (Root !=NULL)
    {
        count ++;

        count+= countNode(Root->pLeft);
        count+= countNode(Root->pRight);
    }
    return count;
}

int countLeafNode(TNode *Root)
{
    int count = 0;
    if(Root !=NULL)
    {
        if ((Root->pLeft==NULL)&&(Root->pRight==NULL))
        count++;
        
        count+= countNode(Root->pLeft);
        count+= countNode(Root->pRight);
    }
}

int getTreeHeight(TNode *Root)
{
    if (Root == NULL)
    return 0;

    int maxLeft = getTreeHeight(Root->pLeft);

    int maxRight = getTreeHeight(Root->pRight);

    if (maxLeft > maxRight)
        return maxLeft+1;
    else
        return maxRight+1;
}

TNode* searchNode(TNode* Root, int X)
{
    if (Root == NULL || Root->Key == X)
        return Root;
    {
    if (X < Root->Key)
        return searchNode(Root->pLeft, X);
    else
        return searchNode(Root->pRight, X);
    }
    return NULL;
}

TNode* insertNode(TNode* Root, int X)
{
    if (Root == NULL)
    {
        printf("\nAdd %d as root ", X);
        return createNewNode(X);
    }

    TNode* current = Root;
    TNode* parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (X < current->Key)
            current = current->pLeft;
        else if (X > current->Key)
            current = current->pRight;
        else
        {
            printf("\nPhan tu %d da ton tai trong cay\n", X);
            return Root;
        }
    }

    if (X < parent->Key)
    {
        printf("\nAdd %d as left child of %d\n", X, parent->Key);
        parent->pLeft = createNewNode(X);
    }
    else
    {
        printf("\nAdd %d as right child of %d\n", X, parent->Key);
        parent->pRight = createNewNode(X);
    }

    return Root;
}

TNode* delNode(TNode* Root, int Key)
{
    if(Root == NULL)
    return Root;
    if (Key < Root->Key)
    Root->pLeft = delNode(Root->pLeft, Key);
else if (Key > Root->Key)
    Root->pRight = delNode(Root->pRight, Key);
else
{
    if (Root->pLeft == NULL)
    {
        TNode* temp = Root->pRight;
        delete Root;
        return temp;
    }
    else if (Root->pRight == NULL)
    {
        TNode* temp = Root->pLeft;
        delete Root;
        return temp;
    }

    TNode* minRight = Root->pRight;
    while (minRight->pLeft != NULL)
        minRight = minRight->pLeft;

    Root->Key = minRight->Key;

    Root->pRight = delNode(Root->pRight, minRight->Key);
}
     return Root;
}
   
   
int main()
{
	TREE my_tree = NULL;
	int selection = 1;
	while (selection)
	{
		printf("---BINARY SEARCH TREE DEMO---\n\n");
		printf("Enter your selection\n");
		printf("1. Input number to BST");
		printf("2. Print BST in First order (NRL)");
		printf("3. Print BST in Middle order (LNT)");
		printf("4. Print BST in Last order (LRN)");
		Printf("5. Delete node in BST");
		printf("0. EXIT");
		
		Printf("Your selection: ");
		scanf("%d", selection);
		
		switch selection
		
		    case 1:
		    	inputNode(my_tree);
		    	break;
		    case 2:
				break;
			case 3:
				print_LNR(my_tree);
				break;
			case 4:
				break;	
			case 5:
				break;	
		
	} while (selection!=0)
		
    /*TNode* myTree =NULL;

    myTree = insertNode(myTree, 11);
    myTree = insertNode(myTree, 28);
    myTree = insertNode(myTree, 40);
    myTree = insertNode(myTree, 10);
    myTree = insertNode(myTree, 22);
    myTree = insertNode(myTree, 33);
    myTree = insertNode(myTree, 18);
    myTree = insertNode(myTree, 36);
    myTree = insertNode(myTree, 9);*/

    printf("\n\nDuyet cay theo thu tu thoi gian\n");
    NLR(myTree);

    int xoaNode= 28;
    printf("\n\nXoa cay so: %d\n", xoaNode);
    myTree = delNode(myTree, xoaNode);
    printf("Duyet cay sau khi xoa node\n");
    NLR(myTree);

    int themNode= 30;
    printf("\n\nThem phan tu: %d", themNode);
    myTree = insertNode(myTree, themNode);
    printf("Duyet cay sau khi them phan tu\n");
    NLR(myTree);

    printf("\n\nSo node tren cay la %d\n",countNode(myTree));
    printf("\nSo leafnode tren cay la %d",countLeafNode(myTree));
    printf("\n\nChieu cao cua cay la %d",getTreeHeight(myTree));
    
    return 0;
}
