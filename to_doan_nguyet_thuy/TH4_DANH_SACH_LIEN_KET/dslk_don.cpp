#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];

}Person;
typedef struct Node
{
    Person info;
    Node* pNext;
}Node;
typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode( Person x)
{
    Node* p;
    p = new Node;
    if(p == NULL)
    {
        printf("not du bo nho");
        return 0;
    }
    p -> info = x;
    p -> pNext = NULL;
    return p;
}

void AddFist( List &l, Node* new_ele)
{
    if (l.pHead== NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele -> pNext = l.pHead;
        l.pHead = new_ele;
    }
}
void AddTail(List &l, Node* new_ele)
{
    if(l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail ->pNext = new_ele;
        l.pTail = new_ele;
    }
}
void printList(List &l)
{
    if(l.pHead == NULL)
    {
        printf("Danh sach rong:\n");
    }
    else
    {
        Node* p;
        p = l.pHead;
        while(p!= NULL)
        {
            printf("%3d%10s%10s\n", p->info.id, p->info.fname , p->info.lname);
            p= p->pNext;

        }
    }
}
void output(List &l)
{
    Node* p= l.pHead;
    if(p!= NULL)
    {
        printf("%3d%10s%10s\n", p->info.id, p->info.fname , p->info.lname);
            p= p->pNext;
    }
}
//tim kiem
Node* FindNodeByID(List l, int idx)
{
    Node* p = l.pHead;
    while(p!= NULL && p->info.id!= idx)
         p = p-> pNext;
    return p;
}
int main()
{
    struct Person per1 = {1, "To", "Thuy" };
    struct Person per2 = {2, "Doan", "Nguyet" };
    struct Person per3 = {3, "Nha", "Doan" };

    Node* new_ele1 = GetNode(per1);
    Node* new_ele2 = GetNode(per2);
    Node* new_ele3 = GetNode(per3);
    List my_list;
    Init(my_list);

    int idx;

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);
    printList(my_list);


    printf("Nhap id can tim\n");
    scanf("%d", &idx);
    
    Node* new_ele = FindNodeByID(my_list,idx);
    output(my_list);





}



