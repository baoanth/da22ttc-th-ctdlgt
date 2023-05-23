#include <stdio.h>
#include <conio.h>
#include <string.h>

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
void PrintfNode(Node *p)
{
	printf("%d %s %s\n",p->Info.id,p->Info.fname,p->Info.lname);
}
void PrintList(List l)
{
	Node* p=l.pHead;
	while(p!=NULL)
	{
		printf("%d %s %s\n",p->Info.id,p->Info.fname,p->Info.lname);
		p=p->pNext;
	}
	
}
void AddTail (List &l,Node *new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail-> pNext = new_ele;
		l.pTail = new_ele;
	}	
}

Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p=l.pHead;
	while((p!=NULL)&&(p->Info.id !=idx))
	p=p->pNext;
	return p;
}
void AddNodeAfter(List &l, int idx, Person x)
{
    Node* q = FindNodeByID(l, idx);
    if (q != NULL)
    {
        Node* new_ele = GetNode(x);
        new_ele->pNext = q->pNext;
        q->pNext = new_ele;
        if (q == l.pTail)
            l.pTail = new_ele;
    }
    else
    {
        printf("loi:khong the chen node co idx=%d\n ", idx);
    }
}
void RemoveHead(List &l)
{
    if (l.pHead == NULL)
    {
        printf("loi: danh sach rong\n");
    }
    else if (l.pHead->pNext == NULL)
    {
        delete l.pHead;
        l.pHead = l.pTail = NULL;
    }
    else
    {
        Node* p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}
void RemoveLast(List &l)
{
    if (l.pHead == NULL)
    {
        printf("loi: danh sach rong\n");
    }
    else if (l.pHead->pNext == NULL)
    {
        delete l.pHead;
        l.pHead = l.pTail = NULL;
    }
    else
    {
        Node* p = l.pHead;
        while (p->pNext != l.pTail)
        {
            p = p->pNext;
        }
        delete l.pTail;
        l.pTail = p;
        l.pTail->pNext = NULL;
    }
}
void RemoveNode(List &l, int idx)
{
    if (l.pHead == NULL)
    {
        printf("loi: danh sach rong\n");
    }
    else if (l.pHead->Info.id == idx)
    {
        RemoveHead(l);
    }
    else
    {
        Node* pPrev = l.pHead;
        Node* p = l.pHead->pNext;
        while (p != NULL && p->Info.id != idx)
        {
            pPrev = p;
            p = p->pNext;
        }
        if (p != NULL)
        {
            pPrev->pNext = p->pNext;
            if (p == l.pTail)
            {
                l.pTail = pPrev;
            }
            delete p;
        }
        else
        {
            printf("Loi: khong tim thay nut cuoi de xoa %d\n", idx);
        }
    }
}
void InputNode(List &l)
{
    struct Person new_per;
    Node *new_ele = GetNode(new_per);
    int vi_tri;
    printf("\nCan them vao vi tri nao: ");
    scanf("%d", &vi_tri);
    AddNodeAfter(l, vi_tri, new_ele);
}


	

  
int main()
{
	int idx;
    struct Person per1 = {1, "Nguyen", "Vinh" };
	struct Person per2 = {2, "Phu", "Vinh" };
	struct Person per3 = {3, "Vinh", "Phu" };
    struct Person per4 = {4, "vinh", "nguyen" };
    struct Person per5 = {5, "nguyen", "phuvinh"};
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    Node* new_ele4 = GetNode(per4);
    
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
 //   AddFist(my_list, new_ele2);
 //   AddFist(my_list, new_ele3);
   
//	PrintList(my_list);
	
//	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
	AddTail(my_list, new_ele3);

    AddTail(my_list, new_ele4);
	PrintList(my_list);
	
	printf("\nnhap id can tim:");
	scanf("%d",&idx);
	Node *tim_kiem = FindNodeByID(my_list, idx);
    if (tim_kiem != NULL)
        PrintfNode(tim_kiem);
    else
        printf("Khong tim thay nut co id %d", idx);
	Node *new_ele5 = GetNode(per5);
	
    AddNodeAfter(my_list, idx, per5);
    printf("Sau khi them nut :\n");
    printf("\n");
    PrintList(my_list);
	
	RemoveHead(my_list);
    printf("******************************\n");
    printf("sau khi xoa node dau:\n");
    PrintList(my_list);
    
	RemoveLast(my_list);
    printf("***********************************\n");
    printf("sau khi xoa node cuoi:\n");
    PrintList(my_list); 

    RemoveNode(my_list,idx);
    printf("***********************************\n");
    printf("sau khi xoa node dau cuoi va node thu idx\n");
    PrintList(my_list);

    printf("nhap struct person moi\n");
    printf("nhap id:");
    scanf("%d",idx);
    printf("nhap fname:");
    scanf("%s",new_per.fname);
    



	return 0;
}
