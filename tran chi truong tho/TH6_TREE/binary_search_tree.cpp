#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pLeft, *pRight;
    
}Node;
typedef Node* TREE;

Node* createNode(int data) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}    
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->pLeft = insertNode(root->pLeft, data);
    } else if (data > root->data) {
        root->pRight = insertNode(root->pRight, data);
    }

    return root;
}

Node* searchNode(Node* t, int x)
{
    if(t)
    {
        if(t->data == x)
            return t;
        if(t->data > x)
            return searchNode(t->pLeft, x);
        else 
            return searchNode(t->pRight, x);
    }
    return NULL;
}

void NLR(Node* node)
{
    if(node != NULL)
    {   
        printf("%d ", node->data);
        NLR(node->pLeft);
        NLR(node->pRight);
    }
}

void LNR(Node* node)
{
    if(node != NULL)
    {
        LNR(node->pLeft);
        printf("%d ", node->data);
        LNR(node->pRight);
    }
}

void LRN(Node* node)
{
    if(node != NULL)
    {
        LRN(node->pLeft);
        LRN(node->pRight);
        printf("%d ", node->data);
    }
}

int main()
{
	
    Node* root = NULL;
    
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 10);

    printf("Duyet theo thu tu truoc:\n");
    NLR(root);
    printf("\n");
    printf("\nDuyet theo thu tu giua:\n");
    LNR(root);
    printf("\n");
    printf("\nDuyet theo thu tu sau:\n");
    LRN(root);
    printf("thanh cong");
return 0;
}


