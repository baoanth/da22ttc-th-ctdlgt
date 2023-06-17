#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LENGTH 100

typedef struct MSSV
{
	char masv[3];
	char ten[MAX_LINE_LENGTH];
    
}MSSV;

typedef struct Node
{
	MSSV Info;
	Node* pNext;
}Node;

typedef struct List
{
	Node* pHead;
	Node* pTail;
}List;

Node* GetNode(MSSV x)
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

void AddFirst(List &l, Node* new_ele)
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

Node* FindNodeByID (List l, char* masv)
{
	Node *p;
	p=l.pHead;
	
	while ((p != NULL)&& (strcmp(p->Info.masv,masv)))
		p=p->pNext;
	
	return p;	
	
}

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

int LoadData(char* file_name, List &l)
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	char *token;
	char masv[MAX_LINE_LENGTH];
	char ten[MAX_LINE_LENGTH];
	MSSV ele_tam;
	Node *node_tam;
	
	file= fopen(file_name,"r");
	if(file == NULL)
	{
		printf("Khong the mo tep van ban \n");
		return 1;
	}
	
	while(fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';
		token = strtok(line, ",");
		if(token != NULL)
		{
			strcpy(masv,token);
			token = strtok(NULL, ",");
			if(token != NULL)
			{
				strcpy(ele_tam.ten, token);
			}
		}
		node_tam = GetNode(ele_tam);
		AddTail(l,node_tam);
	}
	fclose(file);
}

void PrintList(List &l)
	{
		if(l.pHead == NULL)
			printf("Danh sach rong\n");
		else
		{
			Node *p;
			p = l.pHead;
			while(p != NULL)
			{
				printf("%5s %20s \n", p->Info.masv,p->Info.ten);
				p = p->pNext;
			}
		}	
	}
	
char* SubString(char scr_str[], int start_pos, int len)
{
	char* res_str = (char*) malloc((len+1)* sizeof(char));
	int i;
	for(i=0; i<len; i++)
	{
		res_str[i] = scr_str[start_pos + i];
	}
	res_str[len] = '\0';
		
	return res_str;
}
	
int main()
{
	List list_bac, list_he, list_nganh, list_khoa;
	Init(list_bac);
	Init(list_he);
	Init(list_nganh);
	Init(list_khoa);

	LoadData("bac.txt", list_bac);
	LoadData("he.txt", list_he);
	LoadData("nganh.txt", list_nganh);
	LoadData("khoa.txt", list_khoa);
	
	PrintList(list_bac);
	PrintList(list_he);
	PrintList(list_nganh);
	PrintList(list_khoa);

	char my_masv[10];
	printf("\nNhap MSSV : ");
	gets(my_masv);
	printf("*******************KET QUA TIM KIEM CHO %s*********************\n",my_masv);
	
	char* sub1 = SubString(my_masv,0,1);
	char* sub2 = SubString(my_masv,1,1);
	char* sub3 = SubString(my_masv,2,2);
	char* sub4 = SubString(my_masv,4,2);
	
	Node* p = FindNodeByID(list_bac, sub1);
	printf("%5s %20s \n", p->Info.masv, p->Info.ten);
	
	p = FindNodeByID(list_he, sub2);
	printf("%5s %20s \n", p->Info.masv, p->Info.ten);
	
	p = FindNodeByID(list_nganh, sub3);
	printf("%5s %20s \n", p->Info.masv, p->Info.ten);
	
	p = FindNodeByID(list_khoa, sub4);
	printf("%5s %20s \n", p->Info.masv, p->Info.ten);
	
	return 0;
}	


