
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
#include <stdlib.h>

=======
#include <conio.h>
#include <string.h>
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
#include <conio.h>
#include <string.h>
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
#include <stdio.h>
#include <conio.h>
#include <string.h>
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
} Person;
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
} Person;
=======
}Person;
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
} Person;
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

typedef struct Node
{
    Person Info;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    Node* pNext;
} Node;
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
    Node* pNext;
} Node;
=======
    Node* pNext;    
}Node;
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b

typedef struct List
{
    Node* pHead;
    Node* pTail;
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
} List;

Node* GetNode(Person x)
{
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho !");
        return NULL;
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
    }
    p->Info = x;
    p->pNext = NULL;
    return p;   
}

void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead == NULL)
=======
}List;
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;
<<<<<<< HEAD
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
    }
    p->Info = x;
    p->pNext = NULL;
    return p;   
}

<<<<<<< HEAD
<<<<<<< HEAD
void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead == NULL)
=======
}List;
=======
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50

Node *GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
    }
    p->Info = x;
    p->pNext = NULL;
    return p;   
}

<<<<<<< HEAD
void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead == NULL)
=======
void AddFist(List &l, Node *new_ele)
{
=======
void AddFist(List &l, Node *new_ele)
{
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
    if (l.pHead ==NULL)
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
    if (l.pHead == NULL)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
void AddFirst(List &l, Node *new_ele)
{
    if (l.pHead == NULL)
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        new_ele->pNext == l.pHead;
        l.pHead = new_ele;
    }
}
=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
        new_ele->pNext == l.pHead;
        l.pHead = new_ele;
    }
}
=======
        new_ele ->pNext = l.pHead;    
=======
        new_ele->pNext = l.pHead;
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
        new_ele->pNext = l.pHead;
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
        l.pHead = new_ele;
    }
}
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50

=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======

=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void AddAfter(List &l,Node *q, Node* new_ele)
{
		if (q!=NULL && new_ele !=NULL)  
		{
			new_ele->pNext = q->pNext;
			q->pNext = new_ele; 	
			if(q == l.pTail)
					l.pTail = new_ele; 
		}
		else
			AddFirst(l,new_ele);
}


void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void ProcessList (List &l)
{	
	Node	*p;	
	p = l.pHead;
	while (p!= NULL){ 
     ProcessNode(p); // xử lý cụ thể tùy ứng dụng
     p = p->pNext;
	}
}

void Output(List l)
{
		Node* p=l.pHead;
		while(p!=NULL)
		{
			//In các thành phần của 
			p=p ->pNext;
		}
} 

=======
<<<<<<< HEAD
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
<<<<<<< HEAD
void AddAfter(List &l,Node *q, Node* new_ele)
{
		if (q!=NULL && new_ele !=NULL)  
		{
			new_ele->pNext = q->pNext;
			q->pNext = new_ele; 	
			if(q == l.pTail)
					l.pTail = new_ele; 
		}
		else
			AddFirst(l,new_ele);
}


void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

void ProcessList (List &l)
{	
	Node	*p;	
	p = l.pHead;
	while (p!= NULL){ 
     ProcessNode(p); // xử lý cụ thể tùy ứng dụng
     p = p->pNext;
	}
}

void Output(List l)
{
		Node* p=l.pHead;
		while(p!=NULL)
		{
			//In các thành phần của 
			p=p ->pNext;
		}
} 

=======



=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
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

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b

int main()
{
    struct Person per1 = {1, "Kim" , "Tri" };
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
	struct Person per2 = {2, "Thach" , "Minh" };
=======
Node *FindNodeByID(List l, int idx)
{
    Node *p = l.pHead;
    while ((p != NULL) && (p->Info.id != idx))
    {
        p = p->pNext;
    }
    return p;
}
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

void AddNodeAfter(List &l, int idx, Node *new_ele5)
{
    Node *q = FindNodeByID(l, idx);

    if (q != NULL && new_ele5 != NULL)
    {
        new_ele5->pNext = q->pNext;
        q->pNext = new_ele5;
        if (q == l.pTail)
            l.pTail = new_ele5;
    }
    else
        AddFirst(l, new_ele5);
}

<<<<<<< HEAD
    Node* node1 = GetNode(per2);
    AddFirst(my_list, node2);
<<<<<<< HEAD
<<<<<<< HEAD

    
=======
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b

    
=======
    struct Person per2 = {2, "Thach" , "Minh" };
    struct Person per3 = {3, "Kim" , "Minh" };
<<<<<<< HEAD
<<<<<<< HEAD
    struct Person per4 = {4, "Thach" , "Tri" };
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
=======
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

    AddNodeAfter(l, idx - 1, new_node);

    printf("Da them nguoi vao danh sach!\n");
}

>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
int main()
{
    struct Person per1 = {1, "Kim", "Tri"};
    struct Person per2 = {2, "Thach", "Minh"};
    struct Person per3 = {3, "Kim", "Minh"};
    struct Person per4 = {4, "Thach", "Tri"};
    struct Person per5 = {5, "Kim", "MinhTri"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    Node *new_ele5 = GetNode(per5);
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele3);

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
<<<<<<< HEAD
    { 
        printf("Node not found!\n");
<<<<<<< HEAD
    }*/

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
=======
    }
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 12873f93a066a8eddcaa685309c27dac913e12da

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    {
        printf("Khong tim thay id %d\n", idx);
        printf("**************************************************************\n");
    }

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
    printf("**************************************************************\n");
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    return 0;
}
