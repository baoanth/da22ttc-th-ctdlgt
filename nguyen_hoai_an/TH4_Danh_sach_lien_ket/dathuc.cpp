#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

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
    Node *p = new Node;

    if (p == NULL)
    {
        printf("Khong du bo nho");
        return 0;
    }

    p->Info = x;
    p->pNext = NULL;

    return p;
}

void Init(DaThuc &l)
{
    l.pHead = l.pTail = NULL;
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

void NhapDaThuc(DaThuc &l)
{
    int bacmax = 0;

    printf("Da thuc bac: ");
    scanf("%d", &bacmax);

    DonThuc s;
    int i;

    for (i = bacmax; i >= 0; i--)
    {
        printf("  x^%d : ", i);
        s.bac = i;
        scanf("%d", &s.heso);
        Node *new_ele = GetNode(s);
        AddTail(l, new_ele);
    }
}

void InDaThuc(DaThuc &l)
{
    if (l.pHead == NULL)
    {
        printf("Trong Rong.");
    }
    else
    {
        Node *p = l.pHead;

        while (p != NULL)
        {
            if ((p != l.pHead) && (p->Info.heso >= 0))
                printf(" + ");
		
            if (p->Info.bac == 0)
                printf("%d", p->Info.heso);
            else if (p->Info.bac == 1)
                printf("%dx", p->Info.heso);
            else
                printf("%dx^%d", p->Info.heso, p->Info.bac);

            p = p->pNext;
        }
    }
}

void CopyDaThuc(DaThuc l, DaThuc &l_KetQua)
{
	Node* p = l.pHead;

    while (p!=NULL)
    {
    	Node* new_ele = GetNode(p->Info);
    	AddTail(l_KetQua, new_ele);
    	p = p->pNext;
    }
}

Node* TimNodeBacN(DaThuc l, int n)
{
	Node* p = l.pHead;

    while (p!=NULL)
    {
    	if(p->Info.bac==n)
    		break;
    	p = p->pNext;
    }
    return p;
}

void CongDaThuc(DaThuc &l1, DaThuc &l2, DaThuc &l_KetQua)
{
	CopyDaThuc(l1, l_KetQua);
	Node* p = l2.pHead;
	
	while(p!=NULL)
	{
		Node* FoundNode = TimNodeBacN(l_KetQua, p->Info.bac);
		if(FoundNode != NULL)
		{
			FoundNode->Info.heso += p->Info.heso;
		}
		else
		{
			Node* NodeTam = GetNode(p->Info);
			AddTail(l_KetQua, NodeTam);
		}
		p = p->pNext;	
	}	
}

//DaThuc CongDaThuc(DaThuc &l1, DaThuc &l2)
//{
//    Node *p = l1.pHead;
//    Node *q = l2.pHead;
//    DaThuc KetQua;
//    Init(KetQua);
//    DonThuc DaThucTam;
//
//    while (p != NULL)
//    {
//        DaThucTam.bac = p->Info.bac;
//        DaThucTam.heso = p->Info.heso;
//
//       while (q != NULL)
//        {
//            if (DaThucTam.bac == q->Info.bac)
//               break;
//            q = q->pNext;
//        }
//        if (q != NULL)
//            DaThucTam.heso += q->Info.heso;
//
//        Node *new_ele = GetNode(DaThucTam);
//       AddTail(KetQua, new_ele);
//        p = p->pNext;
//    }
//    return KetQua;
//}

void NhanDaThuc(DaThuc l1, DaThuc l2, DaThuc &l_kq)
{
    CopyDaThuc(l1, l_kq);
	
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
}

float TinhGiaTri(DaThuc l, int x)
{
    float KetQua = 0;
    Node* p = l.pHead;
    
    while(p != NULL)
    {
        KetQua += p->Info.heso*pow(x, p->Info.bac);
        p = p->pNext;
    }
    return KetQua;
}

void GopDonThuc(DaThuc &l)
{
	Node* p = l.pHead;
	Node* q = l.pHead->pNext;
	
	while(p != NULL)
	{
		while(q != NULL)
		{
			if(p->Info.bac = q->Info.bac)
				p->Info.heso += q->Info.heso;
			q = q->pNext;
		}
		p = p-> pNext;	
	} 
}

int main()
{
    DaThuc DaThuc1, DaThuc2, Tong, Tich;
    Init(DaThuc1);
    Init(DaThuc2);
	Init(Tong);
    Init(Tich);
	
    NhapDaThuc(DaThuc1);
    NhapDaThuc(DaThuc2);

    printf("Da thuc vua nhap: \n");
    InDaThuc(DaThuc1);
    printf("\n");
    InDaThuc(DaThuc2);
    printf("\n");

    CongDaThuc(DaThuc1, DaThuc2, Tong);
    printf("\nTong 2 da thuc = ");
    InDaThuc(Tong);

    NhanDaThuc(DaThuc1, DaThuc2, Tich);
	printf("\nTich 2 da thuc = ");
	InDaThuc(Tich);
	
	float x;
    printf("\n");
	printf("\nNhap x de tinh gia tri da thuc: ");
	scanf("%f", &x);
	float KetQua = TinhGiaTri(DaThuc1, x);
	printf("Gia tri da thuc 1 khi x = %.2f la: %.2f\n", x, KetQua);
	float KetQua1 = TinhGiaTri(DaThuc2, x);
	printf("Gia tri da thuc 2 khi x = %.2f la: %.2f\n", x, KetQua1);
	
    return 0;
}