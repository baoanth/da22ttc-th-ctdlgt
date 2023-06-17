#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LENGTH 100

typedef struct MSSV
{
	char masv[2];
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
	
	while ((p != NULL)&& (p->Info.masv != masv))
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
		line[strcspn(line, ",")] = '\0';
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
		AddTail(&l,ele_tam);
	}
	fclose(file);
	return 0;
}









