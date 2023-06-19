#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

struct node* newNode(int key) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  
    return node;
}

struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct node *root) {
    if(root != NULL) {
        preOrder(root->left);
        printf(" %d ", root->key);
        preOrder(root->right);
    }
}

int main() {
    struct node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("\n");
    printf("Preorder traversal of the constructed AVL tree is: ");
    preOrder(root);

    return 0;
}

