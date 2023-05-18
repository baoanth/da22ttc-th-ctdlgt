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
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
} Person;
=======
}Person;
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
} Person;
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
} Person;
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
=======
} Person;
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a

typedef struct Node
{
    Person Info;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
<<<<<<< HEAD
=======
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d

Node *GetNode(Person x)
{
    p = new Node;
    if (p == NULL)
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
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b

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
<<<<<<< HEAD
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a

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
<<<<<<< HEAD
<<<<<<< HEAD
    if (l.pHead ==NULL)
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
<<<<<<< HEAD
=======
=======
    if (l.pHead == NULL)
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    if (l.pHead == NULL)
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
    if (l.pHead ==NULL)
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
    if (l.pHead == NULL)
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
        new_ele->pNext == l.pHead;
        l.pHead = new_ele;
    }
}
=======
        new_ele ->pNext = l.pHead;    
=======
        new_ele->pNext = l.pHead;
<<<<<<< HEAD
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
        new_ele->pNext = l.pHead;
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
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
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
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
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
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
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

<<<<<<< HEAD
Node *FindNodeByID(List l, int id)
{
    Node *node = l.pHead;
    while (node != NULL)
    {
        if (node->Info.id == id)
        {
            return node;
        }
        node = node->pNext;
    }
    return NULL;
=======
void PrintNode(Node* p)
{
	printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
    p = p->pNext;
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a

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
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
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
<<<<<<< HEAD
=======
int main()
{
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
<<<<<<< HEAD
    struct Person per4 = {4, "Thach" , "Tri" };
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
int main()
{
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
    struct Person per1 = {1, "Kim", "Tri"};
    struct Person per2 = {2, "Thach", "Minh"};
    struct Person per3 = {3, "Kim", "Minh"};
    struct Person per4 = {4, "Thach", "Tri"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a

    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele1);  
    AddFist(my_list, new_ele3);
<<<<<<< HEAD

=======
    
	AddTail(my_list, new_ele2);
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
    AddTail(my_list, new_ele4);

    PrintList(my_list);

    printf("**************************************************************\n");
	
<<<<<<< HEAD
<<<<<<< HEAD
	int id;
	printf("Nhap id :");
	scanf("%d",&id);
	
    Node *found_node = FindNodeByID(my_list, id);
    if (found_node != NULL)
    {
        printf("%d %s %s\n", found_node->Info.id, found_node->Info.fname, found_node->Info.lname);
    }
    else
    {
        printf("Node not found!\n");
    }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
	int idx;
	printf("Nhap id :");
	scanf("%d",&idx);
	
<<<<<<< HEAD
    Node *found_node = FindNodeByID(my_list, id);
    if (found_node != NULL)
    {
        printf("%d %s %s\n", found_node->Info.id, found_node->Info.fname, found_node->Info.lname);
    }
    else
    { 
        printf("Node not found!\n");
<<<<<<< HEAD
    }*/
=======
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
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d

<<<<<<< HEAD
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d
=======
    }
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28

<<<<<<< HEAD
=======
=======
>>>>>>> d2bbc63055582a14f4528f31452d82c3e6017204
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
    return 0;
}