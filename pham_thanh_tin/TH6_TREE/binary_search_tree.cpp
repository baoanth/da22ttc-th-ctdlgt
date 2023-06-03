#include <stdio.h>
#include <conio.h>
#include <string.h>

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

int insertNode(Node* &root, int data) 
{
    if (root == NULL) 
	{
        root = createNode(data);
    }

    if (data < root->data) 
	{
        return insertNode(root->pLeft, data);
    } 
	else 
		if (data > root->data) 
		{
        	return insertNode(root->pRight, data);
    	}

    return 0;
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

void searchStandFor(Node* &p, Node* &q)
{
    if(q->pLeft)
        searchStandFor(p, q->pLeft);
    else
    {
        p->data = q-> data;
        p = q;
        q = q->pRight;
    }
}

int delNode(Node* &t, int x)
{
    if(t==NULL)
    {
        return 0;
        printf("Khong tim thay node %d", x);
    }
    if(t->data > x)
        return delNode(t->pLeft, x);
    if(t->data < x)
        return delNode(t->pRight, x);
    else
    {    
        Node* p = t;
        
        if(t->pLeft == NULL)
            t = t->pLeft;
        else 
			if(t->pRight == NULL)
        	{
		    	t = t->pRight;
			}
			else
        	{
            	Node* q = t->pRight;
            	searchStandFor(p, q);
        	}
    	delete p;
    }
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

void printRoot(Node* node)
{
	if(node != NULL)
	{
		printf("\n%d ", node->data);
        NLR(node->pLeft);
        NLR(node->pRight);
	}

}

int main()
{   
    int select; 
    Node* root = NULL;
    do
	{
    printf("\n---DANH SACH THAO TAC VOI CAY---\n");
    printf("1. Input tree\n");
    printf("2. Duyet theo thu tu truoc(NLR)\n");
    printf("3. Duyet theo thu tu giua(LNR)\n");
    printf("4. Duyet theo thu tu sau(LRN)\n");
    printf("5. Tim node trong cay\n");
    printf("6. Xoa node trong cay\n");
    printf("0. EXIT\n ");
    
    printf("Moi nhap lua chon cua ban:");
    scanf("%d", &select);
    switch(select)
    {
	}
    
    }while(select);
/*    
    insertNode(root, 20);
    insertNode(root, 50);
    insertNode(root, 00);
    insertNode(root, 70);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 80);
    insertNode(root, 60);
    insertNode(root, 90);
    insertNode(root, 40);

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
	    printf("\nNode %d co ton tai trong cay\n", Key);
	}
	else
	{
	    printf("\nNode %d khon ton tai trong cay\n", Key);
	}
    
    delNode(root,Key);
    printf("\nCay sau khi xoa node:");
    printRoot(root);
*/
return 0;
}



