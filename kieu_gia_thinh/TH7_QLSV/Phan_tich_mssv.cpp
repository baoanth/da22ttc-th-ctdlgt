#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct Mssv_Ele
{
    char ma[2];
    char ten[20];
    
} Mssv_Ele;

typedef struct Node
{
    Mssv_Ele Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
} List;

//Viet ham Init
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Ham GetNode
Node *GetNode(Mssv_Ele x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi");
        return 0;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

//Viet ham void AddFirst(List &l, Node *new_ele)
void AddFirst(List &l, Node *new_ele)
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

//Viet ham void AddTail(List &l, Node *new_ele)
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

//Viet ham Load_Data
void Load_Data(char* filename, List* l)
{
    FILE* file_name = fopen(filename, "r");
    if (file_name == NULL)
    {
        printf("Khong tim thay file\n");
        return ;
    }
    else
    {
    	char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), file_name))
        {
            Mssv_Ele ele_tam;
            char* token = strtok(line, ",");
            strcpy(ele_tam.ma, token);

            token = strtok(NULL, ",");
            strcpy(ele_tam.ten, token);

            Node* new_ele = GetNode(ele_tam);
            AddTail(l, new_ele);
        }
        fclose(file_name);
    }
}


//Viet ham in
void Print_List(List &l)
{
	if (l.pHead == NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5s %20s\n", p->Info.ma, p->Info.ten);
			p = p->pNext;
		}		
	}      
}

//Viet ham main
int main()
{
    List bac;
    Init(bac);

    Load_Data("bac.txt", &bac);

    Print_List(bac);

    return 0;
}


