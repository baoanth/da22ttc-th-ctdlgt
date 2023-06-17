#include <stdio.h>
#include <stdlib.h>

struct AVLNode
{
    int Data;
    struct AVLNode* left;
    struct AVLNode* right;
    int chieucao;
};

struct AVLNode* createNode(int data)
{
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->chieucao = 1;
    return newNode;
}

int chieucao(struct AVLNode* node)
{
    if (node == NULL)
        return 0;
    return node->chieucao;
}

int max(int a, int b)
{
    return (a>b) ? a : b;
}

struct AVLNode* rightRotate(struct AVLNode* y)
{
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->chieucao = max(chieucao(x->left), chieucao(x->right)) +1;
    y->chieucao = max(chieucao(y->left), chieucao(y->right)) +1;

    return y;
}

int getBalance(struct AVLNode* node)
{
    if (node == NULL)
        return 0;
    return chieucao(node->left) - chieucao(node->right);
}

struct AVLNode* insert(struct AVLNode* node, int data)
{
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
    return node;

    node->chieucao = 1 + max(chieucao(node->left), chieucao(node->right));

    int balance = getBalance(node);
    //TH1:LL
    if(balance > 1 && data < node->left->data)
        return rightRotate(node)
    //TH2:RR
    if(balance < -1 && data > node->right->data)
        return leftRotate(node);
    //TH3:LR
    if(balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //TH4:RL
    if(balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrderTraversal(struct AVLNode* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct AVLNode* root = NULL;

    root = insert(root, 12);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 26);
    root = insert(root, 97);
    root = insert(root, 9);

    printf("Cay AVL sau khi chen: \n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
