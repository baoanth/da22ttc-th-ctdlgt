#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
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

void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}

void AddTail(List &l, Node* new_ele)
{
    if (l.pHead==NULL)
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

Node* FindNodeByID(List l, int idx)
{
    Node *p;
    p =l.pHead;

    while ((p!=NULL) && (p->Info.id !=idx))
        p = p->pNext;

    return p;
}



void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

<<<<<<< HEAD
<<<<<<< HEAD
void PrintNode(Node *p)
{
    printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
}

=======
<<<<<<< HEAD
>>>>>>> 0c281b7846b87694a39cb32b4f8c6d9e0b7e1017
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d


int main()
{
    struct Person per1 = {1, "Nguyen", "Le Hoa Binh" };
	struct Person per2 = {2, "Le", "Binh" };
	struct Person per3 = {3, "Tran", "Hoa" };
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

	//AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);

<<<<<<< HEAD
	
    AddTail(my_list, new_ele1);
    //AddTail(my_list, new_ele2);
    //AddTail(my_list, new_ele3);

<<<<<<< HEAD
    PrintList(my_list);
    int idx;
    printf("\nNhap id can tim ");
    scanf("%d", &idx);
    Node *node_kq  = FindNodeByID(my_list, idx);
    if (node_kq!=NULL)
        PrintNode(node_kq);
    else   
        printf("Tim khong thay node co id %d", idx);
=======
<<<<<<< HEAD
    PrintList(my_list);
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b

    return 0;

=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

}
