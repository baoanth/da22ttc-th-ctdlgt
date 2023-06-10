#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Donthuc
{
    int bac;
    int hs;

}Donthuc;

typedef struct Node
{
    Donthuc Info;
    Node *pNext;
}Node;

typedef struct Dathuc
{
    Node *pHead;
    Node *pTail;
}Dathuc;

void Init(Dathuc &l)
{
    l.pHead = l.pTail = NULL;
}

Node *GetNode(Donthuc x)
{
    Node *p = new Node;
    if(p==NULL)
    {
        printf("Khong du bo nho de cap phat nut moi");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(Dathuc &l, Node* new_ele)
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
        new_ele->pNext = NULL;
    }
}

void NhapDaThuc(Dathuc &l)
{
    int n=0;
    int i;
    Donthuc Px;
    printf("Nhap bac cua da thuc:");
    scanf("%d", &n);

    for(i=n; i>=0; i--)
    {
        printf("x^%d *", i);
        Px.bac = i;
        scanf(" %d", &Px.hs);

        Node *new_ele = GetNode(Px);
        AddTail(l, new_ele);
    }
}

void XuatDaThuc(Dathuc &l)
{
    Node *p = l.pHead;
     printf("Da thuc vua nhap :");
    printf("\n  P(x) = ");

    while (p != NULL)
    {
        if ((p->Info.hs > 0) && (p != l.pHead))
            printf(" + ");

        if (p->Info.bac == 0)
            printf("%d", p->Info.hs);
        else
            printf("%dx^%d", p->Info.hs, p->Info.bac);

        p = p->pNext;
    }
}

Dathuc TinhTong(Dathuc l1, Dathuc l2)
{
	Dathuc sum;
	Init(sum);
	
	Node *p1 = l1.pHead;
	Node *p2 = l2.pHead;
	
	while(p1!=NULL && p2!=NULL)
	{
		Donthuc sum_node;
		if(p1->Info.bac == p2->Info.bac)
		{
			sum_node.bac = p1->Info.bac;
			sum_node.hs = p1->Info.hs + p2->Info.hs;
			
			p1 = p1->pNext;
			p2 = p2->pNext;
		}
		else if(p1->Info.bac > p2->Info.bac)
		{
			sum_node.bac = p1->Info.bac;
			sum_node.hs = p1->Info.hs;
			
			p1 = p1->pNext;
		}
		else 
		{
			sum_node.bac = p2->Info.bac;
			sum_node.hs = p2->Info.hs;
			
			p2 = p2->pNext;
		}
		
		Node *new_ele = GetNode(sum_node);
		AddTail(sum, new_ele);
	}	
return sum;	
}
int main()
{
    Dathuc my_Px1;
    Dathuc my_Px2;
    
    Init(my_Px1);
    Init(my_Px2);

    printf("\nNhap da thuc Px1:\n");
    NhapDaThuc(my_Px1);
    XuatDaThuc(my_Px1);
    
    printf("\nNhap da thuc Px2:\n");
    NhapDaThuc(my_Px2);
    XuatDaThuc(my_Px2);
    
    Dathuc sum = TinhTong(my_Px1,my_Px2);
    printf("\nTong hai da thuc:");
    printf("\n");
    XuatDaThuc(sum);
    
    return 0;
}
