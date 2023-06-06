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
        printf("Add %d as root ", data);
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
    printf(" %d ", Root->Key);
    NLR (Root->pLeft);
    NLR (Root->pRight);
   } 
}


void LNR(TNode* Root)
{
	if (Root != NULL)
	{
		printf(" %d ", Root->Key);
		LNR(Root->pLeft);
	//	Xu ly Root; //X? lý tuong ?ng theo nhu c?u
		LNR(Root->pRight);
	
	}
}


void LRN(TNode* Root)
{
	if (Root != NULL)
	{
		printf(" %d ", Root->Key);
		LRN(Root->pLeft);
		LRN(Root->pRight);
		
	//	Xu ly Root; //X? lý tuong ?ng theo nhu c?u
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
    {
    	int xoaNode= 12;
    	printf ("\n khong tim thay khoa x = %d \n",xoaNode);
    	return Root;
	}
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

void inputNode(TNode* &Root)
{
    char ch;
    int num;

    do
    {
        printf("Enter a number (Enter -999 to EXIT):");
        scanf("%d",&num);
        Root = insertNode (Root, num);
        //TNode* insertNode(TNode* Root, int X);
        //insertNode(T,num);
        printf("Inserted %d into the BST \n",num);
        ch = getch();
        while (getchar()!= '\n')
        	continue;
        
    }while(ch!= 27);
    
}
   

int main()
{
    TNode* myTree = NULL;

    int selection;
    int key;
    
    printf ("\n1. Input number to BST \n");
    inputNode(myTree);
    do
    {
    	printf ("\n\n*** BINARY SEARCH TREE DEMO ***\n\n");
    	printf (" Enter your selection ");
    	printf ("\n1. Print BST in first order (NLR) \n");
    	printf ("\n2. Print BST in Middle order (LNR)\n");
    	printf ("\n3. Print BST in last order (LRN)\n");
    	printf ("\n4. Delete node in BST\n");
    	printf ("\n5. EXIT\n");
    	
    	printf ("\n Your selection: ");
    	scanf (" %d ", &selection);
    /*	myTree = insert(myTree, 10);
    myTree = insert(myTree, 7);
    myTree = insert(myTree, 13);
    myTree = insert(myTree, 8);
    myTree = insert(myTree, 9);
    myTree = insert(myTree, 11);
    myTree = insert(myTree, 12);*/
   
	    switch (selection)
	    {
	    
	    	case 1:
	    		printf ("\n1. Print BST in first order (NLR)\n ");
	    		NLR(myTree);
	    		break;
	    		
	    	case 2:
	    		printf ("\n2. Print BST in Middle order (LNR)\n");
	    		LNR(myTree);
	    		break;
	    		
	    	case 3:
	    		printf ("\n3. Print BST in last order (LRN)\n");
	    		LRN(myTree);
	    		break;
	    		
	    	case 4:
	    		printf ("4. Delete node in BST\n");
	    		printf("delete node  : ");
	    		scanf("%d", &key);
	    		delNode(myTree, key);
	    		break;
	    	case 5:
	    		printf("5. EXIT \n");
	    		
	    		 default:
	            	
	            break;
	    }
	    } while (selection);

    

    /*printf("\n\nDuyet cay theo thu tu thoi gian\n");
    NLR (myTree);


    printf("\n\nSo node tren cay la %d\n",countNode(myTree));
    printf("\n\nSo leafnode tren cay la %d",countLeafNode(myTree));
    printf("\n\nChieu cao cua cay la %d",getTreeHeight(myTree));

	int themNode= 11;
    printf("\n\nThem phan tu: %d", themNode);
    myTree = insertNode(myTree, themNode);
    printf("Duyet cay sau khi them phan tu\n");
    NLR(myTree);

    
    int xoaNode= 12;
    printf("\n\nXoa cay so: %d\n", xoaNode);
    myTree = delNode(myTree, xoaNode);
    printf("\nDuyet cay sau khi xoa node\n");
    NLR(myTree);*/

    
    return 0;
}

