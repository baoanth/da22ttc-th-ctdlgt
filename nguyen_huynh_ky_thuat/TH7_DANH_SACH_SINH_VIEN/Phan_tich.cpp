#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct MssvEe
{
	char ma [2];
	char ten[MAX_LINE_LENGTH];
}MssvEle; 

typedef struct Node 
{
	MssvEle Info;
	Node *pNext;
} Node;

typedef struct List
{
	Node *pHead;
	Node *pTail;
} List ;

Node *GetNode(MssvEle x)
{
	Node *p;
	p = new Node;
	if (p == NULL)
	{
		printf("khong du bo nho de cap nhat cho nut moi");
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
		new_ele ->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(List &l, Node* new_ele)
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

Node *FindNodeByID(List l, char* ma)
{
	Node *p;
	p = l.pHead;
	
	while ((p != NULL)&&(strcmp(p->Info.ma)))
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
	MssvEle ele_tam;
	
	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("khong tim thay\n");
		return 1;
	}
	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line,"\n")] = '\0';
		token = strtok(line, ",");
		
		if(token !=NULL)
		{
			strcpy(ele_tam.ma, token);
			token = strtok(NULL,",");
			if(token != NULL)
			{
				strcpy(ele_tam.ten, token);
			}
		}
		Node_tam = GetNode(ele_tam);
		AddTail(l, Node_tam);
	}
	fclose(file);
}

