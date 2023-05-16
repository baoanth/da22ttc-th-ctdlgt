#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *pre;
    Node *next;
};
typedef Node *node;
struct List
{
    node head;
    node tail;
};

node getNode(int x)
{
    node p = new Node;
    if (p == nullptr)
    {
        cout << "khong du vung nho  ";
        exit(1);
    }
    p->data = x;
    p->pre = NULL;
    p->next = NULL;
    return p;
}

void print_list1(List l)
{
    node p = l.tail;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pre;
    }
}

void addFirts(List &l, node tmp)
{
    if (l.head == nullptr)
    {
        l.head = tmp;
        l.tail = l.head;
    }
    else
    {
        tmp->next = l.head;
        l.head->pre = tmp;
        l.head = tmp;
    }
}

void addTail(List &l, node tmp)
{
    if (l.head == NULL)
    {
        l.head = tmp;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = tmp;
        tmp->pre = l.tail;
        l.tail = tmp;
    }
}

void addBefore(List &l, node tmp)
{
    if (l.head = NULL)
    {
        l.head = tmp;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = tmp;
        tmp->pre = l.tail;
        l.tail = tmp;
    }
}
int main()
{
    List mylist;

    int t = 10, x = 20;
    node p = getNode(t);
    node q = getNode(x);
    addBefore(mylist, p);
    addBefore(mylist, q);
    print_list1(mylist);
    return 0;

    
}
