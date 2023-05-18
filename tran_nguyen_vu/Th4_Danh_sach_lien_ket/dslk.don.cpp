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

void AddFist(List &l, Node* new_ele)
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
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintList(List &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
<<<<<<<< HEAD:tran_nguyen_vu/Th4_Danh_sach_lien_ket/dslk.don.cpp
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
			p = p->pNext;
		}		
	}
========
		l.pTail-> pNext = new_ele;
		l.pTail = new_ele;
	}	
}
void PrintfNode(Node *p)
{
	printf("%d %s %s\n",p->Info.id,p->Info.fname,p->Info.lname);
}
Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p=l.pHead;
	while((p!=NULL)&&(p->Info.id !=idx))
	p=p->pNext;
	return p;
>>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b:nguyen_phu_vinh/TH4_Danh_Sach_Lien_Ket/dslk_don.cpp
}

int main()
{
<<<<<<<< HEAD:tran_nguyen_vu/Th4_Danh_sach_lien_ket/dslk.don.cpp
    struct Person per1 = {1, "Vu", "Thien" };
	struct Person per2 = {2, "Nguyen", "Ku ti" };
	struct Person per3 = {3, "Tran", "Hoa" };
========
	int idx;
    struct Person per1 = {1, "Nguyen", "Vinh" };
	struct Person per2 = {2, "Phu", "Vinh" };
	struct Person per3 = {3, "Vinh", "Phu" };
    struct Person per4 = {4, "vinh", "nguyen" };
>>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b:nguyen_phu_vinh/TH4_Danh_Sach_Lien_Ket/dslk_don.cpp
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);
<<<<<<<< HEAD:tran_nguyen_vu/Th4_Danh_sach_lien_ket/dslk.don.cpp

    PrintList(my_list);

    return 0;


========
   
//	PrintList(my_list);
	
//	AddTail(my_list, new_ele1);
//   AddTail(my_list, new_ele2);


    AddTail(my_list, new_ele4);
	PrintList(my_list);
	
	printf("\nnhap id can tim:");
	scanf("%d",&idx);
	
	return 0;
>>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b:nguyen_phu_vinh/TH4_Danh_Sach_Lien_Ket/dslk_don.cpp
}
