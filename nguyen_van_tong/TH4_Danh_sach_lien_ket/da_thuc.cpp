#include <stdio.h>
#include <stdlib.h>

typedef struct Donthuc
{
    int heso, bac;
} donthuc;

typedef struct Node
{
    donthuc Info;
    Node *pNext;
} Node;

typedef struct Dathuc
{
    Node *pHead;
    Node *pTail;
} dathuc;

Node *GetNode(donthuc x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho !");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void Init(dathuc &l)
{
    l.pHead = l.pTail = NULL;
}

void AddTail(dathuc &l, Node *new_ele)
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

void nhapdathuc(dathuc &l)
{
    int tmp;
    printf("nhap vao bac da thuc ");
    scanf("%d", &tmp);
    donthuc x;
    for (int i = tmp; i >= 0; i--)
    {
        printf("He so cua x^%d = ", i);
        scanf("%d", &x.heso);
        x.bac = i;

        Node *p = GetNode(x);

        AddTail(l, p);
    }
}

void print(dathuc l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p != l.pHead && p->Info.heso > 0)
            printf("+");
        if (p->Info.bac == 0)
            printf("%d", p->Info.heso);
        else if(p->Info.bac == 1)
        	 printf("%dx", p->Info.heso);
        else
        {
        	 printf("%dx^%d", p->Info.heso, p->Info.bac);
        
        }
       	p = p->pNext;
    }
}

dathuc congdathuc(dathuc l, dathuc f)
{
	Node* p = l.pHead;
	Node* q = f.pHead;
	
//	if(p->Info.bac > q->Info.bac)
//	{
		while(p!=NULL)
		{
			donthuc tmp;
			dathuc l_kq;
			tmp.bac = p->Info.bac;
			tmp.heso = p->Info.heso;
			while(q!=NULL)
			{
				if (tmp.bac == q->Info.bac)
				{
					break;
				}
				q = q->pNext;
			}
			tmp.heso += q->Info.heso;
			Node* newe = GetNode(tmp);
			Init(l_kq);
			AddTail(l_kq, newe);
			p = p->pNext;
	    }
	    return l_kq;
//	}
//	else
//	{
//		while(q!=NULL)
//		{
//			if (q->Info.bac = p->Info.bac)
//			{
//				q->Info.heso = q->Info.heso+p->Info.heso;
//			}
//			q = q->pNext;
//		}
//		
//	}

}



int main()
{

    dathuc my_dathuc;
    dathuc dathuc2, kq;
    Init(my_dathuc);
	Init(dathuc2);
    nhapdathuc(my_dathuc);
    nhapdathuc(dathuc2);
    kq = congdathuc(my_dathuc,dathuc2);
    
    print(kq);
    return 0;
}
