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
void output(Node* p)
{
    
    printf("%3d%10s%10s\n", p->info.id, p->info.fname , p->info.lname);
    
}
//tim kiem
Node* FindNodeByID(List l, int idx)
{
    Node* p = l.pHead;
    while(p!= NULL && p->info.id!= idx)
         p = p-> pNext;
    return p;
}
/*void RemoveHead(List &l)
{
    Node* p;
    Data idx;
    if(l.pHead != NULL)
    {
        p = l.pHead;
        idx = p->data;
        l.pHead = l.pHead->pNext;
        delete p;
        if(l.pHead == NULL)
            l.pTail = NULL;

    }
    return idx;
}*/
int RemoveNode(List &l, int idx)
{
    Node* p = l.pHead;
    Node* q = NULL;
    while(p!= NULL)
    {
        if(p->info.id== idx)
        	break;
        q = p;
        p= p-> pNext;

    }
    if(p == NULL)    
        return 0;
    if(q != NULL)
    {
        if(p== l.pTail)
            l.pTail= q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        l.pHead = p->pNext;
        if(l.pHead == NULL)
            l.pTail = NULL;

    }
    return 1;

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
    
    Node* node_kq = FindNodeByID(my_list,idx);
    if(node_kq!= NULL)
        output(node_kq);
    else
        printf("Khong tim thay node %d \n", idx);
    
    printf("Nhap id can xoa: ");
    scanf("%d", &idx);
    int kq = RemoveNode(my_list, idx);
    if(kq != 0)
        printf("Da xoa node %d \n", idx);
    else
        printf("Khong the xoa node %d \n");

    printf("Danh sach sau khi xoa:\n");
    printList(my_list);



return 0;

}

