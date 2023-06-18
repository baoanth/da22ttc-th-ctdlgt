#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student 
{
    int id;
    char name[100];
    int age;
    float score;
    struct Student *next;
} Student;

void AddStudent(Student **head) 
{
    Student *St = (Student *)malloc(sizeof(Student));
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &St->id);
    printf("Nhap ho va ten: ");
    scanf("%s", &St->name);
    printf("Nhap so tuoi: ");
    scanf("%d", &St->age);
    printf("Nhap diem trung binh: ");
    scanf("%f", &St->score);
    St->next = NULL;
    
    if (*head == NULL) 
    {
        *head = St;
    } 
	else 
    {
        Student *temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = St;
    }
}

void DeleteStudent(Student **head, int id)
{
	Student *St = *head;
    Student *temp = NULL;
    if(*head!=NULL)
    {
    	while (St != NULL) 
    	{
        	if (St->id == id) 
        	{
           		if (temp == NULL) 
           		{
                   *head = St->next;
            	} 
				else 
            	{
                	temp->next = St->next;
            	}
	            delete(St);
	            printf("Da xoa sinh vien co ma so %d.\n", id);
       		}
        	temp = St;
        	St = St->next;  
    	}  	
    }
    else
    {
    	printf("Khong tim thay sinh vien can xoa co ma so %d.\n", id); 
	} 
}

void UpdateStudent(Student *head, int id)
{
  	 Student *St = head;
	 if (head != NULL) 
	 {
	    while (St != NULL) 
	    {
	        if (St->id == id) 
	        {
	            printf("Nhap ho va ten: ");
				scanf("%s", &St->name);
			    printf("Nhap so tuoi: ");
			    scanf("%d", &St->age);
			    printf("Nhap diem trung binh: ");
			    scanf("%f", &St->score);
	        }
	        St = St->next;
	    }
	}
	else
	{
		printf("Khong tim thay sinh vien can sua co ma so %d.\n", id); 
	}
}

void DisplayStudents(Student *head)
{
	Student *St = head;
	if(head == NULL)
	{
		printf("Danh sach sinh vien rong.\n");
	}
	else
	{
		printf("%12s %20s %15s %25s\n", "MSSV", "HO VA  TEN", "TUOI", "DIEM TRUNG BINH");
		while(St != NULL)
		{
			printf("%12d %20s %15d %25.2f\n", St->id, St->name, St->age, St->score);
        	St = St->next;
		}
	}
}

void SaveStudentsToFile(Student *head, const char *filename)
{
	FILE *f = fopen(filename, "w");
    if (f == NULL) 
    {
        printf("Khong the mo file.\n");
    }
    Student *St = head;
	fprintf(f, "%12s %20s %15s %25s\n", "MSSV", "HO VA  TEN", "TUOI", "DIEM TRUNG BINH");
	while(St != NULL)
	{
		fprintf(f, "%12d %20s %10d %10.2f\n", St->id, St->name, St->age, St->score);
	}
    printf("Da luu vao  file.\n");
    fclose(f);
}

void FreeStudents(Student *head)
{
    Student *St = head;
    while (St != NULL) 
    {
        Student *next = St->next;
        free(St);
        St = next;
    }
}

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
        printf("\n");

        switch (choice) {
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            case 1:
                AddStudent(&head);
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%d", &id);
                DeleteStudent(&head, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua: ");
                scanf("%d", &id);
                UpdateStudent(head, id);
                break;
            case 4:
                DisplayStudents(head);
                break;
            case 5:
                printf("Nhap ten file de luu danh sach sinh vien: ");
                char filename[100];
                scanf("%s", filename);
                SaveStudentsToFile(head, filename);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (choice != 0);

    FreeStudents(head);

    return 0;
}

