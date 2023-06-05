#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
    
} Person;

typedef struct Node
{
	Person Info;
	Node* pNext;
} Node;

typedef struct List
{
	Node* pHead;
	Node* pTail;
} List;

Node* GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho");
        return NULL;
    }
    p -> Info = x;
    p -> pNext = NULL;
    return p;
}

void AddFirst (List &l, Node* new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead= new_ele;
		l.pTail= l.pHead;
	}
  else
	{
		new_ele -> pNext = l.pHead;
		l.pHead =  new_ele ;
	}
}		

void AddTail (List &l, Node* new_ele)	
{
	if (l.pHead==NULL)
	{
		l.pHead= new_ele;
		l.pTail= l.pHead;
	}
  else
	{
		l.pTail -> pNext = new_ele;
		l.pTail = new_ele;
	}
}


Node* FindNodeByID(List l, int idx)
{
    Node *p;
    p =l.pHead;

    while ((p!=NULL) && (p -> Info.id !=idx))
        p = p->pNext;

    return p;
}

void Init( List &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%5d | 20%s | 10%s\n",p->Info.id,p->Info.fname,p->Info.lname);
}	

void PrintList(List &l)
{
	Node* p;
	p= l.pHead;
	while(p !=NULL)
	{
	printf("%5d | 20%s | 10%s\n",p->Info.id,p->Info.fname,p->Info.lname);
		p=p->pNext;
	}
}

int main()
{
    struct Person per1 = {1, "Nguyen", "Tran" };
	struct Person per2 = {2, "Huyen", "Tran" };
	struct Person per3 = {3, "Nguyen", "Tong" };
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    
    List my_list;
    Init(my_list);

	AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
    
    PrintList(my_list); 


    int idx;
        printf ("Nhap id can tim: ");
        scanf("%d", &idx);
        printf("\n");
        Node* kq = FindNodeByID(my_list, idx);		
    if (kq!=NULL)
        PrintNode(kq);
    else   
        printf("\nTim khong thay node co id %d", idx);	
        
    return 0;
}
void AddNodeAfter(List &l, int idx)
{
	

