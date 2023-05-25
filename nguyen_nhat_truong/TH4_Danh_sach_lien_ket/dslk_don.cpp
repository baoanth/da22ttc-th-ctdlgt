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
<<<<<<< HEAD
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
=======
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
>>>>>>> 1305e46ad47d5f841f9874c1605b5d32a477f3f7
}

void AddFirst(List &l, Node* new_ele)
{
<<<<<<< HEAD
    if (l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        new_ele->pNext = l.pHead;
        l.pHead = new_ele;
    }
}

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
=======
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
>>>>>>> 1305e46ad47d5f841f9874c1605b5d32a477f3f7
}

void PrintNode(Node *p)
{
    printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
}

void PrintList(List l)
{
    printf("\n");
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("%d %s %s\n", p->Info.id, p->Info.fname, p->Info.lname);
        p = p->pNext;
    }
}

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
Node *FindNodeById(List l, int idx)
{
    Node *p = l.pHead;
    while (p != NULL && p->Info.id != idx)
        p = p->pNext;
    return p;
}

void AddNodeAfter(List &l, int idx, Node *new_ele4)
{
    Node *q = FindNodeById(l, idx);
    if (q != NULL && new_ele4 != NULL)
    {
        new_ele4->pNext = q->pNext;
        q->pNext = new_ele4;
        if (q == l.pTail)
            l.pTail = new_ele4;
    }
    else
        AddFirst(l, new_ele4);
}

void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if(l.pHead == NULL) l.pTail == NULL;
        delete p;
    }
}

void RemoveLast(List &l)
{
    if (l.pTail != NULL)
    {
        Node *p = l.pTail;
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
    Node *q;
    while(p != NULL)
    {
        if(p->Info.id == idx) break;
        p = p->pNext;
    }
    if(p == NULL)
        return 0;
    q = p->pNext;
    if(q != NULL)
    {
        p = q ->pNext;
        if(p != NULL)
        {
            q->pNext = p->pNext;
            if(p == l.pTail)
                l.pTail = q;
            else   
                p->pNext = q;
        }
    }
    else 
    {
        l.pHead = p->pNext;
        if(l.pHead == NULL)
            l.pTail == NULL;
        else    
            l.pHead == NULL;
    }
    delete p;
    return 1;
}

void InputNode(List &l)
{
    struct Person new_per;
    printf("\nVui long nhap id: ");
    scanf("%d", &new_per.id);
    printf("\nVui long nhap fname: ");
    scanf("%s", &new_per.fname);
    printf("\nVui long nhap lname: ");
    scanf("%s", &new_per.lname);
    
    Node *new_ele = GetNode(new_per);
    int vi_tri;
    printf("\nCan them vao vi tri nao: ");
    scanf("%d", &vi_tri);
    AddNodeAfter(l, vi_tri, new_ele);

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
>>>>>>> 1305e46ad47d5f841f9874c1605b5d32a477f3f7
}

int main()
{
<<<<<<< HEAD
    struct Person per1 = {1, "Nguyen", "Truong"};
    struct Person per2 = {2, "Con", "Bang"};
    struct Person per3 = {3, "Han", "Tin"};
    struct Person per4 = {4, "Raiden", "Shogun"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    Node *new_ele4 = GetNode(per4);

=======
	struct person per1 = {1, "Vy", "Truong"};
	struct person per2 = {2, "Thao", "Vy"};
	struct person per3 = {3, "Truong", "Nguyen"};
	 
 	Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
  	Node* new_ele3  = GetNode(per3);
   
>>>>>>> 1305e46ad47d5f841f9874c1605b5d32a477f3f7
    List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddTail(my_list, new_ele2);
<<<<<<< HEAD
    AddFirst(my_list, new_ele3);

=======
>>>>>>> 1305e46ad47d5f841f9874c1605b5d32a477f3f7
    PrintList(my_list);
    
	int idx;
	printf("\nNhap vi tri ID can chen vao sau no : ");
	scanf("%d",&idx);
    AddNodeAfter(my_list, idx, new_ele3);
    
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

<<<<<<< HEAD
    
    int idx;
    printf("\nNhap id can tim: ");
    scanf("%d", &idx);
    Node *tim_kiem = FindNodeById(my_list, idx);
    if (tim_kiem != NULL)
        PrintNode(tim_kiem);
    else
        printf("Khong tim thay nut co id %d", idx);
    
    printf("\nNhap id can chen phia sau: ");
    scanf("%d", &idx);

    AddNodeAfter(my_list, idx, new_ele4);

    PrintList(my_list);

    RemoveHead(my_list);
    printf("\n Xoa nut dau");
    PrintList(my_list);

    RemoveLast(my_list);
    printf("\n Xoa nut cuoi");
    PrintList(my_list);

    printf("\nNhap id can xoa: ");
    scanf("%d", &idx);
    int kq = RemoveNode(my_list,idx);
    if(kq == 1)
    PrintList(my_list);
    

    InputNode(my_list);
    PrintList(my_list);

    return 0;
}
=======
	
	return 0;
}

>>>>>>> 1305e46ad47d5f841f9874c1605b5d32a477f3f7
