#include <stdio.h>
#include <stdlib.h>

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
    Node* pNext;
} Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
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
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele->pNext == l.pHead;
        l.pHead = new_ele;
    }
}

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

x

int main()
{
    struct Person per1 = {1, "Kim" , "Tri" };
	struct Person per2 = {2, "Thach" , "Minh" };

    List* my_list;
    Init(&l);
    Node* node1 = GetNode(per1);
    AddFirst(my_list, node1);

    // Add an element after the first
    Node* node2 = GetNode(per2);
    AddAfter(my_list, my_list.pHead, node2);

    // Add an element to the end of the list
    Node* node3 = GetNode(per3);
    AddTail(my_list, node3);

    // Add an element after the second
    Node* node4 = GetNode(per4);
    AddAfter(my_list, my_list.pHead->pNext, node4);

    // Print the list
    Node* node = my_list.pHead;
    while (node != NULL) {
        printf("%d %s %s\n", node->Info.id, node->Info.fname, node->Info.lname);
        node = node->pNext;
    }



    return 0;
}