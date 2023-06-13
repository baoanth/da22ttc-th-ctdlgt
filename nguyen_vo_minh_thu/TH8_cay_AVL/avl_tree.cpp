#include <stdio.h>
#include <stlib.h>

//Dinh nghia cau truc nut cua cay AVL
struct AVLNode 
{
	int data;
	struct AVLNode* left;
	struct AVLNode* right;
	int height;
}AVLNode;

//Ham tao mot nut AVL moi 
struct AVLNode* createNode(int data)
{
	struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVlNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;//Ban dau chieu cao cua nut la 1
	return newNode;
}

//Ham tinh chieu cao cua nut 
int height(struct AVLNode* node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

//Ham tinh gia tri lown nhat cua hai so nguyen 

int max(int a, int b)
{
	return (a > b) ? a : b;
}

//Ham xoay phai(right rotation)
{
	struct AVLNode* x = y->left;
	struct AVLNode* T2 = y->right;

//Thuc hien xoay 
x->right = y;
y->left = T2;

//Cap nhat cieu cao
y->height = max(height(y->left), height(y->right)) + 1;
x->height = max(height(x->left), height(x->right)) + 1;

//Tra ve nut moi sau khi xoay
return x;
}

//Ham xoay trai (left rotation)
struct AVLNode* leftRotate(struct AVLNode* x)
{
	struct AVLNode* y = x->right;
	struct AVLNode* T2 = y->left;
	
//Thuc hien xoay
y->left = x;
x->right = T2;

//Cap nhat chieu cao
x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;

//Tra ve nut moi sau khi xoay
return y;
}

//Ham tinh do can bàng cua nut 
int getBalance(struct AVLNode* node)
{
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

//Ham chn mot nut vao cay AVL
struct AVLNode* insert(struct AVLNode* node, int data)
{
	//Thuc hien chen nut nhu cay nhi phan binh thuong
	if (node == NULL)
		return createNode(data);
	if (data < node->data)
		node->left = node->insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else //Truong hop nut da ton tai 
	return node;
	
//
}





















