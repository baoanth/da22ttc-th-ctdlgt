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

void AddFist(List &l, Node* new_ele)
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
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d


int main()
{
    struct Person per1 = {1, "Nguyen", "Thong" };
	struct Person per2 = {2, "Huynh", "Nhan" };
	struct Person per3 = {3, "Pham", "Vinh" };
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele3);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    PrintList(my_list);

=======
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
<<<<<<< HEAD
    PrintList(my_list);

=======
    PrintList(my_list);

>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    PrintList(my_list);

>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
    return 0;


}
=======

} 
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 3b3270c5029c69abffff531b504dec023a307d35
=======
>>>>>>> 746df14f0e5d95d461172bd037c2b85fca5d532d
>>>>>>> 5a1f1f644d05c13365b1e7efdcb95d4b8d623df0
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
