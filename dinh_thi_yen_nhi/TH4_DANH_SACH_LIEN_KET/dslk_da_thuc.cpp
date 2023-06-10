#include <stdio.h>
#include <stdio.h>
#include <string.h>

typedef struct Donthuc
{
    int heso;
    int bac;
} DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node* pNext;
} Node;

typedef struct DaThuc
{
    Node* pHead;
    Node* pTail;
} DaThuc;

Node* GetNode(DonThuc x)
{
    Node *p;
    p = new Node;
    if ( p == NULL)
    {
        printf ("Khong du bo nho");
        //Exit (1);
    }
    p -> Info = x;
    p -> pNext = NULL;
    return p;
}

void AddTail (DaThuc &l, Node *new_ele)
{
    if (l.pHead == NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail -> pNext = new_ele;
        l.pTail = new_ele;
    }
}

void NhapDaThuc (DaThuc &l)
{
    int n = 0;
    int i, j;
    DonThuc dt_tam;
    
    printf("Bac cua da thuc la:");
    scanf ("%d", &n);

   for (i=n; i>=0; i--)
    {
    
        printf("x^%d = ", i);
		dt_tam.bac = i;
		scanf("%d", &dt_tam.heso);
		
		Node* new_ele = GetNode(dt_tam);
		AddTail(l, new_ele);
    }
}

void Init(DaThuc &l)
{
	l.pHead = l.pTail = NULL;
}

void PrintDaThuc (DaThuc &l)
{
    Node *p;
    p = l.pHead;

    printf ("Da thuc da nhap la: ");

    while (p!= NULL)
	{
		if((p->Info.heso>0) && (p!=l.pHead))
			printf("+");
		if(p->Info.bac == 0)
			printf("%d", p->Info.heso);
		else
			printf("%dx^%d", p->Info.heso, p->Info.bac);
		p = p->pNext;
	}
  
}  

int main()
{
	DaThuc my_dt;
	//Dathuc dathuc2;
	
	Init(my_dt);
	
	NhapDaThuc(my_dt);
//	Nhapdathuc(dathuc2);
	
	PrintDaThuc(my_dt);

	return 0;
}

