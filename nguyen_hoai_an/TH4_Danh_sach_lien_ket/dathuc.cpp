#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DonThuc
{
    int heso;
    int bac;
} DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node *pNext;
} Node;

typedef struct Dathuc
{
    Node *pHead;
    Node *pTail;
} Dathuc;

Node *GetNode(DonThuc x)
{
    Node *p = new Node;

    if (p == NULL)
    {
        printf("404 ");
        return 0;
    }

    p->Info = x;
    p->pNext = NULL;

    return p;
}

void Init(Dathuc &l)
{
    l.pHead = l.pTail = NULL;
}

void AddTail(Dathuc &l, Node *new_ele)
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

void NhapDaThuc(Dathuc &l)
{
    int n = 0;
    printf("Da thuc bac: ");
    scanf("%d", &n);

    int i;
    DonThuc s;
    for (i = n; i >= 0; i--)
    {
        printf("  x^%d. Nhap so:", i);
        s.bac = i;
        scanf("%d", &s.heso);

        Node *new_ele = GetNode(s);
        AddTail(l, new_ele);
    }
}

void InDaThuc(Dathuc &l)
{
    if (l.pHead == NULL)
    {
        printf("Trong rong");
    }
    else
    {
        Node *p=l.pHead;

        while (p != NULL)
        {
            if ((p != l.pHead) && (p->Info.heso > 0))
            printf("+");
            if(p->Info.bac == 0)
            printf("%d", p->Info.heso);
            
            else if(p->Info.bac == 1)
            printf("%dx", p->Info.heso);
            
            else
            printf("%dx^%d", p->Info.heso, p->Info.bac);
            p = p->pNext;
        }
    }
}

Dathuc Congdathuc(Dathuc &l, Dathuc &m)
{
	Node *p, *q;
	Dathuc l_kq;
	Init(l_kq);
	Donthuc dt_tam;
	p = l.pHead;
	q = m.pHead;
	
	while(p != NULL)
	{
		dt_tam.heso = p->Info.heso;
		dt_tam.bac = p->Info.bac;
		while(q != NULL)
		{
		if(p->Info.bac == q->Info.bac)
		break;
		q = q->pNext;			
		}
		if(q!=NULL)
			dt_tam.heso += q->Info.heso;
			
		Node new_ele = GetNode(dt_tam);
		AddTail(l_kq, new_ele);
		
		p->pNext;
	}
	return l_kq;
}

int main()
{
   /* Dathuc my_dathuc;
    Init(my_dathuc);

    NhapDaThuc(my_dathuc);

    printf("Da thuc vua nhap:  ");
    InDaThuc(my_dathuc);
   */ 
	Dathuc dt1, dt3, dt3;
	Init(dt1);
	Init(dt2);
	
	Nhapdathuc(dt1);
	PrintDaThuc(dt1);
	
	Nhapdathuc(dt2);
	PrintDaThuc(dt2);
	
	dt3 = CongDaThuc(dt1, dt2);
	PrintDaThuc(dt);
	    

    return 0;
}
