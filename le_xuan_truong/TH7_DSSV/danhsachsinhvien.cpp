#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student{
    int id;
    char ho[20];
    char ten[10];
    int tuoi;
    float dtb;
//    struct Student *next;
} Student;

typedef struct Node
{
    Student Info;
    Node *pNext;
}Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
}List;

Node* GetNode(Student x)
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

void AddTail(List &l, Node *new_ele)
{
    if(l.pHead==NULL)
    {
	    l.pHead=new_ele;
	    l.pTail=l.pHead;
	}
	else
	{
	    l.pTail->pNext = new_ele;
        l.pTail = new_ele;
	}
}

char IsEmpty(List &l)
{
    if(l.pHead == NULL)	return 1;
    else return 0;
}

void EnQueue(List &l, Student x)
{
    Node* new_ele = GetNode(x);
    AddTail(l, new_ele);
}

void AddStudent(List &l)
{
	Student per_tam;
   
    printf("\nMSSV : ");
    scanf("%d", &per_tam.id);

    fflush(stdin);
    printf("Ho : ");
    gets(per_tam.ho);
    
    fflush(stdin);
    printf("Ten : ");
    gets(per_tam.ten);
   
    fflush(stdin);
    printf("Tuoi : ");
    scanf("%d", &per_tam.tuoi);

    fflush(stdin);
    printf("Diem TB : ");
    scanf("%f", &per_tam.dtb);

  	EnQueue(l, per_tam);
}

int DeleteStudent(List &l, int id)
{
	Node *p = l.pHead;
	Node *q = NULL;
	
	while(p != NULL)
	{
		if(p->Info.id==id)	break;
		q = p;
		p = p->pNext;
	}
	
	if(p==NULL)	return 0;

	if(q!=NULL)
	{
		if(p == l.pTail)
			l.pTail = q;
			
		q->pNext= p->pNext;
		delete p;
	}
	else
	{
		l.pHead= p->pNext;
		if(l.pHead==NULL)
			l.pTail==NULL;
	}
	return 1;
}

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

int UpdateStudent(List &l, int id)
{
	Node *p = l.pHead;
	Node *q = NULL;
	
	while(p != NULL)
	{
		if(p->Info.id==id)	break;
		q = p;
		p = p->pNext;
	}
	
	if(p==NULL)	return 0;

	if(q!=NULL)
	{
		if(p == l.pTail)
			l.pTail = q;
			
		q->pNext= p->pNext;
		delete p;
		AddStudent(l);
	}
	else
	{
		l.pHead= p->pNext;
		if(l.pHead==NULL)
			l.pTail==NULL;
	}
	return 1;
}

void DisplayStudents(List &l)
{
    if(l.pHead == NULL)
    {
        printf("\nDanh sach rong!\n");
    }
    else
    {
        Node* p;
        p = l.pHead;
        
        printf("\n   MSSV   |    HO VA TEN LOT   |    TEN   |TUOI| DTB ");
        while(p!= NULL)
        {
            printf("\n%10d|%20s|%10s|%4d|%.1f", p->Info.id, p->Info.ho ,p->Info.ten , p->Info.tuoi, p->Info.dtb);
            p = p->pNext;
        }
        printf("\n");
    }
}

void SaveStudentsToFile(List &l, char *filename)
{
	FILE *outfile;
	outfile = fopen(filename, "w");
	
	if(l.pHead == NULL)
    {
        fprintf(outfile,"\nDanh sach rong!\n");
    }
    else
    {
        Node* p;
        p = l.pHead;
        
        fprintf(outfile,"\n   MSSV   |    HO VA TEN LOT   |    TEN   |TUOI| DTB ");
        while(p!= NULL)
        {
            fprintf(outfile,"\n%10d|%20s|%10s|%4d|%.1f", p->Info.id, p->Info.ho ,p->Info.ten , p->Info.tuoi, p->Info.dtb);
            p = p->pNext;
        }
        printf("\n");
    }
    
    if(outfile!=0)
	   printf("Ghi file thanh cong!");
	else 
	   printf("Loi! Ghi file khong thanh cong");
    fclose(outfile);
}
	
//void freeStudents(Student *h);

void SortList(List &l)
{
	for(Node *p=l.pHead; p != NULL; p = p->pNext)
	{		
		for(Node *q = p->pNext; q != NULL; q = q->pNext)
 		{
   			if(p->Info.id > q->Info.id)
     		{
      			Student t = p->Info;
       			p->Info = q->Info;
       			q->Info = t;		
     		}	
  		}
 	}
}

int main() 
{

    List my_list;
    Init(my_list);
    int choice;
    int id;

    do {
        printf("\n---- CHUONG TRINH QUAN LY SINH VIEN ----\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 0:
                printf("\nCam on ban da su dung chuong trinh!\n");
                break;
            case 1:
                AddStudent(my_list);
                break;
            case 2:
                printf("\nNhap ma so sinh vien can xoa: ");
                scanf("%d", &id);
                DeleteStudent(my_list, id);
                break;
            case 3:
                printf("\nNhap ma so sinh vien can sua: ");
                scanf("%d", &id);
                UpdateStudent(my_list, id);
                break;
            case 4:
            	printf("\nDanh sach sinh vien:");
                DisplayStudents(my_list);
                break;
            case 5:
                printf("\nNhap ten file de luu danh sach sinh vien: ");
                char filename[100];
                scanf("%s", &filename);
                SaveStudentsToFile(my_list, filename);
                break;
            case 6:
            	SortList(my_list);
            	printf("\nDanh sach da duoc sap xep!\n");
            	break;
            default:
                printf("\nLua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    }while (choice != 0);

   // freeStudent(my_list);

    return 0;
}


