#include<bits/stdc++.h>
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

typedef struct  Node* node;

node getnode(Person x)
{
    node p = new Node;
    p->data = x;
    p->Next = NULL;
    return p;
}

void addFirst(node &a,node new_ele)
{
    if(a == NULL)
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
    while(a!= NULL)
    {
        in(a->data);
        a = a->Next;
    }

}
int main()
{
    node Head = NULL;
    Person per1 = {1,"nguyen", "An"};
	Person per2 = {2,"Le", "Vinh"};
	Person per3 = {3,"Nguyen", "Tong"};

    node p1 = getnode(per1);
    node p2 = getnode(per2);
    node p3 = getnode(per3);

    addFirst(Head, p1);
    addFirst(Head, p2);
    addFirst(Head, p3);

    print_List(Head);
    return 0;
}
