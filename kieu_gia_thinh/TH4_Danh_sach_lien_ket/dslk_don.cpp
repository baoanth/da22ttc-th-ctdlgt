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

//Khai bao Node voi Info la kieu Person
typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

//Khai bao danh sach lien ket don List voi thanh phan la Node 
typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

//Viet ham khoi tao danh sach lien ket 
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Viet ham tao mot Node moi tu cau truc x kieu  Person
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

//Viet ham them mot Node mo vao dau danh sach
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

//Ham duyet va in dannh sach ra man hinh
void PrintList(List &l, Node* new_ele)
{
	if(l.pHead == NULL)
	{
		printf("Danh sach rong\n");
	}
	else 
	{
		Node *p;
		p = l.pHead;
		while(p!=NULL)
		{
			printf("%5d %20s %10d\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;	
		}
	}
}


//Ham main
int main()
{
    struct Person per1 = {1, "Kieu", "Gia Thinh"};
	struct Person per2 = {2, "Nguyen", "Tra My"};
	struct Person per3 = {3, "Con", "Vit"};
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);
    

}

