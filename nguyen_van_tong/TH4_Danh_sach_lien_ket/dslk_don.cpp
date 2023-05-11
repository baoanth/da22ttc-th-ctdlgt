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
node FindbyID(node a, int idx)
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
node FindbyID(node a, int idx)
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
<<<<<<< HEAD
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
node FindbyID(node a,int idx)
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651

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
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
<<<<<<< HEAD
=======
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
<<<<<<< HEAD
=======
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
<<<<<<< HEAD
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe
int main()
{
	
    node Head = NULL;
<<<<<<< HEAD
    Person per1 = {1, "nguyen", "An"};
    Person per2 = {2, "Le", "Vinh"};
    Person per3 = {3, "Nguyen", "Tong"};
    Person per4 = {4, "Nguyen", "Vinh"};
=======
    Person per1 = {1,"nguyen", "An"};
	Person per2 = {2,"Le", "Vinh"};
	Person per3 = {3,"Nguyen", "Tong"};
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
<<<<<<< HEAD
<<<<<<< HEAD
    Person per4 = {4,"Nguyen", "Vinh"};
=======
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
<<<<<<< HEAD
=======
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
=======
=======
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
<<<<<<< HEAD
=======
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
<<<<<<< HEAD
=======
=======
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 2ebb5d8f42fed092649e2016097bd227db0bb6ba
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
<<<<<<< HEAD
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
=======
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
    Person per4 = {4,"Nguyen", "Vinh"};
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe

    node p1 = getnode(per1);
    node p2 = getnode(per2);
    node p3 = getnode(per3);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
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
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
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
=======
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
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
<<<<<<< HEAD
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe
    node p4 = getnode(per4);

<<<<<<< HEAD
    addLast(Head, p1);
    addLast(Head, p2);
=======
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
=======
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
=======
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
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
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
=======
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
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======

    addFirst(Head, p1);
    addFirst(Head, p2);
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
    addLast(Head, p3);
    addLast(Head, p4);
    print_List(Head);
    int idx;
    cout << "nhap vao id can xoa ";
    cin >> idx;

   RemoveNode(Head,idx);

    print_List(Head);
<<<<<<< HEAD
<<<<<<< HEAD

=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
<<<<<<< HEAD

=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
<<<<<<< HEAD
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
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
<<<<<<< HEAD
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
=======
>>>>>>> ca6edf686a2c7cdb261f9140d39b3c06060e9f39
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 2923fb8293bd51162c7c4592d26ce9e03f8061a2
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
>>>>>>> 9e98f717cf1d1b9f2bbe93ca23465c1bb3a250e4
=======
>>>>>>> 6f29dcfadef56eec2c3dec7e6b498c1691139651
>>>>>>> 29dc8d166e4f5ef6238a5198531361a3353f4dbe
    return 0;
}
