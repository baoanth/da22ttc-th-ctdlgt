#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai b�o cau truc du li�u Sinh vi�n
typedef struct Student
{
    int id;
    char name[100];
    int age;
    float score;
    struct Student *next;
} Student;


//Them 1 sv
void AddAfter( list &l, Node *q, Node * new_ele)
{
	if ( q!=NULL) 
	{
		new_ele -> pNext =q -> pNext
	}
}

//Xoa 1 sv
int delNode(Student &t , int x)
{
	if(t==NULL)
		return 0;
	if(t -> id > x)
		return delNode (t -> pLeft, x);
	if(t -> id < x)
		return delNode (t -> pRight, x);
	else 
	{
		TNode*	p = t;
			if(t -> pLeft == NULL )
				t = t -> pRight;
			else 
				if( t -> pRight == NULL) 
					t = t -> pLeft;	
				else
				{
					TNode*	q = t -> pRight;
					searchStandFor(p, q);
				}
		delete p;		
	}
}



















// Khai b�o c�c h�m
void addStudent(Student **head);
void deleteStudent(Student **head, int id);
void updateStudent(Student *head, int id);
void displayStudents(Student *head);
void saveStudentsToFile(Student *head, const char *filename);
void freeStudents(Student *h
int main() 
{
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
                addStudent(&head);
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua: ");
                scanf("%d", &id);
                updateStudent(head, id);
                break;
            case 4:
                displayStudents(head);
                break;
            case 5:
                printf("Nhap ten file de luu danh sach sinh vien: ");
                char filename[100];
                scanf("%s", filename);
                saveStudentsToFile(head, filename);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (choice != 0);

    freeStudents(head);

    return 0;

