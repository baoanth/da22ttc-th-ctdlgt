#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int key;
	struct Node *pLeft, *pRight;
}Node;

typedef Node*TREE;

void Node_Left_Right(Node* node)
{
	if(node!=NULL)
	{
		printf("%d", node->key);
		Node_Left_Right(node->pLeft);
		Node_Left_Right(node->pRight);
	}
}

void Left_Node_Right(Node* node)
{
	if(node!=NULL)
	{
		Left_Node_Right(node->pLeft);
		printf("%d", node->key);
		Left_Node_Right(node->pRight);
	}
}

void Left_Right_Node(Node* node)
{
	if(node!=NULL)
	{
		Left_Right_Node(node->pLeft);
		Left_Right_Node(node->pRight);
		printf("%d",node->key);
	}
}

Node* SearchNode(Node* t, int x)
{
	if(t)
	{
		if(t->key == x)
			return t;
		if(t->key > x)
			return SearchNode(t->pLeft,x);
		else
			return SearchNode(t->pRight,x);		
	}
	return NULL;
}














