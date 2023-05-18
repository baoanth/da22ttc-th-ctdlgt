#include <stdio.h>
#include <conio.h>
#include <string.h>
// struct person with 3 fields
typedef struct Person
{
    int id;
    char fname[20];
    char lname[20];
}Person;

typedef struct Node
{
    Person Info;
    Node* pNext;    
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

Node* GetNode(Person x)
{
    Node *p;
    p = new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead ==NULL)
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;      
    }
    else
    {
        new_ele ->pNext = l.pHead;    
        l.pHead = new_ele;
    }
}

void AddTail(List &l, Node* new_ele)
{
    if (l.pHead==NULL)
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

<<<<<<< HEAD
//Ham nhap Node moi vao vi tri tuy y
void InputNode(List &l)
{
    Person per_tam; //Cau truc chua person moi
    printf("\nNhap node moi\n");
    
    printf("ID: ");
    scanf("%d", &per_tam.id);
	
	fflush(stdin);
    printf("First name: ");
    gets(per_tam.fname);

	fflush(stdin);
    printf("Last name: ");
    gets(per_tam.lname);

    Node *new_ele = GetNode(per_tam) ; // Node moi

    
    printf("\nChon vi tri cho nut moi: 1. Dau danh sach; 2.Cuoi danh sach  ");
    
    fflush(stdin);
	int chon=0;
	scanf("%d", &chon);
    switch (chon)
    {
        case 1: 
            AddFirst(l, new_ele );
            printf("Da them new_ele vao dau danh sach\n");
            break;
        case 2:
            AddTail(l, new_ele);
            printf("Da them new_ele vao cuoi danh sach\n");
            break;
        default:
            AddTail(l, new_ele );
            printf("Ban nhap lua chon xa lo; Da them new_ele vao cuoi danh sach\n");
            break;
    }
}


void RemoveHead(List &l)
=======
Node* FindNodeByID(List l, int idx)
>>>>>>> parent of 31600ad (Add Remove Node)
{
    Node *p;
    p =l.pHead;

    while ((p!=NULL) && (p->Info.id !=idx))
        p = p->pNext;

    return p;
}



void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

<<<<<<< HEAD
<<<<<<< HEAD
void PrintNode(Node *p)
{
    printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
}

=======
<<<<<<< HEAD
>>>>>>> 0c281b7846b87694a39cb32b4f8c6d9e0b7e1017
=======
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
void PrintList(List &l)
{
<<<<<<< HEAD

=======
>>>>>>> parent of 31600ad (Add Remove Node)
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %20s %20s\n", p->Info.id, p->Info.fname, p->Info.lname );
			p = p->pNext;
		}		
<<<<<<< HEAD
	}      

=======
	}
>>>>>>> parent of 31600ad (Add Remove Node)
}
=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d




int main()
{
<<<<<<< HEAD
    struct Person per1 = {1, "Nguyen", "Le Hoa Binh"};
    struct Person per2 = {2, "Le", "Binh"};
    struct Person per3 = {3, "Tran", "Hoa"};

    Node *new_ele1 = GetNode(per1);
    Node *new_ele2 = GetNode(per2);
    Node *new_ele3 = GetNode(per3);
    
	List my_list;
    Init(my_list);

    AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);

    //AddTail(my_list, new_ele1);
    // AddTail(my_list, new_ele2);
    // AddTail(my_list, new_ele3);
=======
    struct Person per1 = {1, "Nguyen", "Le Hoa Binh" };
	struct Person per2 = {2, "Le", "Binh" };
	struct Person per3 = {3, "Tran", "Hoa" };
    
    Node* new_ele1  = GetNode(per1);
    Node* new_ele2  = GetNode(per2);
    Node* new_ele3  = GetNode(per3);
    List my_list;
    Init(my_list);

	//AddFirst(my_list, new_ele1);
    AddFirst(my_list, new_ele2);
    AddFirst(my_list, new_ele3);

<<<<<<< HEAD
	
    AddTail(my_list, new_ele1);
    //AddTail(my_list, new_ele2);
    //AddTail(my_list, new_ele3);
>>>>>>> parent of 31600ad (Add Remove Node)

<<<<<<< HEAD
    PrintList(my_list);
    
	int idx;
    printf("\nNhap id can tim ");
    scanf("%d", &idx);
<<<<<<< HEAD
    
	Node *node_kq = FindNodeByID(my_list, idx);
    if (node_kq != NULL)
=======
    Node *node_kq  = FindNodeByID(my_list, idx);
    if (node_kq!=NULL)
>>>>>>> parent of 31600ad (Add Remove Node)
        PrintNode(node_kq);
    else   
        printf("Tim khong thay node co id %d", idx);
<<<<<<< HEAD

    // PrintList(my_list);

    printf("\nNhap id can xoa ");
    scanf("%d", &idx);
    
	int kq = RemoveNode(my_list, idx);
    if (kq!=0)    
        printf("Da xoa Node co id = %d", idx);
    else
        printf("Khong the xoa nut co id = %d", idx);
    printf("\nDanh sach sau thao tac \n"); 

    PrintList(my_list);

    InputNode(my_list);
    InputNode(my_list);
    InputNode(my_list);

    PrintList(my_list);
=======
=======
<<<<<<< HEAD
    PrintList(my_list);
>>>>>>> 53216d064b8a49cd04e413668fa08fdf5874804b
>>>>>>> parent of 31600ad (Add Remove Node)

    return 0;

=======
>>>>>>> 111ae627302a13f94f32aa31b4a57d5139f9673d

}
