
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
   
int main()
{
    TNode* myTree =NULL;

    myTree = insert(myTree, 10);
    myTree = insert(myTree, 7);
    myTree = insert(myTree, 13);
    myTree = insert(myTree, 8);
    myTree = insert(myTree, 9);
    myTree = insert(myTree, 11);
    myTree = insert(myTree, 12);

    printf("\n\nDuyet cay theo thu tu thoi gian\n");
    NLR(myTree);
    printf("\n\nSo node tren cay la %d\n",countNode(myTree));
    printf("\n\nSo leafnode tren cay la %d",countLeafNode(myTree));
    printf("\n\nChieu cao cua cay la %d",getTreeHeight(myTree));
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE
{
	int Key;
	struct TNODE *pLeft, *pRight;
}TNODE;
typedef TNODE*TREE;

void Print_NLR(TREE Root)
{
	if (Root !=NULL)
	{
		printf("%4d", Root->Key);
		Print_NLR(Root->pLeft);
		Print_NLR(Root->pRight);
	}
}

void Print_LNR(TREE Root)
{
	if (Root !=NULL)
	{
		Print_LNR(Root->pLeft);
		printf("%4d", Root->Key);
		Print_LNR(Root->pRight);
	}
}

void Print_LRN(TREE Root)
{
	if (Root != NULL)
	{
		Print_LRN(Root->pLeft);
		Print_LRN(Root->pRight);
		printf("%4d", Root->Key);
	}
}

TNODE* SearchNode(TREE T, int x)
{
	if(T)
	{
		if(T->Key == x)
		    return T;
		if(T->Key > x)
		    return SearchNode(T->pLeft, x);
		else
		    return SearchNode(T->pRight, x);
	}
	return NULL;
}

int InsertNode(TREE &T, int x)
{
	if(T)
	{
		if(T->Key == x)
		    return 0;
		if(T->Key > x)
		    return InsertNode(T->pLeft, x);
		else 
		    return InsertNode(T->pRight, x);
	}
	T = new TNODE;
	if(T == NULL)
	    return -1;
	T->Key = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}

int searchStandFor(TREE &p, TREE &q)
{
	if(q->pLeft)
	searchStandFor(p, q->pLeft);
	else 
	{
		p->Key = q->Key;
		p = q;
		q = q->pRight;
	}
}

int delNode(TREE &T, int x)
{
	if (T == NULL)
        return 0;
    if (T->Key > x)
        return delNode(T->pLeft, x);
    if (T->Key < x)
        return delNode(T->pRight, x);
    else
    {
    	TNODE* p = T;
        if (T->pLeft == NULL)
            T = T->pRight;
        else 
		if (T->pRight == NULL)
            T = T->pLeft;
        else
        {
            TNODE* q = T->pRight;
            searchStandFor(p, q);
        }
        delete p;
    }return 0;
}

int main()
{
	TREE my_tree = NULL;
	
	InsertNode(my_tree, 14);
	InsertNode(my_tree, 4);
	InsertNode(my_tree, 10);
	InsertNode(my_tree, 2);
	InsertNode(my_tree, 9);
	InsertNode(my_tree, 1);
	InsertNode(my_tree, 7);
	InsertNode(my_tree, 33);
	InsertNode(my_tree, 6);
	InsertNode(my_tree, 15);
	
	Print_NLR(my_tree);
	printf("\n");
	Print_LNR(my_tree);
	printf("\n");
	Print_LRN(my_tree);
	
	int x;
	printf("\nTim gia tri cua x= ");
	scanf("%d", &x);
	TNODE *giatri=SearchNode(my_tree, x);
	if(giatri == NULL)
	{
		printf("\nKhong tim thay gia tri ");
	}
	else 
	    printf("\nTim thay gia tri");
	
    printf("\n");
    printf("\nNhap x can chen: ");
    scanf("%d", &x);
    printf("\nChen %d vao day\n", x);
	InsertNode(my_tree, x);
	Print_NLR(my_tree);
	printf("\n");
	Print_LRN(my_tree);
	printf("\n");
	Print_LNR(my_tree);
	
	printf("\nNhap x can xoa: ");
	scanf("%d", &x);
	delNode(my_tree, x);
	printf("\nDay sau khi xoa\n");
	Print_NLR(my_tree);
	printf("\n");
	Print_LRN(my_tree);
	printf("\n");
	Print_LNR(my_tree);
}
