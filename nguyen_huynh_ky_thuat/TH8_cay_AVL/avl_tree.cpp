#include<stdio.h>
#include <stlib.h>

// Dinh nghia cau truc nut cua cay AVL

struct AVLNode
{
	int data;
	struct AVLNode* left;
	struct AVLNode* right;
	int height;
};

// Ham tao nut AVL moi 
struct AVLNode* createNode(int data)
{
	struct AVLNode* newNode = (struct AVLNode*)maloc(sizeof(struct AVLNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;//Ban dau chieu cao cua nut la 1
	return newNode;
}

// Ham tinh chieu cao cua nut
int height(struct AVLNode* node)
{
	if (node == NULL)
	    return 0;
	return node->height;    
}

// Ham tinh gia tri lon nhat cua hai so nguyen 
int max(*int a, int b)
{
	return (a>b) ? a : b;
}
