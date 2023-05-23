<<<<<<< HEAD

#include <stdio.h>
=======
<<<<<<< HEAD
=======
  #include <stdio.h>
>>>>>>> 594e5729e738585b58519f9084fbcd81c77519ca
#include <conio.h>
>>>>>>> e747f3b24ff3f201c0528826f0cc7e0e6f0a9e11
#include <string.h>
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

void AddTail(List &l, Node *new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail= l.pHead;
	}
	else
	{
		l.pTail->pNext =new_ele;
		l.pTail=new_ele;
	}
} 

void AddNodeAfter(List &l, Node *q, Node *new_ele)
{
	if( q!=NULL)
	{
		new_ele->pNext =q->pNext;
		q->pNext = new_ele;
		if(q==l.pTail)
			l.pTail= new_ele;
	}
	else
	 AddFirst(l, new_ele);
}


void RemoveHead(List &l)
{
	Node *p;

	if (l.pHead !=NULL)
	 {
	 	p= l.pHead ;
	 	l.pHead= l.pHead->pNext;
		delete p;
		if (l.pHead==NULL)
		    l.pTail= NULL;
	 }
}	 

void RemoveAfter(List &l, Node *q)
{
	Node *p;
	if(q!= NULL)
	{
		p=q ->pNext;
		if(p !=NULL)
		{
			if (p==l.pTail)
				l.pTail= q;
			q->pNext =p->pNext;
			delete p;
		}
	}
	else 
	RemoveHead(l);
}

int RemoveNode (List &l, int idx)
{
	
   	Node *p=l.pHead;
   	Node *q=NULL;
   	while(p!=NULL)
   	{
   		if(p ->Info.id == idx) break;
   		q = p; p=p->pNext;
   	}
		if(p==NULL) return 0; 
		printf("Ko thay Node co id can tim = %d",idx);
   		if(q != NULL)
   	{
   		if (p==l.pTail)
   			l.pTail = q;
   		q->pNext = p->pNext;
   		delete p;
   	}
   	else 
   	{
   		l.pHead= p->pNext;
   		if(l.pHead == NULL)
   			l.pTail== NULL;
   	}
   	return 1;
   	
}

Node* FindNodeByID (List l, int idx)
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL)&& (p->Info.id !=idx))
		p=p->pNext;
	
	return p;	
	
=======
void AddTail(List &l, Node* new_ele)
{
	if(l.pHead==NULL)
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

void RemoveHead(List &l, int idx)
{
	Node *p;
	if (l.pHead  != NULL)
	{
		p = l.pHead; 
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL) l.pTail = NULL;
	}
} 

void RemovoAfter ( List &l, Node *q)
{
	Node *p;
	if ( q != NULL)
	{
		p = q ->pNext;
		if (p ! = NULL)
		{
			if (p== l.pTail)
		 		l.pTail = q;
			q->pNext = p->pNext;
			delete p;	
		} 
	else
	
		RemoveHead(l);
	}
}
int RemoveNode (List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	while( p! = NULL)
	{
		if (p->Info == k) break;
		q = p; p = p->pNext;
	}
	if(p == NULL) return 0;
	if(q != NULL)
	{
		if(p == l.pTail)
			l.pTail = q;
			p->pNext = p->pNext;
			delete p;
	}
	else
	{
		l.Head = p->pNext;
		if(l.pHead == NULL)
			l.pTail = NULL;
	}
	return 1;
}


Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p =l.pHead;
	while((p!=NULL) && ( p->Info.id !=idx ))
	p = p-> pNext;
	return p;
>>>>>>> e747f3b24ff3f201c0528826f0cc7e0e6f0a9e11
}

void Init(List &l)
{
	l. pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("%5d  %20s  %20s\n",p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List &l)
{
	if (l. pHead ==NULL)
	{
		printf(" Danh sach trong\n");
	}
	else
	{
		Node *p;
		p = l.pHead;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext; 
		}
	}
}
int main()
{

	struct person per1 = {1, "Yen", "Vo" };
	struct person per2 = {2, "Hong", "Nguyen" };
	struct person per3 = {3 , "Dung", "Tran" };

	Node* new_ele1 = GetNode(per1);
	Node* new_ele2 = GetNode(per2);
	Node* new_ele3 = GetNode(per3);
	List my_list;
	Init(my_list);
	
<<<<<<< HEAD
	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
	AddTail(my_list, new_ele3);
=======
<<<<<<< HEAD
	AddFist(my_list, new_ele1);
	AddFist(my_list, new_ele2);
	
	PrintList(my_list);
<<<<<<< HEAD
<<<<<<< HEAD
=======
	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
>>>>>>> 2a7947e254789dee86141976d0ac7ff00a60444a
=======
	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
=======
>>>>>>> 70bbb6f9dd7dbe79db9df453a7ea5c8be6dd02ec
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
return 0;
=======
	AddTail(my_list, new_ele1);
	AddTail(my_list, new_ele2);
>>>>>>> e747f3b24ff3f201c0528826f0cc7e0e6f0a9e11
	
	PrintList(my_list);
	
	int idx;
<<<<<<< HEAD
	printf("\nNhap id can tim: ");
	scanf("%d",&idx);
	Node* KQ=FindNodeByID (my_list, idx);
		if(KQ != NULL) PrintNode(KQ);
		else
		 printf("\nTim ko thay Node co id %d", idx);
		 
	printf("\nNhap id muon xoa :");
	scanf("%d", &idx);
	int kq=RemoveNode(my_list, idx);
	if (kq !=0)
		printf("\nDa xoa Node co id = %d",idx);
		printf("Danh sach sau thao tac \n");
	PrintList(my_list);	

return 0;
=======
	scanf("%d", &idx);
   	printf("\n nhap id can tim  ");
	printf("\n");
    Node* kq = FindNodeByID( my_list, idx);
	if ( kq != NULL)
    	PrintNode(kq);
	else 
		printf("Tim khong thay node co id \n  %d",idx);   
	
    return 0;
<<<<<<< HEAD
>>>>>>> 23ffe3f67ad4e1fb00aaef81241a1894c18d4867
=======
>>>>>>> d6302ece61a6dba59df57133f5a722db35bfa133
>>>>>>> c1af93f3f198b3d672135fceeddfc247ee92151a
}





 
/*void AddFirst (DList &l, DNode* new_ele)
{
	if (l.Head==NULL)
	{
		l.pHead = new_ele;
		l.pHead = l.Head;
	}
	else
	{
		new_ele->pNext = l.Head;
		l.Head ->pPev = new_ele;
		l.Head = new_ele; 
	}
}
NODE* InsertHead(DList &l, Data x)
{
	NODE* new_ele = GetNode (x);
	if (new_ele==NULL) return NULL;
	if ( l.pHead==NULL)
	{
		L. pHead = new_ele;
		l.pTail = l. pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.Head ->pPrev = new_ele ;
		l.Head = new_ele;
	}
	return new_ele;
}*/



	






>>>>>>> e747f3b24ff3f201c0528826f0cc7e0e6f0a9e11
