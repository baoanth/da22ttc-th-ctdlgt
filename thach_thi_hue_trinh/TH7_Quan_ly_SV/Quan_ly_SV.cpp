#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	int mssv;
    char fname[100];
    char lname[100];
    int tuoi;
    float diem;
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
		l.pTail= l.pHead;
	}
	else
	{
		l.pTail->pNext =new_ele;
		l.pTail=new_ele;
	}
} 

/*
void AddStudent(List &l, Node* new_ele)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail  = l.pHead;
	}
	else 
	{	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}
*/
void NhapIF(List &l, Student x)
{

    Node* new_ele = GetNode(x);
    	AddTail(l, new_ele);
}

void AddStudent(List &l)
{
    Student stu_tam;
    
    printf("\nNhap MSSV: ");
    scanf("%d", &stu_tam.mssv);

    fflush(stdin);
    printf("Nhap Ho: ");
    gets(stu_tam.fname);
    
    fflush(stdin);
    printf("Nhap Ten: ");
    gets(stu_tam.lname);

    fflush(stdin);
    printf("Nhap Tuoi: ");
    scanf("%d",&stu_tam.tuoi);

    fflush(stdin);
    printf("Nhap diem tb: ");
    scanf("%.2f",&stu_tam.diem);

	printf("\n");
  	NhapIF(l, stu_tam);

}

void DeleteStudent (List &l, int idx)
{
	Node *p = l.pHead;
	Node *q = NULL;
	
	while(p != NULL)
	{
		if( p->Info.mssv == idx) 
			break;
		q = p;
		p = p->pNext;
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
}

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

int UpdateStudent(List &l, int idx)
{
	
	Node *p = l.pHead;
	Node *q = NULL;
	
	while(p != NULL)
	{
		if( p->Info.mssv == idx) 
			break;
		q = p;
		p = p->pNext;
	}
	if(q != NULL) 
	{
		if(p == l.pTail)
		l.pTail = q;
		q->pNext = p->pNext;
		delete p;
		AddStudent(l);
	}
	else 
	{
		l.pHead = p->pNext;
		if(l.pHead == NULL)
			l.pTail = NULL;
	}
	return 1;
}
void DisplayStudents(List &l)
{
	if(l.pHead==NULL)
		printf("\nDanh sach rong");
	else
	{
		Node *p;
		p = l.pHead;
		
		printf("\n   MSSV   |    HO    |   TEN   | TUOI | DTB ");
		while (p!= NULL)
		{
			printf("\n%10d|%10s|%9s|%6d|%5f\n",p->Info.mssv, p->Info.fname, p->Info.lname, p->Info.tuoi, p->Info.diem);
			p = p->pNext;
		}
		printf("\n");
	}
	
}
void SaveStudentsToFile(List &l, char *file_name)
{
	
	FILE *outfile;
	outfile = fopen(file_name, "w");
	
	if(l.pHead==NULL)
		fprintf(outfile,"\nDanh sach rong");
	else
	{
		Node *p;
		p = l.pHead;
		
		fprintf(outfile,"\n   MSSV   |    HO    |   TEN   | TUOI | DTB ");
		while (p!= NULL)
		{
			fprintf(outfile,"%10d|%10s|%9s|%6d|%5f\n",p->Info.mssv, p->Info.fname, p->Info.lname, p->Info.tuoi, p->Info.diem);
			p = p->pNext;
		}
		fprintf(outfile,"\n");
	}
	if(outfile!=0)
		printf("Ghi tep thanh cong!");
	else
		printf("Ghi tep that bai!");
	fclose(outfile);	
}
//void freeStudents(Student *h)

int main()
{
 	List meo;
 	Init(meo);
 	int c,idx;
    while(1)
	 {
        printf("\n---- CHUONG TRINH QUAN LY SINH VIEN ----\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &c);
		printf("\n");
		if(c==0)
		{
			printf("Cam on ban da su dung chuong trinh!\n");
				break;
		}
			
		else if(c==1)
        {
           AddStudent(meo);
	    }
	    else if(c==2)
	    {
	    	printf("Danh sach sau khi xoa:\n");
	    	DeleteStudent(meo,idx);
	    }
    	else if(c==3)
    	{
    		printf("Danh sach sau khi sua:\n");
    		UpdateStudent(meo,idx);
    	}
   		else if(c==4)
   		{
   			printf("Danh sach sinh vien:\n");
   			DisplayStudents(meo);
   		}
   		else if(c==5)
   		{
   			printf("Nhap ten file de luu Danh sach Sinh vien");
   			char file_name[100];
   			scanf("%s",&file_name);
   			SaveStudentsToFile(meo,file_name);
   		}
	} 
	return 0;
}
