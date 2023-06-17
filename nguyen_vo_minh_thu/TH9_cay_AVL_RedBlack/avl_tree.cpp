#include <stdio.h>
#include <stdlib.h>

// �?nh nghia c?u tr�c n�t c?a c�y AVL
struct AVLNode 
{
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// H�m t?o m?t n�t AVL m?i
struct AVLNode* createNode(int data) 
{
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Ban d?u chi?u cao c?a n�t l� 1
    return newNode;
}

// H�m t�nh chi?u cao c?a n�t
int height(struct AVLNode* node) 
{
    if (node == NULL)
        return 0;
    return node->height;
}

// H�m t�nh gi� tr? l?n nh?t c?a hai s? nguy�n
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// H�m xoay ph?i (right rotation)
struct AVLNode* rightRotate(struct AVLNode* y) 
{
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Th?c hi?n xoay
    x->right = y;
    y->left = T2;

    // C?p nh?t chi?u cao
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Tr? v? n�t m?i sau khi xoay
    return x;
}

// H�m xoay tr�i (left rotation)
struct AVLNode* leftRotate(struct AVLNode* x) 
{
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Th?c hi?n xoay
    y->left = x;
    x->right = T2;

    // C?p nh?t chi?u cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Tr? v? n�t m?i sau khi xoay
    return y;
}

// H�m t�nh d? c�n b?ng c?a n�t
int getBalance(struct AVLNode* node) 
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// H�m ch�n m?t n�t v�o c�y AVL
struct AVLNode* insert(struct AVLNode* node, int data) 
{
    // Th?c hi?n ch�n n�t nhu c�y nh? ph�n b�nh thu?ng
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Tru?ng h?p n�t d� t?n t?i
    return node;

    // C?p nh?t chi?u cao c?a n�t
    node->height = 1 + max(height(node->left), height(node->right));

    // Ki?m tra d? c�n b?ng c?a n�t
    int balance = getBalance(node);

    // Ki?m tra c�c tru?ng h?p vi ph?m d? c�n b?ng v� th?c hi?n xoay d? c�n b?ng c�y
    // Tru?ng h?p 1: Left Left
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Tru?ng h?p 2: Right Right
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Tru?ng h?p 3: Left Right
    if (balance > 1 && data > node->left->data) 
	{
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Tru?ng h?p 4: Right Left
    if (balance < -1 && data < node->right->data) 
	{
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Tru?ng h?p kh�ng vi ph?m d? c�n b?ng, tr? v? n�t
    return node;
}

// H�m in-order traversal (duy?t theo th? t? tr�i - g?c - ph?i)
void inOrderTraversal(struct AVLNode* root)  
{
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct AVLNode* root = NULL;
    // Ch�n c�c s? nguy�n v�o c�y AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // In c�y AVL sau khi ch�n
    printf("Cay AVL sau khi chen: \n");
    inOrderTraversal(root);
    // 10 20 25 30 40 50

    printf("\n");

	return 0;
}



