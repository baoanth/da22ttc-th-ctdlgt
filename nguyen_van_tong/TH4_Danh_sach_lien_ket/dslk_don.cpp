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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
=======
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
>>>>>>> 67478727c443e6834eb52538eef05b3efdb129aa

void addLast(node& a, node p)
{
    if(a == NULL )
    {
        a = p;
    }
    else
    {
    	node q = a;
        while(q->Next != NULL)
        {
            q= q->Next;
        }
    	q ->Next = p; 
        
        
    }
}

<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
<<<<<<< HEAD
node FindbyID(node a,int idx)
{
    node p = a;
    while(p != NULL)
    {
        if(p->data.id == idx) 
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

    tmp->Next = q->Next;
    q ->Next = tmp; 
}
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
>>>>>>> 67478727c443e6834eb52538eef05b3efdb129aa
int main()
{
    node Head = NULL;
    Person per1 = {1,"nguyen", "An"};
	Person per2 = {2,"Le", "Vinh"};
	Person per3 = {3,"Nguyen", "Tong"};
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba

    node p1 = getnode(per1);
    node p2 = getnode(per2);
    node p3 = getnode(per3);
<<<<<<< HEAD
<<<<<<< HEAD

    addFirst(Head, p1);
    addFirst(Head, p2);
<<<<<<< HEAD
<<<<<<< HEAD
    addFirst(Head, p3);
=======
    addLast(Head, p3);
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
    addFirst(Head, p3);
>>>>>>> 67478727c443e6834eb52538eef05b3efdb129aa

    print_List(Head);
=======
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
    node p4 = getnode(per4);

   addLast(Head,p1);
   addLast(Head,p2);
   addLast(Head,p3);
	
    int idx;
    cout << "nhap vao id can chen"; cin >> idx;
    addNodeAfter(Head,p4,idx);
    
    print_List(Head);

   
=======

    addFirst(Head, p1);
    addFirst(Head, p2);
    addLast(Head, p3);

    print_List(Head);
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
    return 0;
}
