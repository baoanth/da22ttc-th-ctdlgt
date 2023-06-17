#include <stdio.h>
#include <stdlib.h>

// Ð?nh nghia c?u trúc nút c?a cây AVL
struct AVLNode 
{
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Hàm t?o m?t nút AVL m?i
struct AVLNode* createNode(int data) 
{
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Ban d?u chi?u cao c?a nút là 1
    return newNode;
}

// Hàm tính chi?u cao c?a nút
int height(struct AVLNode* node) 
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Hàm tính giá tr? l?n nh?t c?a hai s? nguyên
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// Hàm xoay ph?i (right rotation)
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

    // Tr? v? nút m?i sau khi xoay
    return x;
}

// Hàm xoay trái (left rotation)
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

    // Tr? v? nút m?i sau khi xoay
    return y;
}

// Hàm tính d? cân b?ng c?a nút
int getBalance(struct AVLNode* node) 
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Hàm chèn m?t nút vào cây AVL
struct AVLNode* insert(struct AVLNode* node, int data) 
{
    // Th?c hi?n chèn nút nhu cây nh? phân bình thu?ng
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Tru?ng h?p nút dã t?n t?i
    return node;

    // C?p nh?t chi?u cao c?a nút
    node->height = 1 + max(height(node->left), height(node->right));

    // Ki?m tra d? cân b?ng c?a nút
    int balance = getBalance(node);

    // Ki?m tra các tru?ng h?p vi ph?m d? cân b?ng và th?c hi?n xoay d? cân b?ng cây
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

    // Tru?ng h?p không vi ph?m d? cân b?ng, tr? v? nút
    return node;
}

// Hàm in-order traversal (duy?t theo th? t? trái - g?c - ph?i)
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
    // Chèn các s? nguyên vào cây AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // In cây AVL sau khi chèn
    printf("Cay AVL sau khi chen: \n");
    inOrderTraversal(root);
    // 10 20 25 30 40 50

    printf("\n");

	return 0;
}



