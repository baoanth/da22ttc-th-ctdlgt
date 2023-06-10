#include <stdio.h>
#include <stdlib.h>

typedef struct mssv_ele
{
	char *ma;
	char *ten;
	
}mssv_ele;

typedef struct Node
{
	mssv_ele Info;
	Node *pNext;
}

typedef struct List
{
    Node *pHead;
    Node *pTail;
}List;

Node* GetNode(Student x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Khong du bo nho !"); 
		return NULL; 
	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

void AddTail(List &l, Node *new_ele)
{
    if(l.pHead==NULL)
    {
	    l.pHead=new_ele;
	    l.pTail=l.pHead;
	}
	else
	{
	    l.pTail->pNext = new_ele;
        l.pTail = new_ele;
	}
}

void load_data(Lish &l)
{
    char *filename = ("bac.txt");
    FILE *file = fopen(file_name, "rb");
    if(file = NULL)
    printf("khong mo duoc tap tin %s \n", file_name);

}


int main() {
    

    int bac = Student / 100000000;
    int he = ( Student/ 1000000) % 100;
    int nganh = ( Student/ 10000) % 100;
    int khoa = ( Student/ 100) % 1000;
    int id =  Student % 1000;

    return 0;
}
