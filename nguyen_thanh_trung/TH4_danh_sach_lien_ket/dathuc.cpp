#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct DonThuc
{
    int he_so;
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
        printf("Khong du bo nho de cap phat nut");
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

void them_nut_cuoi(DaThuc &l)
{
    DonThuc new_don_thuc;
    int bac_da_thuc, i;
    printf("Ban muon nhap da thuc bac may?: ");
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

DaThuc tinh_toan_da_thuc(DaThuc l1, DaThuc l2)
{
    DonThuc dt_tam;

    Node *q = l1.pHead;
    Node *p = l2.pHead;

    DaThuc l_kq;
    Init(l_kq);

    while(q != NULL)
    {
        dt_tam.he_so = q->Info.he_so;
        dt_tam.bac = q->Info.bac;

        while(p != NULL)
        {
            if(q->Info.bac == p->Info.bac)
                break;
            p = p->pNext;
        }

        dt_tam.he_so += p->Info.he_so;

        Node* new_ele = GetNode(dt_tam);
        AddTail(l_kq,new_ele);

        q = q->pNext;
    }
    return l_kq;
    
}

int main()
{
    DaThuc da_thuc1;
    Init(da_thuc1);

    DaThuc da_thuc2;
    Init(da_thuc2);

    DaThuc da_thuc_kq;

    them_nut_cuoi(da_thuc1);
    in_da_thuc(da_thuc1);
    printf("\n\n");
    them_nut_cuoi(da_thuc2);
    in_da_thuc(da_thuc2);

    da_thuc_kq = tinh_toan_da_thuc(da_thuc1,da_thuc2);
    printf("\nDa thuc sau khi cong: ");
    in_da_thuc(da_thuc_kq);

    return 0;
}
