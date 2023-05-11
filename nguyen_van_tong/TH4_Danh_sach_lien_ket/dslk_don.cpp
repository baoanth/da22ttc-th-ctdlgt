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
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba

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
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
int main()
{
    node Head = NULL;
    Person per1 = {1,"nguyen", "An"};
	Person per2 = {2,"Le", "Vinh"};
	Person per3 = {3,"Nguyen", "Tong"};
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
<<<<<<< HEAD
    Person per4 = {4,"Nguyen", "Vinh"};
=======
=======
<<<<<<< HEAD
=======
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
=======
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50

    node p1 = getnode(per1);
    node p2 = getnode(per2);
    node p3 = getnode(per3);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
<<<<<<< HEAD

    addFirst(Head, p1);
    addFirst(Head, p2);
    addFirst(Head, p3);

    print_List(Head);
=======
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
    node p4 = getnode(per4);

   addLast(Head,p1);
   addLast(Head,p2);
   addLast(Head,p3);
	
    int idx;
    cout << "nhap vao id can chen"; cin >> idx;
    addNodeAfter(Head,p4,idx);
    
    print_List(Head);

   
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50

    addFirst(Head, p1);
    addFirst(Head, p2);
    addLast(Head, p3);

    print_List(Head);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
    return 0;
}
