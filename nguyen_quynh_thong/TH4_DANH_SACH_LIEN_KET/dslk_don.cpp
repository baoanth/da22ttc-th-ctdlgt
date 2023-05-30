#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
} Person;

typedef struct Node
{
    Person Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

<<<<<<< HEAD
void AddFirst(List &l, Node* new_ele)
=======
void AddFirst(List &l, Node *new_ele)
>>>>>>> ca6ac27cd5e02de09453469c19c79d97e62cca5b
{
    if (l.pHead == NULL)
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

<<<<<<< HEAD
void PrintList(List &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
			p = p->pNext;
		}		
	}
}
<<<<<<< HEAD
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

=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
void PrintList(List &l)
=======
void PrintNode(Node *p)
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
void PrintList(List &l)
=======
void PrintNode(Node *p)
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
}
<<<<<<< HEAD
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
<<<<<<< HEAD
>>>>>>> 5de63e9e904304a5f48a7fee999f0123f1cdeb0a
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
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
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
=======
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

void PrintList(List l)
{
    printf("\n");
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

>>>>>>> ca6ac27cd5e02de09453469c19c79d97e62cca5b
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
    struct Person per1 = {1, "Nguyen", "Thong"};
    struct Person per2 = {2, "Huynh", "Nhan"};
    struct Person per3 = {3, "Pham", "Vinh"};
    

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
<<<<<<< HEAD
   
=======
    
>>>>>>> ca6ac27cd5e02de09453469c19c79d97e62cca5b

    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
<<<<<<< HEAD
   

    PrintList(my_list);

    /*
    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);
    Node *tim_kiem = FindNodeById(my_list, idx);
    if (tim_kiem != NULL)
        PrintNode(tim_kiem);
    else
        printf("Khong tim thay nut co id %d", idx);
    
    printf("\nNhap id can chen phia sau: ");
    scanf("%d", &idx);

    AddNodeAfter(my_list, idx, new_ele4);

    PrintList(my_list);

    RemoveHead(my_list);
    printf("\n Xoa nut dau");
    PrintList(my_list);

    RemoveLast(my_list);
    printf("\n Xoa nut cuoi");
    PrintList(my_list);

    printf("\nNhap id can xoa: ");
    scanf("%d", &idx);
    int kq = RemoveNode(my_list,idx);
    if(kq == 1)
    PrintList(my_list);
    */

    InputNode(my_list);
=======

<<<<<<< HEAD
>>>>>>> ca6ac27cd5e02de09453469c19c79d97e62cca5b
    PrintList(my_list);

    return 0;


}
<<<<<<< HEAD






=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    PrintList(my_list);

=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
    PrintList(my_list);

=======
<<<<<<< HEAD
<<<<<<< HEAD

} 
=======
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813

} 
=======
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
<<<<<<< HEAD
=======

} 
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
>>>>>>> 5de63e9e904304a5f48a7fee999f0123f1cdeb0a
=======
=======
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
    PrintList(my_list);

=======
<<<<<<< HEAD
<<<<<<< HEAD

} 
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
=======
    PrintList(my_list);

    /*
    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);
    Node *tim_kiem = FindNodeById(my_list, idx);
    if (tim_kiem != NULL)
        PrintNode(tim_kiem);
    else
        printf("Khong tim thay nut co id %d", idx);
    
    printf("\nNhap id can chen phia sau: ");
    scanf("%d", &idx);

    AddNodeAfter(my_list, idx, new_ele4);

>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
    PrintList(my_list);

    RemoveHead(my_list);
    printf("\n Xoa nut dau");
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
    PrintList(my_list);

    RemoveLast(my_list);
    printf("\n Xoa nut cuoi");
    PrintList(my_list);

    printf("\nNhap id can xoa: ");
    scanf("%d", &idx);
    int kq = RemoveNode(my_list,idx);
    if(kq == 1)
    PrintList(my_list);
    */

    InputNode(my_list);
    PrintList(my_list);

<<<<<<< HEAD
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    PrintList(my_list);

>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
=======
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    return 0;
}
<<<<<<< HEAD
=======

} 
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
<<<<<<< HEAD
>>>>>>> 5de63e9e904304a5f48a7fee999f0123f1cdeb0a
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
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
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
=======
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
>>>>>>> ca6ac27cd5e02de09453469c19c79d97e62cca5b
