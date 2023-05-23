#include <stdio.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int hs;
    int bac;
}Donthuc;

typedef struct Node
{
	Donthuc Info;
	Node* pNext;
}Node;

typedef struct Dathuc
{
	Node* pHead;
	Node* pTail;
}Dathuc;


Node* GetNode(Donthuc x)
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

//Viet ham AddTail
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

//Viet ham Nhap da thuc
void Nhapdathuc(Dathuc &l)
{
	int MaxN= 0;
	int i, j;
	Donthuc s;
	
	printf("Da thuc co bac: ");
	scanf("%d", &MaxN);
	
	for(i= MaxN; i>=0; i--)
	{
		printf("x^%d = ",i);
		s.bac = i;
		scanf("%d", &s.hs);
		
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);	
	}
}

//Viet ham Init
void Init(Dathuc &l)
{
	l.pHead = l.pTail = NULL;
}

  
 void Xuatdathuc(Dathuc& l)
{
    Node* p = l.pHead;

    printf("da thuc vua nhap :\n");
    printf("\n  P(x) = ");

    while (p != NULL)
    {
        if ((p->Info.hs > 0) && (p != l.pHead))
            printf(" + ");

        if (p->Info.bac == 0)
            printf(" %d", p->Info.hs);
        else
            printf("%dx^%d", p->Info.hs, p->Info.bac);

        p = p->pNext;
    }
}
Dathuc TinhTong(Dathuc l1, Dathuc l2)
{
    Dathuc sum;
    Init(sum);

    Node* p1 = l1.pHead;
    Node* p2 = l2.pHead;

    while (p1 != NULL && p2 != NULL)
    {
        Donthuc sum_node;
        if (p1->Info.bac == p2->Info.bac)
        {
            sum_node.bac = p1->Info.bac;
            sum_node.hs = p1->Info.hs + p2->Info.hs;

            p1 = p1->pNext;
            p2 = p2->pNext;
        }
        else if (p1->Info.bac > p2->Info.bac)
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

        Node* new_ele = GetNode(sum_node);
        AddTail(sum, new_ele);
    }

    

    return sum;
}


 
//viet ham main

int main()
{
    Dathuc my_Px1;
    Dathuc my_Px2;

		
    Init(my_Px1);
    Init(my_Px2);
	
	
    printf("Nhap da thuc 1\n");
    Nhapdathuc(my_Px1);
    Xuatdathuc(my_Px1);
    printf("\n");
    
    
    printf("Nhap da thuc 2\n");
    Nhapdathuc(my_Px2);
    Xuatdathuc(my_Px2);

    Dathuc sum = TinhTong (my_Px1, my_Px2);
    printf("\n Cong hai da thuc :\n");
    Xuatdathuc(sum);

    return 0;
}


