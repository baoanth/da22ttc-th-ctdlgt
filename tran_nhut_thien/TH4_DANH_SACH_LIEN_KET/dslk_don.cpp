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
    Node *pNext;    
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;


Node *GetNode(Person x)

{
    Node *p;
    p = new Node;
    if (p==NULL)
    {

        printf("Khong du bo nho de cap phat cho nut moi");

        printf("Khong du bo nho de cap nhat");

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



void AddFirst(List &l, Node * new_ele)
{
  if (l.pHead==NULL) 
{
    l.pHead = new_ele;
    l.pTail = l.pHead;
}
  else
{
    new_ele->pNext = l.pHead;
    l.pHead = new_ele;
}
}


void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}
void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}


void AddTail(List &l, Node *new_ele)
{
    if (l.pHead == NULL)
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

Node *FindNodeById(List l, int idx)
{
    Node *p = l.pHead;
    while (p != NULL && p->Info.id != idx)
        p = p->pNext;
    return p;
}
void AddNodeAfter(List &l, int idx, Node *new_ele4)
{
    Node *q = FindNodeById(l, idx);
    if (q != NULL && new_ele4 != NULL)
    {
        new_ele4->pNext = q->pNext;
        q->pNext = new_ele4;
        if (q == l.pTail)
            l.pTail = new_ele4;
    }
    else
        AddFirst(l, new_ele4);
}

void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if(l.pHead == NULL) l.pTail == NULL;
        delete p;
    }
}

void RemoveLast(List &l)
{
    if (l.pTail != NULL)
    {
        Node *p = l.pTail;
        Node *q = NULL;
        while (p->pNext != NULL)
        {
            q = p;
            p = p->pNext;
        }
        if (q != NULL)
            q->pNext = NULL;
        else
            l.pHead = NULL;
        l.pTail = q;
        delete p;
    }
}

int RemoveNode(List &l, int idx)
{
    Node *p = l.pHead;
    Node *q;
    while(p != NULL)
    {
        if(p->Info.id == idx) break;
        p = p->pNext;
    }
    if(p == NULL)
        return 0;
    q = p->pNext;
    if(q != NULL)
    {
        p = q ->pNext;
        if(p != NULL)
        {
            q->pNext = p->pNext;
            if(p == l.pTail)
                l.pTail = q;
            else   
                p->pNext = q;
        }
    }
    else 
    {
        l.pHead = p->pNext;
        if(l.pHead == NULL)
            l.pTail == NULL;
        else    
            l.pHead == NULL;
    }
    delete p;
    return 1;
}

void InputNode(List &l)
{
    struct Person new_per;
    printf("\nVui long nhap id: ");
    scanf("%d", &new_per.id);
    printf("\nVui long nhap fname: ");
    scanf("%s", &new_per.fname);
    printf("\nVui long nhap lname: ");
    scanf("%s", &new_per.lname);
    
    Node *new_ele = GetNode(new_per);
    int vi_tri;
    printf("\nCan them vao vi tri nao: ");
    scanf("%d", &vi_tri);
    AddNodeAfter(l, vi_tri, new_ele);

}



int main()
{

    struct Person per1 = {1, "Thien", "Tran Nhut Thien" };
	struct Person per2 = {2, "Tran", "Thien" };
	struct Person per3 = {3, "Tran", "Nhut" };
    
   

    struct Person per1 = {1, "Nhut Thien", "Thien"};
    struct Person per2 = {2, "Tran Nhut", "Nhut Thien"};
    struct Person per3 = {3, "Nhut Thien", "Nhut"};
   
    

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
    PrintList(my_list);
    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);

    Node *tim_kiem = FindNodeByID(my_list, idx);

    Node *tim_kiem = FindNodeById(my_list, idx);

    if (tim_kiem != NULL)
        PrintNode(tim_kiem);
    else
        printf("Khong tim thay ten co id %d", idx);
    return 0;

    

   



}

}

