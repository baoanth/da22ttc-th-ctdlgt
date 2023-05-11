#include <bits/stdc++.h>
using namespace std;
struct Person
{
    int id;
    char fname[20];
    char lname[20];
};

struct Node
{
    Person data;
    Node *Next;
};

typedef struct Node *node;

node getnode(Person x)
{
    node p = new Node;
    p->data = x;
    p->Next = NULL;
    return p;
}

void addFirst(node &a, node new_ele)
{
    if (a == NULL)
    {
        a = new_ele;
    }
    else
    {
        new_ele->Next = a;
        a = new_ele;
    }
}

void in(Person per)
{
    cout << "id = " << per.id << " \n";
    cout << "fname  = " << per.fname << " \n";
    cout << "lname  = " << per.lname << " \n\n";
}

void print_List(node a)
{
    while (a != NULL)
    {
        in(a->data);
        a = a->Next;
    }
}

void addLast(node &a, node p)
{
    if (a == NULL)
    {
        a = p;
    }
    else
    {
        node q = a;
        while (q->Next != NULL)
        {
            q = q->Next;
        }
        q->Next = p;
    }
}

node FindbyID(node a, int idx)
{
    node p = a;
    while (p != NULL)
    {
        if (p->data.id == idx)
        {
            return p;
            break;
        }
        p = p->Next;
    }
    return NULL;
}

void addNodeAfter(node &a, node tmp, int idx)
{
    node p = a;
    node q = FindbyID(p, idx);
    if (q != NULL)
    {
        tmp->Next = q->Next;
        q->Next = tmp;
    }
    else
    {
        addLast(a, tmp);
    }
}

void RemoveHead(node &a)
{
    a = a->Next;
}

void RemoveLast(node &a)
{
    node p = a;
    while (p->Next->Next != NULL)
    {
        p = p->Next;
    }
    node q = p->Next;
    p->Next = NULL;
    delete (q);
}

void RemoveNode(node &a, int idx)
{
    node p = a;
    node tmp = FindbyID(p,idx);
   
    if(tmp == NULL) cout << "khong tim thay ";
    else
    {
    	node q =a;
   		while (q ->Next != tmp)
   		{
   			q = q->Next;
   		}
   		q->Next = tmp->Next;
    }
   
}
int main()
{
    node Head = NULL;
    Person per1 = {1, "nguyen", "An"};
    Person per2 = {2, "Le", "Vinh"};
    Person per3 = {3, "Nguyen", "Tong"};
    Person per4 = {4, "Nguyen", "Vinh"};

    node p1 = getnode(per1);
    node p2 = getnode(per2);
    node p3 = getnode(per3);
    node p4 = getnode(per4);

    addLast(Head, p1);
    addLast(Head, p2);
    addLast(Head, p3);
    addLast(Head, p4);
    print_List(Head);
    int idx;
    cout << "nhap vao id can xoa ";
    cin >> idx;

   RemoveNode(Head,idx);

    print_List(Head);

    return 0;
}
