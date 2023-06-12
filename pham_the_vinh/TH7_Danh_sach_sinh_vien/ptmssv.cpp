#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

typedef struct MssvEle
{
    char ma[2];
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
} List;

Node *GetNode(MssvEle x)
{
    Node *p;
    p = new Node;

    if (p == NULL)
    {
        printf("--- Khong du bo nho de cap phat ---\n");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;

    return p;
}

void AddTail(List &l, Node *new_ele)
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

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

Node *Find(List l, char* ma)
{
    Node *p;
    p = l.pHead;
    while ((p != NULL) && (strcmp(p->Info.ma, ma)))
        p = p->pNext;
    return p;
}

int LoatData(char* filename, List &l)
{
	FILE* file;
	char line[MAX_LINE_LENGTH];
	char* token;
	char ma[MAX_LINE_LENGTH];
	char ten[MAX_LINE_LENGTH];
	MssvEle ele_tam;
	Node* node_tam;
	
	file = fopen(filename, "r");
	if(file == NULL)
	{
		printf("--- Khong the mo tep ---\n");	
		return 1;
	}
		
	while(fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';
		token = strtok(line, ",");
		
		if(token != NULL)
		{
			strcpy(ele_tam.ma, token);
			token = strtok(NULL, ",");
			
			if(token != NULL)
			{
			strcpy(ele_tam.ten, token);	
			}	
		}
		node_tam = GetNode(ele_tam);
		AddTail(l, node_tam);
	}
	fclose(file);
}

void PrintList(List &l)
{
    if (l.pHead == NULL)
        printf("--- Danh sach rong ---\n");
    else
    {
        Node *p;
        p = l.pHead;
        while (p != NULL)
        {
            printf("%5s %20s\n", p->Info.ma, p->Info.ten);
            p = p->pNext;
        }
    }
}

char* SubString(char scr_str[], int start_pos, int len) 
{
    char* res_str = (char*) malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++) {
        res_str[i] = scr_str[start_pos + i];
    }
    res_str[len] = '\0';

    return res_str;
}

int main()
{
	List list_nganh, list_bac, list_he, list_khoa;
	
	Init(list_bac);
	Init(list_he);
	Init(list_nganh);
	Init(list_khoa);
	
	LoatData("bac.txt", list_bac);
	LoatData("he.txt", list_he);
	LoatData("nganh.txt", list_nganh);
	LoatData("khoa.txt", list_khoa);

	char Mssv[10];
	printf("Nhap ma so sinh vien: ");
	gets(Mssv);

	char* Sub1 = SubString(Mssv, 0, 1);
    char* Sub2 = SubString(Mssv, 1, 1);
    char* Sub3 = SubString(Mssv, 2, 2);
    char* Sub4 = SubString(Mssv, 4, 2);
       
	
	Node* p  = Find(list_bac, Sub1);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p = Find(list_he, Sub2);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p = Find(list_nganh, Sub3);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p = Find(list_khoa, Sub4);
	printf("%5s %20s", p->Info.ma, p->Info.ten);	
	
	
	return 0;
}

