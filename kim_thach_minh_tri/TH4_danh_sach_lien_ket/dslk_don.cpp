#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>

=======
#include <conio.h>
#include <string.h>
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
<<<<<<< HEAD
<<<<<<< HEAD
} Person;
=======
}Person;
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
} Person;
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204

typedef struct Node
{
    Person Info;
<<<<<<< HEAD
<<<<<<< HEAD
    Node* pNext;
} Node;
=======
    Node* pNext;    
}Node;
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

typedef struct List
{
    Node* pHead;
    Node* pTail;
<<<<<<< HEAD
} List;

Node* GetNode(Person x)
{
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho !");
        return NULL;
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
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204

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
<<<<<<< HEAD
    if (l.pHead ==NULL)
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
    if (l.pHead == NULL)
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
        new_ele->pNext == l.pHead;
        l.pHead = new_ele;
    }
}
=======
        new_ele ->pNext = l.pHead;    
=======
        new_ele->pNext = l.pHead;
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
        l.pHead = new_ele;
    }
}
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
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
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

void PrintNode(Node* p)
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

<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

int main()
{
    struct Person per1 = {1, "Kim" , "Tri" };
<<<<<<< HEAD
	struct Person per2 = {2, "Thach" , "Minh" };

    List* my_list;
    Init(&l);

    Node* new_ele1 = GetNode(per1);
    AddFirst(my_list, node1);

    Node* node1 = GetNode(per2);
    AddFirst(my_list, node2);

    
=======
    struct Person per2 = {2, "Thach" , "Minh" };
    struct Person per3 = {3, "Kim" , "Minh" };
=======
int main()
{
    struct Person per1 = {1, "Kim", "Tri"};
    struct Person per2 = {2, "Thach", "Minh"};
    struct Person per3 = {3, "Kim", "Minh"};
    struct Person per4 = {4, "Thach", "Tri"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204

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
	scanf("%d",&idx);
	
   Node* node_kq =
    FindNodeByID(my_list, idx);
   if(node_kq != NULL)
   {
    PrintNode(node_kq);
   }
   else
   {
    printf("Khong tim thay id %d",idx);
   }

<<<<<<< HEAD
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
    return 0;
}
