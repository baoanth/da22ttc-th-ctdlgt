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

void NLR(TNode* Root)//First orther
{
   if (Root != NULL)
   {
    printf("%d", Root->Key);
    NLR (Root->pLeft);
    NLR (Root->pRight);
   } 
}

void LNR(TNode* Root)//Middle order
{
    if (Root != NULL)
    {
        LNR(Root->pLeft);
        printf("%d ", Root->Key);
        LNR(Root->pRight);
    }
}

void LRN(TNode* Root)//Last orther
{
    if (Root != NULL)
    {
        LRN(Root->pLeft);
        LRN(Root->pRight);
        printf("%d ", Root->Key);
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

void inputNode(TNode* Root) 
{
    int num = 0;

    while (num != -999) 
	{
        printf("Enter a number (Enter -999 to EXIT): ");
        scanf("%d", &num);
        if (num != -999)
	    {
            insertNode(Root, num);
            printf("Inserted %d into the BST\n", num);
        }
    }
}
   
int main()
{
     TNode* Root =NULL;
    int selection = 1;

    do
    {
        printf("____BINARY SEARCH TREE DEMO___\n");

        printf("Enter your selection\n");
        printf("1. input number to BST\n");
        printf("2. Print BST in First order\n");
        printf("3. Print BST in Middle order\n");
        printf("4. Print BST in Last order\n");
        printf("5. Delete node in BST\n");
        printf("0. EXIT\n");

        printf("Your selection: ");
        scanf("%d",&selection);

    switch(selection)
    {
        case 0:
            break;

        case 1:
        printf("1. input number to BST");
        inputNode(Root);
            break;

        case 2:
        printf("\nFirst order traversal: \n");
        NLR(Root);
            break;

        case 3:
        printf("\nMiddle order traversal: \n");
        LNR(Root);
            break;

        case 4:
        printf("\nLast order traversal: \n");
        LRN(Root);
            break;
            
        case 5:
        printf("\nEnter the node to delete: \n");
        int delKey;
        scanf("%d", &delKey);
        Root = delNode(Root, delKey);
        printf("\nDeleted node %d from BST", delKey);
		    break;  
		
		default:
            printf("\nInvalid selection");
            break;	  
    }
}while (selection != 0);
    /*TNode* myTree =NULL;

    myTree = insert(myTree, 8);
    myTree = insert(myTree, 9);
    myTree = insert(myTree, 5);
    myTree = insert(myTree, 6);
    myTree = insert(myTree, 4);
    myTree = insert(myTree, 3);
    myTree = insert(myTree, 7);
    myTree = insert(myTree, 2);
    myTree = insert(myTree, 1);
    myTree = insert(myTree, 10);

    printf("\n\nDuyet cay theo thu tu thoi gian\n");
    NLR(myTree);

    int xoaNode= 8;
    printf("\n\nXoa cay so: %d\n", xoaNode);
    myTree = delNode(myTree, xoaNode);
    printf("Duyet cay sau khi xoa node\n");
    NLR(myTree);

    int themNode= 11;
    printf("\n\nThem phan tu: %d", themNode);
    myTree = insertNode(myTree, themNode);
    printf("Duyet cay sau khi them phan tu\n");
    NLR(myTree);

    int timNode = 6;
    TNode* foundNode = searchNode(myTree, timNode);
    if (foundNode != NULL)
        printf("\n\nTim thay phan tu %d trong cay\n", timNode);
    else
        printf("\n\nKhong tim thay phan tu %d trong cay\n", timNode);

    printf("\nSo node tren cay la %d\n",countNode(myTree));
    printf("\nSo nhanh tren cay la %d",countLeafNode(myTree));
    printf("\n\nChieu cao cua cay la %d",getTreeHeight(myTree));*/
    
    return 0;
}


