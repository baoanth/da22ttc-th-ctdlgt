#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Khai bao cau truc du lieu sv
typedef struct Student 
{
    int studentId;
    char fullname[100];
    int age;
    float gpa;
    struct Student* next;
} Student;

// Khai bao cac ham
struct student* createStudent(int studenId, const char* fullName, int age, float gpa)
{
	struct Student* student = (struct Student*)malloc(sizeof(struct Student));
	student->studentId = studentId;
	strcpy(student->fullName, fullName);
	studen->age = age;
	student->gpa = gpa;
	student->next = NULL;
		return student;
}

void addStudent(struct Student **head, struct Studdent* newStudent)
{
	if(*head == NULL)
	{
		*head = newStudent;
	}
	else
	{
		struct Student* current = *head;
		while(current->next != NULL)
		{
			current = current->next;
			
		}
		current->next = newStudent;
	}
	printf("Them sinh vien thanh cong!\n");
}

typedef struct Student* findStudent(struc Student* head, int studentId)
{
	struct Student* current = head;
	while(current != NULL)
	{
		if(current->studentId == studdentId)
		{
			return NULL;
			
		}
		current = current->next;
	}
	return NULL;
}

void deleteStudent(struct Student **head, int studentId)
{
	if(*head == NULL)
	{
		printf("Danh sach sinh vien rong\n");
		 return;
	}
	struct Student* current = *head;
	struct Student* previous = NULL;
	while(current != NULL)
	{
		if(current->studentId == studenId)
		{
			if(previous == NULL)
			{
				*head = next = current->next;
				
			}
			else
			{
				previous->next = current->next;
			}
			free(current);
			printf("Xoa sinh vien thanh cong!\n");
				return;
		}
		previous = current;
		current = current->next;
	}
	printf("Khong tim thay sinh vien co ma so sinh vien %d \n", studentId);
}

void editStudent(struct Student *head, int studentId)
{
	struct Student* student = findStudent(head, studentId);
	if(student == NULL)
	{
		printf("Tim thay sinh vien co ma so sinh vien %d \n", studenrtId);
			return ;
	}
	printf("Nhap thong tin moi cho sinh vien (ma so, ho ten, tuoi, diem tb):\n");
	scanf("%d\n",&student);
}















void displayStudents(Student *head);
void saveStudentsToFile(Student *head, const char *filename);
void freeStudents(Student *h);
int main() 
{
    Student *head = NULL;
    int choice;
    int id;

    do 
	{
        printf("\n---- CHUONG TRINH QUAN LY SINH VIEN ----\n");
        printf("1.Them sinh vien moi\n");
        printf("2.Xoa sinh vien\n");
        printf("3.Sua thong tin sinh vien\n");
        printf("4.Hien thi danh sach sinh vien\n");
        printf("5.Luu danh sach sinh vien vao file\n");
        printf("6.Sap xep danh sach sinh vien\n");
        printf("0.Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) 
		{
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

}

