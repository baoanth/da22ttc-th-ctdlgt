#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
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

//Tao mot nut voi gia tri x
Node *GetNode(DonThuc x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
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
    printf("Ban muon nhap da thuc bac may?");
    scanf("%d", &max_bac);

    int i;
    for (i =max_bac; i>=0; i--)
    {
        DonThuc dt_tam;
        dt_tam.bac = i;

        printf("x^ %d * ",i);
        scanf("%d", &dt_tam.heso);

        Node* new_ele = GetNode(dt_tam);

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
    printf("\nDa copy da thuc xong!\n");
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
	    
    CopyDaThuc(l1, l_kq);    // Sao chep l1 vao l_kq
    
	Node* p;
    p =l2.pHead;  // p chay tren L2
    
	while (p!=NULL)
    {
    	Node* foundNode = TimNodeBacN(l_kq, p->Info.bac); // tim Nut co bac N tren l1
    	if (foundNode!=NULL) // Tim thay node cung bac   
		{
		 	
    		foundNode->Info.heso += p->Info.heso;	 // Cong 2 he so
    		printf("Found bac %d\n" ,p->Info.bac);
    	}
    	else  // Nguoc lai copy nut tu l2 sang l_kq
    	{
    		Node* node_tam = GetNode(p->Info);
    		AddTail(l_kq, node_tam);
    	}
    	p=p->pNext;
    }  

}

void PrintDaThuc(DaThuc l)
{
    Node* p;
    p =l.pHead;

    while (p!=NULL )
    {
        if(p!=l.pHead && p->Info.heso>=1)
        	printf("+")	;
        printf("%d" , p->Info.heso);
        if(p->Info.bac>0)
			printf("x^%d" , p->Info.bac);
        
        p=p->pNext;
    }
}

int main()
{
    DaThuc my_dt1, my_dt2, my_dt3;
    Init(my_dt1);
    Init(my_dt2);
    Init(my_dt3);
    
    NhapDaThuc(my_dt1);
    PrintDaThuc(my_dt1);
    
    NhapDaThuc(my_dt2);
    PrintDaThuc(my_dt3);
    
    CongDaThuc(my_dt1, my_dt2, my_dt3);
    PrintDaThuc(my_dt3);
}


