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

typedef struct DaThuc
{
    Node *pHead;
    Node *pTail;
} DaThuc;

Node *GetNode(DonThuc x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho.");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(DaThuc &l, Node *new_ele)
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
void Init(DaThuc &l)
{
    l.pHead = l.pTail = NULL;
}

void NhapDaThuc(DaThuc &l)
{
    int max_bac = 0;
    printf(" Da thuc bac: ");
    scanf("%d", &max_bac);

    int i;
    for (i =max_bac; i>=0; i--)
    {
        printf("Nhap he so x^%d:", i);
        s.bac = i;
        scanf("%d", &s.heso);
        Node *new_ele = GetNode(s);
        AddTail(l, new_ele);
    }

}
void CopyDaThuc(DaThuc l, DaThuc &l_kq)
{
	Node* p;
    p = l.pHead;

    while (p!=NULL)
    {
    	Node* new_ele = GetNode(p->Info);
    	AddTail(l_kq, new_ele);
    	p=p->pNext;
    }
    printf("\nCopy da thuc xong.\n");
}

Node* TimNodeBacN(DaThuc l, int n)
{
	Node* p;
    p =l.pHead;

    while (p!=NULL)
    {
    	if(p->Info.bac==n)
    		break;
    	p=p->pNext;
    }
    return p;
}

void CongDaThuc(DaThuc l1, DaThuc l2, DaThuc &l_kq)
{

    CopyDaThuc(l1, l_kq);

	Node* p;
    p =l2.pHead;

	while (p!=NULL)
    {
    	Node* foundNode = TimNodeBacN(l_kq, p->Info.bac); 
    	if (foundNode!=NULL)   
		{

    		foundNode->Info.heso += p->Info.heso;
    		printf("Found bac %d\n" ,p->Info.bac);
    	}
    	else  
    	{
    		Node* node_tam = GetNode(p->Info);
    		AddTail(l_kq, node_tam);
    	}
    	p=p->pNext;
    }  

}

/*void NhanDaThuc(DaThuc l1, DaThuc l2, DaThuc &l_kq)
{
    //Copydathuc(l1, l_kq);
	
	Node* p;
	p = l2.pHead;
	
	while(p!=NULL)
	{
		Node* foundNode = TimNodeBacN(l_kq, p->Info.bac);
		if(foundNode != NULL)
		{
			foundNode->Info.heso *= p->Info.heso;
		}
		else
		{
			Node* Node_tam = GetNode(p->Info);
			AddTail(l_kq, Node_tam);
		}
		p = p->pNext;
	}
}*/

void PrintDaThuc(DaThuc l)
{
    Node* p;
    p =l.pHead;

    while (p!=NULL )
    {
        if(p!=l.pHead && p->Info.heso>=1)
        	printf(" + ")	;
        printf("%d", p->Info.heso);
        if(p->Info.bac>0)
			printf("x^%d", p->Info.bac);

        p=p->pNext;
    }
}

int main()
{
    DaThuc my_dt1, my_dt2, my_dt3, kq;
    Init(my_dt1);
    Init(my_dt2);
    Init(my_dt3);
    Init(kq);

    NhapDaThuc(my_dt1);
    PrintDaThuc(my_dt1);
    printf("\n--------------------\n");

    NhapDaThuc(my_dt2);
    PrintDaThuc(my_dt2);
    printf("\n--------------------\n");

    printf("Da thuc vua nhap:\n");
    InDaThuc(DaThuc1);
    printf(" \n");
    InDaThuc(DaThuc2);

    /*NhanDaThuc(my_dt1, my_dt2, kq);
	printf("\nTich 2 da thuc = ");
	PrintDaThuc(kq);*/
    
    return 0;
}