#include <stdio.h>
#include <conio.h>
#include <string.h>
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
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho");
        return NULL;
    }
    p -> Info = x;
    p -> pNext = NULL;
    return p;
}

void AddFirst (List &l, Node* new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead= new_ele;
		l.pTail= l.pHead;
	}
  else
	{
		new_ele -> pNext = l.pHead;
		l.pHead =  new_ele ;
	}
}		

void AddTail (List &l, Node* new_ele)	
{
	if (l.pHead==NULL)
	{
		l.pHead= new_ele;
		l.pTail= l.pHead;
	}
  else
	{
		l.pTail -> pNext = new_ele;
		l.pTail = new_ele;
	}
}


Node* FindNodeByID(List l, int idx)
{
    Node *p;
    p =l.pHead;

    while ((p!=NULL) && (p -> Info.id !=idx))
        p = p->pNext;

    return p;
}

void Init( List &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintNode(Node *p)
{
	printf("5%d %s  %s\n",p->Info.id,p->Info.fname,p->Info.lname);
}	

void PrintList(List &l)
{
	Node* p;
	p= l.pHead;
	while(p !=NULL)
	{
	printf("%5d %s %s\n",p->Info.id,p->Info.fname,p->Info.lname);
		p=p->pNext;
	}
}

void AddNodeAfter(List &l, int idx, Node *new_ele5)
{
	 Node *q = FindNodeByID(l, idx);

    if (q != NULL && new_ele5 != NULL)
    {
        new_ele5->pNext = q->pNext;
        q->pNext = new_ele5;
        if (q == l.pTail)
            l.pTail = new_ele5;
    }
    else
        AddFirst(l, new_ele5);
}


void RemoveHead(List &l)
{
    if (l.pHead != NULL)
    {
        Node *p = l.pHead;
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
    }
}


void RemoveLast(List &l)
{
    if (l.pTail != NULL)
    {
        Node *p = l.pHead;
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

int RemoveNode(List &l,int idx)
{
    Node *p = l.pHead;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->Info.id == idx)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == l.pTail)
            l.pTail = q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return 1;
}
 
void InputNode(List &l)
{
    Person p;
    printf("Nhap thong tin nguoi:\n");
    printf("ID: ");
    scanf("%d", &p.id);
    fflush(stdin);
    printf("First name: ");
    gets(p.fname);
    fflush(stdin);
    printf("Last name: ");
    gets(p.lname);

    Node *new_node = GetNode(p);

    int idx;
    printf("Nhap vi tri can them: ");
    scanf("%d", &idx);

    AddNodeAfter(l, idx - 1, new_node);

    printf("Da them nguoi vao danh sach!\n");

}

int main()
{
    struct Person per1 = {1, "Nguyen", "Tran" };
	struct Person per2 = {2, "Huyen", "Tran" };
	struct Person per3 = {3, "Nguyen", "Tong" };
	struct Person per4 = {4, "Nguyen Thi Huyen", "Tran" };
	struct Person per5 = {5, "Nguyen Ke", "Tong" };
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    Node* new_ele4  = GetNode(per4);
    Node* new_ele5  = GetNode(per5);
    
    List my_list;
    Init(my_list);

	AddFirst(my_list, new_ele1);
	AddFirst(my_list, new_ele3);
	
    AddTail(my_list, new_ele2);
    AddTail(my_list, new_ele4);
    
    PrintList(my_list); 


    int idx;
        printf ("Nhap id can tim: ");
        scanf("%d", &idx);
        printf("\n");
        Node* kq = FindNodeByID(my_list, idx);		
    if (kq!=NULL)
    {
        PrintNode(kq);
    }
    else 
	{  
        printf("\nTim khong thay node co id %d", idx);	
    }   
         
    AddNodeAfter(my_list, idx, new_ele5);

    printf("Sau khi them nut : \n");
    printf("\n");
    PrintList(my_list);
        
    RemoveHead(my_list);     
    printf("Sau khi xoa nut dau : \n");
    printf("\n");

    PrintList(my_list);

    RemoveLast(my_list);
    printf("Sau khi xoa nut cuoi : \n");
    printf("\n");

    PrintList(my_list);

    printf("Nhap id can xoa:");
    scanf("%d", &idx);
    RemoveNode(my_list, idx);
     
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);

    InputNode(my_list);
     
    printf("Sau khi thuc hien thao tac : \n");
    printf("\n");
    PrintList(my_list);
 
    return 0;
}






