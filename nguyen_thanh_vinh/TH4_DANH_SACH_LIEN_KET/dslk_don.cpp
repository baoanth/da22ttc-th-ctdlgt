#include <stdio.h>
#include <conio.h>
#include <string.h>
<<<<<<< HEAD
// struct person with 3 fields
=======

>>>>>>> 4167010305f6918aedcd575e6543f0c0425437a6
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

<<<<<<< HEAD
//Khai bao Node voi Info la kieu Person
typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

//Khai bao danh sach lien ket don List voi thanh phan la Node 
=======
typedef struct Node
{
    Person Info;
    Node* pNext;
}Node;

>>>>>>> 4167010305f6918aedcd575e6543f0c0425437a6
typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

<<<<<<< HEAD
//Viet ham khoi tao danh sach lien ket 
=======
>>>>>>> 4167010305f6918aedcd575e6543f0c0425437a6
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

<<<<<<< HEAD
//Viet ham tao mot Node moi tu cau truc x kieu  Person
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

//Viet ham them mot Node mo vao dau danh sach
void AddFist(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
=======
Node* GetNode(Person x)
{
	Node* p;
    p=new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho de cap phat cho nut moi!\n");
    	return 0;
	}
	p->Info=x;
	p->pNext=NULL;
	return p;	
}

void AddFirst(List &l, Node* new_ele)
{
    if(l.pHead==NULL)
    {
	    l.pHead=new_ele;
	    l.pTail=l.pHead;
	}
	else
	{
	   new_ele->pNext=l.pHead;
	   l.pHead=new_ele;
	}
}

void AddTail(List &l, Node *new_ele)
{
    if (l.pHead==NULL)
>>>>>>> 4167010305f6918aedcd575e6543f0c0425437a6
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
<<<<<<< HEAD
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}

//Ham duyet va in dannh sach ra man hinh
void PrintList(List &l)
{
	if(l.pHead == NULL)
	{
		printf("Danh sach rong\n");
	}
	else 
	{
		Node *p;
		p = l.pHead;
		while(p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname);
			p = p->pNext;	
=======
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

Node* FindNodeByID(List l, int idx)
{
	Node* p=l.pHead;
	while(p!=NULL && p->Info.id!=idx)
	p=p->pNext;
	return p;
}

int RemoveNode(List &l, int idx)
{
    Node *p = l.pHead;
    Node *q = NULL;
    while(p != NULL)
    {
	    if(p->Info.id == idx) break;
	    q = p;
	    p = p->pNext;
	}
	if(p == NULL) 
	{
	    return 0;
	    printf("\n Khong tim thay Node co id %d", idx);
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
return 1;
}

void InputNode(List &l)
{
	Person per_tam;
	printf("\n Moi nhap node moi");
    printf("\nID:");
    scanf("%d", &per_tam.id);
    
    fflush(stdin);
    printf("First name:");
    gets(per_tam.fname);
    
    fflush(stdin);
    printf("Last name:");
    gets(per_tam.lname);
    
    Node* new_ele = GetNode(per_tam);
    
    printf("Ban muon them vao vi tri nao: ");
    printf("1.Dau danh sach; 2.Cuoi danh sach\n");
    
    fflush(stdin);
    int chon=0;
    scanf("%d", &chon);
    
    switch(chon)
    {
    	case 1:
    		AddFirst(l, new_ele);
    		printf("Da them new_ele vao dau danh sach");
    		break;
    	case 2:
    		AddTail(l, new_ele);
    		printf("Da them new_ele vao cuoi danh sach");
    		break;
    	default:
    		AddTail(l, new_ele);
	        printf("Ban da nhap sai. Da them new_ele vao cuoi danh sach\n");	
	        break;
	}
}
void PrintNode(Node *p)
{
	printf("%3d %10s %12s \n", p->Info.id, p->Info.fname, p->Info.lname);    
}

void PrintList(List l)
{
    if(l.pHead==NULL)
    {
	    printf("Danh sach rong\n");
	}
	else
	{
	    Node* p;
	    p=l.pHead;
	    while(p!=NULL)
	    {
	        printf("%3d %10s %12s \n", p->Info.id, p->Info.fname, p->Info.lname);
	        p = p->pNext;
>>>>>>> 4167010305f6918aedcd575e6543f0c0425437a6
		}
	}
}

<<<<<<< HEAD

//Ham main
int main()
{
    struct Person per1 = { 1, "kaneki","ken"};
    struct Person per2 = { 2, "Thanh","Vinh"};
    struct Person per3 = { 3, "I AM", "BadMan"};
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

    AddFist(my_list, new_ele3);
    AddFist(my_list, new_ele2);
    AddFist(my_list, new_ele1);
    
    PrintList(my_list);
    
   
}
=======
int main()
{
    struct Person per1= {1, "Thanh","Vinh"};
    struct Person per2= {2, "kaneki", "ken"};
    struct Person per3= {3, "I AM","Badman"};
    
    Node* new_ele1 = GetNode(per1);
    Node* new_ele2 = GetNode(per2);
    Node* new_ele3 = GetNode(per3);
    
    List my_list;
    Init(my_list);
    
    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);
    
    PrintList(my_list);
    
    int idx;
    printf("Nhap id can tim: \n");
    scanf("%d", &idx);
    Node* node_kq = FindNodeByID(my_list, idx);
    if(node_kq != NULL)
        PrintNode(node_kq);
    else
        printf("Khong tim thay Node co id %d", idx);
        
    printf("\n Nhap id can xoa: ");
	scanf("%d", &idx);
	int kq = RemoveNode(my_list, idx);
	if(kq!=0)
	    printf("\n Da xoa nut co id %d", idx);
    else
        printf("\n Khong the xoa nut co id %d", idx);
    printf("\n Danh sach sau khi xoa\n");
    PrintList(my_list);
    
    
    InputNode(my_list);
    InputNode(my_list);
    printf("\n Danh sach sau khi cap nhat: \n");
    PrintList(my_list);
	
return 0;
}

>>>>>>> 4167010305f6918aedcd575e6543f0c0425437a6
