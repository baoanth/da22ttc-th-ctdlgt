#include<stdio.h>
typedef struct
{
    int key;
    struct Node*pLeft,*pRight;

}TNode;
typedef TNode*TREE;

void NLR(TREE Root)
{
    if(Root !=NULL)
    {
        printf("%d",NLR->key);
        print_NLR(Root->pLeft);
        print_NLR(Root->pRight);
    }
}

void LNR(TREE Root)
{
    if(Root != NULL)
    {
        print_LNR(Root->Left);
        printf("%d",LNR->key);
        print_LNR(Root->Right);
    }
}

void LRN(TREE Root)
{
    if(Root != NULL)
    {
        print_LRN(Root->Left);
        print_LRN(Root->Right);
        printf("%d",LNR->key);

    }
}

TNODE* SearchNode(TREE Root,int x)
{
    Node*p = Root;
    while(p != NULL)
    {
        if(x == p->key)
        return p;
        else 
        if(x<p->key)
        p = p->pLeft;
        else 
        p =p->pRight; 

    }
    return NULL;
}

int InsertNode(TREE &t,int x)
{
    if(t)
    {
        if(t->key == x)
        return 0;
        if(t->key >x)
        return InsertNode(t->pLeft,x);
        else
        return InsertNode(t->pRight,x);
    }
}

int main()
{
    int main ()
{
	TNode* Tress = NULL;
	
	Tress = InsertNode(Tress, 8);
	Tress = InsertNode(Tress,23);
    Tress = InsertNode(Tress,1);
    Tress = InsertNode(Tress,34);
    Tress = InsertNode(Tress,2);
    Tress = InsertNode(Tress,5768);
    Tress = InsertNode(Tress,20);
    NLR
	
	return 0;
		
} 
}