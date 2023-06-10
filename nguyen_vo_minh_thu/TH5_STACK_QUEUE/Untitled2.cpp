#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct Person
{
    char hoten[20];
    int tuoi;
    char diachi[30];
    char tinhtrang[40];
} Person;

typedef struct Node
{
    Person Info;
    Node *pNext;
} Node;

typedef struct Queve
{
    Node *pHead;
    Node *pTail;
} Queve;

Node *GetNode(Person x)
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

void AddTail(Queve &l, Node *new_ele)
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

void Init(Queve &l)
{
    l.pHead = l.pTail = NULL;
}

char IsEmpty(Queve &l)
{
    if (l.pHead == NULL)

        return 1;
	else
        return 0;
}

void EnQueue(Queve &l, Person x)
{
    Node *new_ele = GetNode(x);
    AddTail(l, new_ele);
}

Person Front(Queve &l)
{
	Person x;
    if (IsEmpty(l))
        return x;
    return l.pHead->Info;
}

void PrintQueue(Queve &l)
{
    if(l.pHead == NULL)
    {
        printf("\nDanh sach rong:");
    }
    else
    {
        Node* p;
        p = l.pHead;
        while(p!= NULL)
        {
            printf("\nTen: %14s\nTuoi: %7d\nDiaChi: %10s\nTinhTrang: %5s\n",p->Info.hoten,p->Info.tuoi,p->Info.diachi , p->Info.tinhtrang);
            
            p= p->pNext;

        }
    }
}

void InputQueue(Queve &l)
{
    Person p;
    printf("\nNhap thong tin nguoi benh:");
    printf("HoTen:");
    gets(p.hoten);
    fflush(stdin);
    printf("Tuoi:");
    scanf("%d",&p.tuoi);
    fflush(stdin);
    printf("DiaChi:");
    gets(p.diachi);
    printf("TinhTrang:");
    gets(p.tinhtrang);

    Node *new_node = GetNode(p);

    
    AddTail(l, new_node);

    printf("Da them nguoi vao danh sach!\n");
}

main()
{
    Person Per1 = {"N.V.M.THU",21,"TraCu","Nghien TIKTOK"};
    Person Per2 = {"V.L.TRUONG",24,"TraVinh","Nghien LIENQUAN.MOBILE"};
    Person Per3 = {"K.T.T.NGAN",25,"Travinh","Nghien KIEMTIEN"};
    
    
    Queve my_queve;
    Init(my_queve);
    EnQueue(my_queve,Per1);
    
    EnQueue(my_queve,Per2);
    PrintQueue(my_queve);
    
    EnQueue(my_queve,Per3);
    PrintQueue(my_queve);
    
	
    InputQueue(my_queve);
    
     PrintQueue(my_queve);

    return 0;
}
