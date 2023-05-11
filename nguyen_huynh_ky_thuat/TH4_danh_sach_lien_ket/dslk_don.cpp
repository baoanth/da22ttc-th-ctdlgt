#include <stdio.h>
#include <stdlib.h>


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
    		printf("Khong du bo nho cap phat cho nut moi");
    		return NULL;
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
    
    void Init(List &l)
    {
    	l.pHead = l.pTail = NULL;
    }
    
    void PrintList(List&l)
    {
    	if(l.pHead == NULL)
    	{
    		printf("Danh sach rong\n");
    	}
    	else
    	{
    		Node *p;
    		p = l.pHead;
    		while (p!=NULL)
    		{
    			printf("%5d %20s %20s\n", p->Info.id,p->Info.fname, p->Info.lname);
    			p = p->pNext;
    		}
    	}
    }
    int main()
    {
    	struct Person per1 = {1, "Nguyen","Huynh Ky Thuat"};
    	struct Person per2 = {2, "Do","Thien Vu"};
    	struct Person per3 = {3, "Duong","Chi Minh"};
    	
    	Node* new_ele1 = GetNode(per1);
    	Node* new_ele2 = GetNode(per2);
    	Node* new_ele3 = GetNode(per3);
    	List my_list;
    	Init(my_list);
    	
    	AddFirst(my_list, new_ele1);
    	AddFirst(my_list, new_ele2);
    	AddFirst(my_list, new_ele3);
    	
    	PrintList(my_list);
    	
    }
