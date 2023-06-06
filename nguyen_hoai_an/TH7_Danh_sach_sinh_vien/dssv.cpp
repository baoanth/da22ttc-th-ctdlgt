#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Student 
{
    int id;
    char name[100];
    int age;
    float score;
    struct Student *next;
} Student;

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
    p = new Node;
    if(p==NULL)
    {
        printf("Khong du bo nho.");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(List &l, Node *new_ele)
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

// Khai báo các hàm
void addStudent(List &l)
{
    Student sv;
    printf("Them Node moi ");
    printf("Id: ");
    scanf("%d", &sv.id);

    printf("Ho ten: ");
    gets(sv.name);

    printf("Tuoi: ");
    scanf("%d", &sv.age);

    printf("Diem trung binh: ");
    scanf("%f", &sv.score);

    Node* new_ele = GetNode(sv);
    AddTail(l, new_ele);

}

void deleteStudent(List &l, int id)
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
	    printf(" Khong tim thay ", id);
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
    Node *p = pHead;
    while (p != NULL && strcmp(p->Info.id) != 0)
    {
        p = p->next;
    }
    if (p == NULL)
        printf("Khong tim thay sinh vien co ma so %d ", id);
    else
    {
        printf("Nhap ma so moi: ");
        fflush(stdin);
        gets(p->Info.id);
        printf("Nhap ten moi: ");
        gets(p->Info.name);
        printf("Nhap tuoi moi: ");
        scanf("%d", &p->Info.age);
        printf("Nhap diem trung binh moi: ");
        scanf("%f", &p->Info.score);
    }
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
	        printf("%3d %15s %5d %5f \n", p->Info.id, p->Info.name, p->Info.age, p->Info.score);
	        p = p->pNext;
		}
	}
}

void saveStudentsToFile(List &l, const char *filename)
{
    FILE *file = fopen (filename ,"w");
    if(file = NULL)
    {
        printf("Khong the mo", filename);
        return ;
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

/*void freeStudents(List &l)
{

}*/

int main() 
{
    Student *head = NULL;
    int choice;
    int id;
    List(l);
    Init(l);

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

  //  freeStudents(head);

    return 0;

}
