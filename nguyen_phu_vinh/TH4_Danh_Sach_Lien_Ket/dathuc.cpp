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
void CopyDaThuc(DaThuc l, DaThuc &l_kq)
{
    // Init(l_kq);
    Node *p = l.pHead;
    while (p != NULL)
    {
        Node *q = GetNode(p->Info);
        AddTail(l_kq, q);
        p = p->pNext;
    }
}

Node *TimNodeBacN(DaThuc l, int n)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->Info.bac == n)
        {
            break;
        }
        p = p->pNext;
    }
    return p;
}

DaThuc CongDaThuc(DaThuc l1, DaThuc l2, DaThuc &l_kq)

{

    Init(l_kq);
    CopyDaThuc(l1, l_kq);
    Node *p = l2.pHead;

    while (p != NULL)
    {
        Node *fNode = TimNodeBacN(l_kq, p->Info.bac);
        if (fNode != NULL)
        {
            fNode->Info.he_so += p->Info.he_so;
        }
        else
        {
            Node *tam = GetNode(p->Info);
            AddTail(l_kq, tam);
        }
        p = p->pNext;
    }
}

int main()
{
    DaThuc my_dathuc1;
    DaThuc my_dathuc2, kq;
    Init(my_dathuc1);
    Init(my_dathuc2);
    Init(kq);

    them_nut_cuoi(my_dathuc1);
    them_nut_cuoi(my_dathuc2);

    printf("\nDa thuc 1:");
    in_da_thuc(my_dathuc1);
    printf("\nDa thuc 2:");
    in_da_thuc(my_dathuc2);

    printf("\nDa thuc kq:");
    CongDaThuc(my_dathuc1, my_dathuc2, kq);

    in_da_thuc(kq);

    return 0;
}

