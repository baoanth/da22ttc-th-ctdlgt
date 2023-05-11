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
void PrintList(List &l)
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
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;	
		}
	}
}

//Viet ham them nut vao cuoi danh sach
//void AddAfter(List &l, Node*q, Node* new_ele)
//{
//	Node* p = q->pNext;
//	if(q != NULL)
//	{
//		new_ele->pNext = p;
//		new_ele->pPrev = q;
//		q->pNext = new_ele;
//		
//		if(p != NULL)
//			p->pPrev = new_ele;
//		if(q==l.pTail)
//			l.pTail = new_ele;
//	}
//	else
//	AddFirst(l, new_ele);
//}

//Tao ham void InserAfter
//void InserAfter(List &l, Node *q, Person x)
//{
//	Node *p = q->pNext;
//	Node* new_ele  = GetNode(x);
//	
//	if(new_ele ==NULL)
//	return NULL;
//	
//	if(q!=NULL)
//	{
//		new_ele->pNext = p;
//		new_ele->pPrev = q;
//		q->pNext = new_ele;
//		
//		if(p!=NULL)
//			p->pPrev = new_ele;
//			
//		if(q==l.pTail)
//			l.pTail = new_ele;
//	}
//	else
//		AddFirst(l, new_ele);
//}

// Viet ham AddTail
void AddTail(List &l, Node *new_ele)
{
	if(l.pHead==NULL)
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



//Ham main
int main()
{
    struct Person per1 = {1, "Kieu", "Gia Thinh"};
	struct Person per2 = {2, "Nguyen Thi", "Tra My"};
	struct Person per3 = {3, "Con", "Vit"};
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
   
    List my_list;
    Init(my_list);

  //  AddFist(my_list, new_ele1);
  //  AddFist(my_list, new_ele2);
   AddFist(my_list, new_ele3);
    
    
    AddTail(my_list, new_ele1);
    AddTail(my_list, new_ele2);
   // AddTail(my_list, new_ele3);
    
    PrintList(my_list);
//    int idx;
//    printf("\nNhap id can tim: ");
//    scanf("%d", idx);
//    
//    Node *node
//    

}

