<<<<<<< HEAD
=======
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
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFist(List &l, Node *new_ele)
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

void AddTail(List &l, Node *new_ele)
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (l.pTail == NULL)
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
<<<<<<< HEAD
	if (l.pHead == NULL)
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
	if (l.pTail == NULL)
=======
	if (l.pHead == NULL)
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
<<<<<<< HEAD
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
	if (l.pTail == NULL)
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
<<<<<<< HEAD
<<<<<<< HEAD
		p = l.pTail;
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
<<<<<<< HEAD
		p = l.pHead;
=======
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
		p = l.pTail;
=======
		p = l.pHead;
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
<<<<<<< HEAD
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
		p = l.pTail;
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;
		}
	}
=======
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
<<<<<<< HEAD
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
}

void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
    p = p->pNext;
}

Node *FindNodeByID(List l, int idx)
{
    Node *p = l.pHead;
    while ((p != NULL) && (p->Info.id != idx))
    {
        p = p->pNext;
    }
    return p;
}

void AddNodeAfter(List &l, int idx, Node *new_ele)
{
    Node *q = FindNodeByID(l, idx);

    if (q != NULL && new_ele != NULL)
    {
        new_ele->pNext = q->pNext;
        q->pNext = new_ele;
        if (q == l.pTail)
            l.pTail = new_ele;
    }
    //	else
    //	AddFirst(l, new_ele);
}

void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
    }
}

void RemoveLast(List &l)
{
    if (l.pTail != NULL)
    {
        Node *p = l.pHead;
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
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->Info.id == idx)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == l.pTail)
            l.pTail = q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return 1;
}

void InputNode(List &l)
{
    Person p;
    printf("Nhap thong tin nguoi:\n");
    printf("ID: ");
    scanf("%d", &p.id);
     fflush(stdin);
    printf("First name: ");
    gets(p.fname);
    fflush(stdin);
    printf("Last name: ");
    gets(p.lname);

    Node *new_node = GetNode(p);

    int idx;
    printf("Nhap vi tri can them: ");
    scanf("%d", &idx);

    AddNodeAfter(l, idx-1, new_node);

    printf("Da them nguoi vao danh sach!\n");
}


int main()
{
    struct Person per1 = {1, "giap", "at"};
    struct Person per2 = {2, "binh", "dinh"};
    struct Person per3 = {3, "mau", "ky"};
    struct Person per4 = {4, "canh", "tan"};
    struct Person per5 = {5, "nham", "quy"};
   
    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);

    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele3);

    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele4);

    PrintList(my_list);

    printf("**************************************************************\n");

    int idx;
    printf("Nhap id :");
    scanf("%d", &idx);

    Node *node_kq =
        FindNodeByID(my_list, idx);
    if (node_kq != NULL)
    {
        PrintNode(node_kq);
        printf("**************************************************************\n");
    }
    else
    {
        printf("Khong tim thay id %d\n", idx);
        printf("**************************************************************\n");
    }

    Node *new_ele5 = GetNode(per5);
    AddNodeAfter(my_list, idx, new_ele5);

    printf("Sau khi them nut : \n");
    printf("\n");
    PrintList(my_list);

    RemoveHead(my_list);
    printf("**************************************************************\n");
    printf("Sau khi xoa nut dau : \n");
    printf("\n");

    PrintList(my_list);

    RemoveLast(my_list);
    printf("**************************************************************\n");
    printf("Sau khi xoa nut cuoi : \n");
    printf("\n");

    PrintList(my_list);


    printf("Nhap id can xoa:");
    scanf("%d", &idx);
    RemoveNode(my_list, idx);
    printf("**************************************************************\n");
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);
    
    InputNode(my_list);
    PrintList(my_list);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> b8140ab904ab6152d12532e648e1379e71b9184d
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
>>>>>>> 347f9951992dfdbf98060bb69330328ea236a3cd
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
>>>>>>> 47d9a4f2cbf417b7cc90d9c81d4043f3d95e9217
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
>>>>>>> 9fe68217ae5ccfac5030a3ef4c9baa2df4779813
=======
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
=======
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
=======
<<<<<<< HEAD
	struct Person per1 = {1, "Thao" , "Di" };
	struct Person per2 = {2, "Tieu" , "Vy" };
	struct Person per3 = {3, "Han" , "Tin" };
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
	struct Person per1={1,"Tieu","Vy"};
	struct Person per2={1,"Thao","Di"};
	struct Person per3={1,"Han","Tin"};
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
	
	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	Node* new_ele3 = GetNode(per3);
	
	List mylist;
	Init(mylist);
	
	AddFirst(mylist, new_ele1);
	AddFirst(mylist, new_ele2);
	AddFirst(mylist, new_ele3);	
	
	PrintList(mylist);
	
	return 0;
=======
>>>>>>> 4e5a62c4974b0bfc73948b764429946ebc1f5461
=======
    return 0;
<<<<<<< HEAD
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
}
<<<<<<< HEAD
>>>>>>> 8e63614c252e774f190db70f99fc78ad49aea3e1
=======
<<<<<<< HEAD
>>>>>>> ac67c5a3029941dc8b236826380a711232d27631
=======
>>>>>>> 8e63614c252e774f190db70f99fc78ad49aea3e1
>>>>>>> c502d85257d060c87e9d78f08e987cc2b381e655
>>>>>>> 6a81b0e94e76b735ddbad8782a57a3f06b06736b
