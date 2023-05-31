#include <stdio.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *pLeft, *pRight;
    
}Node;
typedef Node* TREE;

Node* createNode(int data) 
{
    Node* node = new Node;
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
    
    root = insertNode(root, 20);
    root = insertNode(root, 50);
    root = insertNode(root, 00);
    root = insertNode(root, 70);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 80);
    root = insertNode(root, 60);
    root = insertNode(root, 90);
    root = insertNode(root, 40);

    printf("Duyet theo thu tu truoc:\n");
    NLR(root);
    printf("\n");
    printf("\nDuyet theo thu tu giua:\n");
    LNR(root);
    printf("\n");
    printf("\nDuyet theo thu tu sau:\n");
    LRN(root);
    
    int Key;
    printf("\n");
    printf("\nNhap node can tim trong cay:");
    scanf("%d",&Key);
    Node* searchN = searchNode(root, Key);
    if(searchN != NULL)
    {
	    printf("Node %d co ton tai trong cay", Key);
	}
	else
	{
	    printf("Node %d khon ton tai trong cay", Key);
	}
     
return 0;
}



