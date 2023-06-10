#include <stdio.h>
#include <conio.h>
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

char* FindMa(Node *p, char ma[])
{
    while(p != NULL)
    {
    	if(strcmp(p->Info.ma, ma)==0)
    		return p->Info.ten;
    	p = p->pNext;
	}
    return ma;
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

void PhanTichMssv(Node* ListNganh, Node* ListBac, Node* ListHe, Node* ListKhoa, char* Mssv)
{
	if(strlen(Mssv) != 9)
	{
		printf("--- Ma so sinh vien khong dung ---\n");
	}
	
	char bac[2]
	strncpy(bac, Mssv, 1);
	bac[1] = '\0';
	
	char nganh[2]
	strncpy(nganh, Mssv + 1, 1);
	nganh[1] = '\0';
	
	char he[3]
	strncpy(he, Mssv + 2, 2);
	he[2] = '\0';
	
	char khoa[3]
	strncpy(khoa, Mssv + 4, 2);
	khoa[2] = '\0';
	
	char* TenBac = FindMa(ListBac, bac);
	char* TenNganh = FindMa(ListNganh, nganh);
	char* TenHe = FindMa(ListHe, he);
	char* TenKhoa = FindMa(ListKhoa, khoa);
	
	 printf("%s %s %s khoa %s \n", TenBac, tenHe, TenNganh, TenKhoa);
}

int main()
{
	List list_nganh, list_bac, list_he, list_khoa;
	
	Init(list_nganh);
	Init(list_bac);
	Init(list_he);
	Init(list_khoa);
	
	LoatData("nganh.txt", list_nganh);
	LoatData("bac.txt", list_bac);
	LoatData("he.txt", list_bac);
	LoatData("khoa.txt", list_bac);

	
	
	return 0;
}

