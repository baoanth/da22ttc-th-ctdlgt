#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pLeft, *pRight;
} Node;

typedef Node* TREE;

Node* CreateNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

Node* InsertNode(Node* root, int data)
{
    if (root == NULL)
    {
        return CreateNode(data);
    }

    if (data < root->data)
    {
        root->pLeft = InsertNode(root->pLeft, data);
    }
    else if (data > root->data)
    {
        root->pRight = InsertNode(root->pRight, data);
    }

    return root;
}

Node* SearchNode(Node* t, int x)
{
    if (t)
    {
        if (t->data == x)
            return t;
        if (t->data > x)
            return SearchNode(t->pLeft, x);
        else
            return SearchNode(t->pRight, x);
    }
    return NULL;
}

void NLR(Node* node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        NLR(node->pLeft);
        NLR(node->pRight);
    }
}

void LNR(Node* node)
{
    if (node != NULL)
    {
        LNR(node->pLeft);
        printf("%d ", node->data);
        LNR(node->pRight);
    }
}

void LRN(Node* node)
{
    if (node != NULL)
    {
        LRN(node->pLeft);
        LRN(node->pRight);
        printf("%d ", node->data);
    }
}

int main()
{
    Node* root = NULL;

    root = InsertNode(root, 4);
    root = InsertNode(root, 6);
    root = InsertNode(root, 16);
    root = InsertNode(root, 20);
    root = InsertNode(root, 19);
    root = InsertNode(root, 13);
    root = InsertNode(root, 10);
    root = InsertNode(root, 45);
    root = InsertNode(root, 30);
    root = InsertNode(root, 27);

    printf("Duyet theo thu tu truoc:\n");
    NLR(root);
    printf("\n");

    printf("\nDuyet theo thu tu giua:\n");
    LNR(root);
    printf("\n");

    printf("\nDuyet theo thu tu sau:\n");
    LRN(root);
    printf("\n");

    int Key;
    printf("\nNhap node can tim :");
    scanf("%d", & Key);
    printf("\n");
    
    Node* newKey = SearchNode(root, Key);
    if (newKey != NULL)
    {
        printf("Da tim thay node %d trong cay \n", Key);
    }
    else
    {
        printf("khong tim thay node %d ton tai trong cay\n", Key);
    }

    return 0;
}

