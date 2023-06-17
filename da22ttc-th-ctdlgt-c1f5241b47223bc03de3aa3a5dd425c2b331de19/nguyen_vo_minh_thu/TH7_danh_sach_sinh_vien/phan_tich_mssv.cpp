#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct MssvEle
{
	char mssv[2];
	char ten[MAX_LINE_LENGTH];
}MssvEle;

typedef struct Node 
{
	MssvEle Info;
	Node *pNext;
}Node;

typedef struct List 
{
	Node *pHead;
	Node *pTail;
}List;

Node *GetNode(MssvEle x)
{
	Node *p;
	p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap nhat cho nut moi ");
		return 0;
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
		l.pTail = l.pHead;
	}
	else 
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(List &l, Node* new_ele)
{
	if (l.pHead == NULL)
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

Node *FindNodeByID(List l, char* ma)
{
	Node *p;
	p = l.pHead;
	
	while ((p !=NULL)) && (strcmp(p->Info.ma, ma))
		p = p->pNext;
		
	return p;
}

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

int LoadData(char* filename, List &l)
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	char *token;
	char ma[MAX_LINE_LENGTH];
	char ten[MAX_LINE_LENGTH];
	MSSVELE ele_tam;
	
	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Khong tim thay\n ");
		return 1;
	}
	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(ine, "\n")] = '0';
		token = strtok(line, ",");
		if(token != NULL)
		{
			strcpy(ele_tam.ten, token);
		}
		node_tam = GetNode(ele_tam);
		AddTail(l, node_tam);
	}
	fclose(file);
}

void PrintList(List &l)
{
	if(l.pHead == NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHaed;
		while (p != NULL)
		{
			printf("%5d %20ds\n", p->Info.ma, p->Info.ten);
			p = p->pNext;
		}
	}
}

int main()
{
	List list_bac, list_he, list_khoa, list_nganh;
	
	Init(list_bac);
	Init(list_he);
	Init(list_khoa);
	Init(list_nganh);
	
	LoadData("bac.txt", list_bac);
	LoadData("he.txt", list_he);
	LoadData("khoa.txt", list_khoa);
	LoadData("nganh.txt", list_nganh);
	
	PrintList(list_bac);
	PrintList(list_he);
	PrintList(list_khoa);
	PrintList(list_nganh);
	
	return o;
}














