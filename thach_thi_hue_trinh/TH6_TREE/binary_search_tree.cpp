#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int key;
	struct Node *pLeft, *pRight;
}Node;

typedef Node*TREE;

void Node_Left_Right(TREE Root)
{
	if(Root != NULL)
	{
		printf("%4d", Root->key);
		Node_Left_Right(Root->pLeft);
		Node_Left_Right(Root->pRight);
	}
}

void Left_Node_Right(TREE Root)
{
	if(Root != NULL)
	{
		Left_Node_Right(Root->pLeft);
		printf("%4d", Root->key);
		Left_Node_Right(Root->pRight);
	}
}

void Left_Right_Node(TREE Root)
{
	if(Root!=NULL)
	{
		Left_Right_Node(Root->pLeft);
		Left_Right_Node(Root->pRight);
		printf("%4d",Root->key);
	}
}

Node* SearchNode(TREE Root, int x)
{
	Node *p = Root;
    while (p != NULL)
    {
        if (x == p->key)
            return p;
        else if (x < p->key)
            p = p->pLeft;
        else
            p = p->pRight;
	return NULL;
    }
}

int InsertNode(TREE &t, int x)
{
	if(t)
	{
		if(t->key == x)
			return 0;
		if(t->key > x)
			return InsertNode(t->pLeft,x);
		else
			return InsertNode(t->pRight,x);                                      		
	}
	
	t = new Node;
	if(t == NULL)
		return -1;
		
	t->key = x;
	t->pLeft = t->pRight = NULL;
	return 1;	
}

int main()
{
	int x, m;
	TREE root = NULL;
	
	 InsertNode(root,1);
	 InsertNode(root,4);
	 InsertNode(root,67);
	 InsertNode(root,18);
	 InsertNode(root,19);
	 InsertNode(root,87);
	 InsertNode(root,2);
	 InsertNode(root,4);
	 InsertNode(root,5);
	 InsertNode(root,15);		
	
	printf("DAY 1:\n");
	printf("Sap xep theo thu tu NLR ");
	Node_Left_Right(root);
	printf("\n");
	printf("DAY 2: \n");
	printf("Sap xep theo thu tu LNR ");
	Left_Node_Right(root);
	printf("\n");
	printf("DAY 3:\n");
	printf("Sau xep theo thu tu LRN ");
	Left_Right_Node(root);
	
	printf("\n");
	
	printf("\nNhap x can tim: ");
	scanf("%d",&x);
	if(SearchNode(root,x)==NULL)
	{
		printf("Khong tim thay %d trong day ",x);
	}
	else
	{
		printf("Tim thay %d trong day ",x);
	}
	
	printf("\nNhap x can chen: ");
	scanf("%d",&x);
	printf("Chen %d vao day 2: \n",x);
	InsertNode(root, x);
	Left_Node_Right(root);
	
}













