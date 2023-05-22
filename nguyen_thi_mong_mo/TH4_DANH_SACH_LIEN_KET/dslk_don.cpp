#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

Node* GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}

void AddTail(List &l, Node* new_ele)
{
    if (l.pHead==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

Node* FindNodeByID(List l, int idx)
{
    Node *p;
    p =l.pHead;

    while ((p!=NULL) && (p->Info.id !=idx))
        p = p->pNext;

    return p;
}



void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}
 
void PrintNode(Node *p)
{
    printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
}
 
void PrintList(List &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
			p = p->pNext;
		}		
	}
}
 


int main()
{
    struct Person per1 = {3, "Nguyen", "Le Hoa Binh" };
	struct Person per2 = {2, "Le", "Binh" };
	struct Person per3 = {1, "Tran", "Hoa" };
    
    Node* new_ele3  = GetNode(per3);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele1  = GetNode(per1);
    List my_list;
    Init(my_list);

	//AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
 
	
    AddTail(my_list, new_ele1);
    //AddTail(my_list, new_ele2);
    //AddTail(my_list, new_ele3);

 
    PrintList(my_list);
    int idx;
    printf("\nNhap id can tim ");
    scanf("%d", &idx);
    Node *node_kq  = FindNodeByID(my_list, idx);
    if (node_kq!=NULL)
        PrintNode(node_kq);
    else   
        printf("Tim khong thay node co id %d", idx);
 
    PrintList(my_list); 

    return 0;

 

}
