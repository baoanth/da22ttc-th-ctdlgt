#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Hàm tạo một nút mới với khóa được cung cấp
Node* newNode(int key) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Hàm tính chiều cao của cây con
int getHeight(Node* node) 
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Hàm tính số lượng các nút con của một nút
int getBalance(Node* node) 
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Hàm xoay phải tại nút y
Node* rightRotate(Node* y) 
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Hàm xoay trái tại nút x
Node* leftRotate(Node* x) 
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Hàm chèn một khóa vào cây AVL
Node* insert(Node* node, int key) 
{
    // Thực hiện chèn như trong BST
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Không chèn các khóa trùng lặp

    // Cập nhật chiều cao của nút cha
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Tìm hiệu chỉnh cân bằng
    int balance = getBalance(node);

    // Nếu cây mất cân bằng, có ba trường hợp xoay và cân bằng
    // Trường hợp Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Trường hợp Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Trường hợp Left Right
    if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp Right Left
    if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Hàm duyệt cây AVL theo thứ tự trung tố
void inorderTraversal(Node* root) 
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Hàm chính
int main() 
{
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Duyet cay AVL theo thu tu : ");
    inorderTraversal(root);

    return 0;
}
