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
} Person;
=======
}Person;
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

typedef struct Node
{
    Person Info;
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

Node* GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFist(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
<<<<<<< HEAD
        new_ele->pNext == l.pHead;
        l.pHead = new_ele;
    }
}
=======
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

void AddTail(List &l, Node *new_ele)
{
    if(l.pHead==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else{
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

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



void PrintList(List l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

Node* SearchList(List l, int id)
{
    Node* node = l.pHead;
    while (node != NULL)
    {
        if (node->Info.id == id)
        {
            return node;
        }
        node = node->pNext;
    }
    return NULL;
}

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

    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);


    PrintList(my_list);

    Node* found_node = SearchList(my_list, 2);
    if (found_node != NULL)
    {
        printf("%d %s %s\n", found_node->Info.id, found_node->Info.fname, found_node->Info.lname);
    }
    else
    {
        printf("Node not found!\n");
    }

>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

    return 0;
}
