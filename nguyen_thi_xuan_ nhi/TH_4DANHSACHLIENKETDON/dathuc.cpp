#include <stdio.h>
#include <stdlib.h>

typedef struct DonThuc
{
    int heso;
    int bac;
}DonThuc;

typedef struct Node
{
    DonThuc Info;
    Node* pNext;
}Node;

typedef struct DaThuc
{
    Node *pHead;
    Node *pTail;
}DaThuc;

Node *GetNode (DonThuc x)
{
    Node *p;
    p= new Node;
    if (p==NULL)
    {
        printf("Khong du dubg luong");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void copydathuc(dathuc l,dathuc &l_kq)
{
    Node*P;
    P=pHead;
    while(p!=NULL)
    {
        Node*new_ele=GetNode(p->Info);
        AddTail(dathuc &l,Node *new_ele);
        p->pNext;
    }
    printf("\n da thuc da coopy xong");
}

Node*TimNodeBacN(dathuc l,int n)
{
    Node*p;
    p=pHead;
    while(p=!NULL)
    {
        if(p->Info.bac==n)
        break;
        p=p->pNext;

    }
    return p;
}

void congdathuc(dathuc l1,dathuc l2,dathuc &l_kq)
{
    copydathuc(l1,l_kq)
    Node*p;
    p=l2.pHead;
    while(p=!NULL)
    {
        Node*foundNode=TimNodeBacN(l_kq,p->Info.bac);
        if(foundNode=!NULL)
        {
            foundNode->Info.heso =p->Info.heso;
            printf("\n bac cua he so la %d =",p->Info.bac);
        }
        else
        {
            Node *node_tam=GetNode(p->Info);
            AddTail(l_kq,node_tam);
        }
        p=p->pNext;
    }
}













void AddTail(DaThuc &l, Node *new_ele)
{
    if(l.pHead == NULL)
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

void NhapDathuc(DaThuc &l)
{
	int MaxN= 0;
	int i,j;
	DonThuc s;
	
	printf("PT co bac: ");
	scanf("%d", &MaxN);
	
	for(i= MaxN; i>=0; i--)
	{
		printf("x^%d = ",i);
		s.bac= i;
		scanf("%d", &s.heso);
		
		Node* new_ele = GetNode(s);
		AddTail(l, new_ele);	
	}
}

void Init(DaThuc &l)
{
    l.pHead = l.pTail = NULL;
}

void PrintDaThuc(DaThuc &l)
{
    Node *p;
	p = l.pHead;
	
	printf("\nP(x)= ");
	
    while (p!= NULL)
    {
        
        if((p->Info.heso>0)&&(p!= l.pTail))
        printf("+");
        
        if(p->Info.bac == 0)
        printf("%d",p->Info.heso);
        
        else 
        printf("%dx^%d",p->Info.heso, p->Info.bac);

        p= p->pNext;
    }
}

int main()
{
    DaThuc dathuc1;
       
    Init(dathuc1);
    
    NhapDathuc(dathuc1);
   
    PrintDaThuc(dathuc1);
    
    
    return 0;
}
