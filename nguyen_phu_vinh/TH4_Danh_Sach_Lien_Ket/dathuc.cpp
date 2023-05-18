#include<stdio.h>



typedef struct Donthuc
{
	int he_so;
	int bac;
	
	
	
}Donthuc;

typedef struct Node
{
	Donthuc Info;
	Node *pNext;
	
}Node;

typedef struct Dathuc
{
	Node  *pHead;
	Node *pTail;
	
}DaThuc;
void Init(DaThuc &l)
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
Node *GetNode(Donthuc x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho Node moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void PrintList(Dathuc l)
{
	Node* p=l.pHead;
	while(p!=NULL)
	{
		printf("%d^%d",p->Info.he_so,p->Info.bac);
		p=p->pNext;
	}
	
}
void them_nut_cuoi( Dathuc &l)
{
    struct Donthuc new_don_thuc;
    int bac_da_thuc, i;
    printf("Ban muon nhap da thuc bac may: ");
    scanf("%d", &bac_da_thuc);

    for (i = bac_da_thuc; i >= 0; i--)
    {
        printf("X^%d : ", i);
        scanf("%d", &new_don_thuc.he_so);
        new_don_thuc.bac = i;
        Node *new_ele = GetNode(new_don_thuc);
        AddTail(l, new_ele);
    }
}

void in_da_thuc(DaThuc l)
{
    printf("\n");
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->Info.he_so == 0)
        {
            p = p->pNext;
            l.pHead = p;
            continue;
        }
        if (p != l.pHead && p->Info.he_so > 0)
            printf("+");
        if (p != l.pTail && p->pNext != l.pTail)
        {
            if (p->Info.he_so != 1 && p->Info.he_so != -1)
                printf("%dx^%d", p->Info.he_so, p->Info.bac);
            else if (p->Info.he_so == 1)
                printf("x^%d", p->Info.bac);
            else if (p->Info.he_so == -1)
                printf("-x^%d", p->Info.bac);
        }
        else if (p->pNext == l.pTail)
        {
            if (p->Info.he_so != 1 && p->Info.he_so != -1)
                printf("%dx", p->Info.he_so);
            else if (p->Info.he_so == 1)
                printf("x");
            else if (p->Info.he_so == -1)
                printf("-x");
        }
        else if (p == l.pTail)
            printf("%d", p->Info.he_so);

        p = p->pNext;
    }
}
//void cong_da_thuc(DaThuc,DaThuc)
//{
//	Node *p ,*q;
//	DaThuc l_kq;
//	Init(l_kq);
//	DonThuc tam;
//	p = l1.pHead;
//	q = l2.pHead;
//	while(p!= NULL)
//	{
//		tam.he_so=p->Info.he_so;
//		tam.bac= p->Info.bac;
//		
//		while(q!=NULL)
//		{
//			if(p->Info.bac == q->Info.bac)
//			break;
//			q=q->pNext;
//			
//		}
//	}
//}

int main ()
{
	DaThuc my_da_thuc;
	DaThuc my_da_thuc1;
    Init(my_da_thuc);
	
    them_nut_cuoi(my_da_thuc);
	them_nut_cuoi(my_da_thuc1);
    in_da_thuc(my_da_thuc);
    in_da_thuc(my_da_thuc1);
    
	return 0;
}
