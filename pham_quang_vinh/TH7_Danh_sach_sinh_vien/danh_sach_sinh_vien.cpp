#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    int id;
    char name[50];
    int age;
    float score;
    struct Student *next;
}Student;

typedef struct Node
{
    Student Info;
    Node* pNext;
}Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

void Init(List &l)
{ 
    l.pHead = l.pTail = NULL;
}

Node* GetNode(Student x)
{
	Node* p;
    p=new Node;
    if(p==NULL)
    {
    	printf("Khong du bo nho de cap phat cho nut moi!\n");
    	return 0;
	}
	p->Info=x;
	p->pNext=NULL;
	return p;	
}

void AddTail(List &l, Node *new_ele)
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

void addStudent(List &l)
{
    Student sv_moi;
	printf("\n Moi nhap node moi");
    printf("\nID:");
    scanf("%d", &sv_moi.id);
    
    fflush(stdin);
    printf("TEN:");
    gets(sv_moi.name);

    fflush(stdin);
    printf("TUOI:");
    scanf("%d", &sv_moi.age);

    fflush(stdin);
    printf("DTB:");
    scanf("%f", &sv_moi.score);
    
    Node* new_ele = GetNode(sv_moi);
    AddTail(l, new_ele);
}

int deleteStudent(List &l, int id)
{
    Node *p = l.pHead;
    Node *q = NULL;
    while(p != NULL)
    {
	    if(p->Info.id == id) break;
	    q = p;
	    p = p->pNext;
	}
	if(p == NULL) 
	{
	    return 0;
	    printf("\n Khong tim thay Sinh vien co stt %d", id);
	}
	if(q != NULL)
	{
	    if(p == l.pTail)
	        l.pTail = q;
	    q->pNext = p->pNext;
	    delete p;
	}
	else 
	{
	    l.pHead = p->pNext;
	    if(l.pHead == NULL)
	        l.pTail = NULL;
	}
return 1;
}

void updateStudent(List &l, int id)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->Info.id == id)
        {
            printf("\nNhap thong tin sinh vien can sua:\n");
            printf("\nID:");
            scanf("%d", &p->Info.id);

            fflush(stdin);
            printf("\nTEN:");
            gets(p->Info.name);

            fflush(stdin);
            printf("\nTUOI:");
            scanf("%d", &p->Info.age);

            fflush(stdin);
            printf("\nDTB:");
            scanf("%f", &p->Info.score);

            printf("\nDa cap nhat thong tin sinh vien co ID %d\n", id);
            return;
        }
        p = p->pNext;
    }
    printf("\nKhong tim thay Sinh vien co ID %d\n", id);
}

void displayStudents(List &l)
{
    if(l.pHead==NULL)
    {
	    printf("Danh sach rong\n");
	}
	else
	{
	    Node* p;
	    p=l.pHead;
	    while(p!=NULL)
	    {
	        printf("%3d %10s %5d %.2f \n", p->Info.id, p->Info.name, p->Info.age, p->Info.score);
	        p = p->pNext;
		}
	}
}

void saveStudentsToFile(List l, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Khong the mo file %s de ghi\n", filename);
        return;
    }

    Node *p = l.pHead;
    while (p != NULL)
    {
        fprintf(file, "%d;%s;%d;%.2f\n", p->Info.id, p->Info.name, p->Info.age, p->Info.score);
        p = p->pNext;
    }

    fclose(file);
    printf("Danh sach sinh vien da duoc luu vao file %s\n", filename);
}

int main()
{
	List(l);
	Init(l);
    Student *head = NULL;
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

        switch (choice) {
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            case 1:
                addStudent(l);
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%d", &id);
                deleteStudent(l, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua: ");
                scanf("%d", &id);
                updateStudent(l, id);
                break;
            case 4:
                displayStudents(l);
                break;
            case 5:
                printf("Nhap ten file de luu danh sach sinh vien: ");
                char filename[100];
                scanf("%s", filename);
                saveStudentsToFile(l, filename);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (choice != 0);

    return 0;


}
