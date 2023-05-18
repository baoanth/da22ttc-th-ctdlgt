#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int id;
    char fname[20];
    char lname[20];
}person;

typedef struct Node
{
	person Info;
	Node* pNext;
}Node;

typedef struct List
{
	Node* pHead;
	Node* pTail;
}List;

Node* GetNode(person x)
{
	Node *p;
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
		l.pTail  = l.pHead;
	}
	else 
	{	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
=======
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a

=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
=======
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
Node* FindNodeByID (List l, int idx)
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL)&& (p->Info.id !=idx))
		p=p->pNext;
	
	return p;	
	
}

void AddNodeAfter(List &l, int idx, Node *new_ele)
{
	Node *q;
	q= FindNodeByID(l,idx);
	if ( q!=NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if(q == l.pTail)
			l.pTail = new_ele;
	}
	else 
		AddFirst(l, new_ele);
}
    
void RemoveHead(List &l)
{
	Node *p;
		
	if ( l.pHead != NULL)
	{
		p = l.pHead; 
		l.pHead = l.pHead->pNext;
		delete p;
		if(l.pHead == NULL) l.pTail = NULL;
	}
}
    
void RemoveLast(List &l, Node *q)
{
	Node *p;
	
	if ( q != NULL)
	{
		p = q ->pNext ;
		if ( p != NULL)
	{
	if(p == l.pTail)
		l.pTail = q;
	q->pNext = p->pNext;
	delete p;
	}
}
	else
		RemoveHead(l);
}
	
void RemoveNode(List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	
	while( p != NULL)
	{
		if(p->Info.id == idx) break;
		q = p; 
		p = p->pNext;
	}
	 
	if(q != NULL)
	{
		if(p == l.pTail)
		l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	else 
	{
		l.pHead = p->pNext;
		if(l.pHead == NULL)
			l.pTail = NULL;
		
	}

}	
	
<<<<<<< HEAD
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%3d | %20s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
	Node *p;
	p = l.pHead;
	
	while (p!= NULL)
	{
		printf("%3d | %20s | %10s\n",p->Info.id, p->Info.fname, p->Info.lname);
		p = p->pNext;
	}
}

int main()
{
	struct person per1 = {1, "Le Xuan", "Truong"};
	struct person per2 = {2, "Thach Thi Hue", "Trinh"};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
=======
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
	
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
	struct person per3 = {3, "Le Thach Hue", "Meo"};

=======
	struct person per3 = {3, "Le Thach Xuan", "Meo"};
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======

=======
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
   
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    AddFirst(my_list, new_ele2);
=======
<<<<<<< HEAD
<<<<<<< HEAD
    AddTail(my_list, new_ele2);
=======
=======
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    AddTail(my_list, new_ele2);
<<<<<<< HEAD
    AddTail(my_list, new_ele3);
   
=======
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
<<<<<<< HEAD
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    AddTail(my_list, new_ele2);
=======
<<<<<<< HEAD
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    AddFirst(my_list, new_ele2);
=======
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> b383becc58d4c9cd8508517a2d8a395dd3c6d6d7
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
=======
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele3);
>>>>>>> 9c62531f1cfae60fcb086841383235521fa3e424
>>>>>>> 334655d424bda68a9d41827a76714eab9247231d
=======
<<<<<<< HEAD
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
=======
>>>>>>> 52101222854229aae11bba57ee85bfbcd88c7e28
<<<<<<< HEAD
>>>>>>> 0db6543df8aa9c1bd51ecbe5b15e3f1306d01f50
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
=======
    AddTail(my_list, new_ele2);
    PrintList(my_list);
    
	int idx;
	printf("\nNhap vi tri ID can chen vao sau no : ");
	scanf("%d",&idx);
    AddNodeAfter(my_list, idx, new_ele3);
<<<<<<< HEAD
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
    
	PrintList(my_list);
	
	printf("\nNhap ID can tim : ");
	scanf("%d",&idx);
	printf("\n");
	Node* KQ = FindNodeByID(my_list, idx);
	if(KQ != NULL)
		PrintNode(KQ);
	else
		printf("\nKhong tim thay Node co ID : %d",idx);	
	
	printf("\nNhap ID can xoa : ");
	scanf("%d",&idx);
	
	printf("\nSau khi xoa ID %d : \n", idx);
//	RemoveHead(my_list);
//	RemoveLast(my_list, KQ);
	RemoveNode(my_list, idx);
	PrintList(my_list);

	
	return 0;
}

