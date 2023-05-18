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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
node FindbyID(node a,int idx)
=======
node FindbyID(node a, int idx)
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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
    node tmp = FindbyID(p, idx);

    if (tmp == NULL)
        cout << "khong tim thay ";
    else
    {
        node q = a;
        while (q->Next != tmp)
        {
            q = q->Next;
        }
        q->Next = tmp->Next;
    }
}

void addbyViTri(node &a,node tmp, int vt)
{
    node p = a;
   for(int i=0; i < vt-1;i++)
   {
        p = p-> Next;
   }
    tmp-> Next = p->Next;
    p->Next = tmp;

}

void inputNode(node &a)
{
    Person per;
    cout << "nhap vao id "; cin >> per.id;
    cout << "nhap vao fname "; cin >> per.fname;
    cout << "nhap vao lname "; cin >> per.lname;
    node tmp = getnode(per);
    int vt, i = 0;
    cout << "nhap vao vi tri can chen "; cin >> vt;
    node p = a;
    addbyViTri(a,tmp, vt);
    
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
=======
<<<<<<< HEAD
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
=======
<<<<<<< HEAD
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
=======
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> b8140ab904ab6152d12532e648e1379e71b9184d
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
int main()
{

    node Head = NULL;
<<<<<<< HEAD
    Person per1 = {1,"nguyen", "An"};
	Person per2 = {2,"Le", "Vinh"};
	Person per3 = {3,"Nguyen", "Tong"};
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> b8140ab904ab6152d12532e648e1379e71b9184d
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
=======
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    Person per1 = {1, "Nguyen", "An"};
    Person per2 = {2, "Pham", "Vinh"};
    Person per3 = {3, "Nguyen", "Tong"};
    Person per4 = {4, "Nguyen", "Vinh"};
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

    node p1 = getnode(per1);
    node p2 = getnode(per2);
    node p3 = getnode(per3);
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
=======
<<<<<<< HEAD
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
=======
<<<<<<< HEAD
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
=======
<<<<<<< HEAD
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
=======
<<<<<<< HEAD
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50

    addFirst(Head, p1);
    addFirst(Head, p2);
=======
    node p4 = getnode(per4);

    addLast(Head, p1);
    addLast(Head, p2);
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    addLast(Head, p3);
    addLast(Head, p4);
    print_List(Head);
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> b8140ab904ab6152d12532e648e1379e71b9184d
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======

    inputNode(Head);
    print_List(Head);

>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    return 0;
}