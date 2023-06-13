#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int height;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *rotateRight(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *rotateLeft(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node *insertNode(struct Node *node, int val)
{
    if (node == NULL)
        return createNode(val);

    if (val < node->val)
        node->left = insertNode(node->left, val);
    else if (val > node->val)
        node->right = insertNode(node->right, val);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && val < node->left->val)
        return rotateRight(node);

    if (balance < -1 && val > node->right->val)
        return rotateLeft(node);

    if (balance > 1 && val > node->left->val)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && val < node->right->val)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inOrder(struct Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->val);
        inOrder(node->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
	
	printf("Duyet theo thu tu giua:\n");
    inOrder(root);

    return 0;
}
