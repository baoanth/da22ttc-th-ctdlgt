#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100 

typedef struct MSSV
{
    char ma[20];
    char ten[MAX_LINE_LENGTH];
} MSSV;

typedef struct Node
{
    MSSV Info;
    Node* pNext;    
}Node;

Node* Get_Node(MSSV x)
{
	Node *p;
	p = new Node;
	
	if(p==NULL)
	{
		printf("Khong du bo nho!");
		return 0;
	}
	p->Info=x;
	p->pNext=NULL;
	
	return p;
}

typedef struct List
{
    Node* pHead;
    Node* pTail;
}List;

void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

void Add_First(List &l, Node* new_ele)
{
	if(l.pHead=NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		new_ele->pNext=l.pHead;
		l.pHead=new_ele;
	}
}

void Add_Tail(List &l, Node* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail=new_ele;
	}
}

void addNode(Node **head, Node *p)
{
    if (*head == NULL)
        *head = p;
    else
    {
        Node *q = *head;
        while (q->pNext != NULL)
        {
            q = q->pNext;
        }
        q->pNext = p;
    }
}

Node* loadData(char* fileName, List &l)
{
     FILE *infile = fopen(fileName, "r");
    if (infile != NULL)
    {
        Node *head = NULL;
        char line[100];
        while (fgets(line, sizeof(line), infile))
        {
            line[strcspn(line, "\n")] = '\0';
            MSSV x;
            sscanf(line, "%[^,], %[^\n]", x.ma, x.ten);
            Node *tmp = Get_Node(x);
            addNode(&head, tmp);
        }
        fclose(infile);
        return head;
    }
    return NULL;
  }


char *getName(Node *p, char ma[])
{
    while (p != NULL)
    {
        if (strcmp(p->Info.ma, ma) == 0)
            return p->Info.ten;

        p = p->pNext;
    }
    return ma;
}

void Find_MSSV(Node *bacList, Node *heList, Node *nganhList, Node *khoaList, const char *studentID)
{
    if (strlen(studentID) != 9)
    {
        printf("Ma so sinh vien khong hop le\n");
        return;
    }

    char bacCode[2];
    strncpy(bacCode, studentID, 1);
    bacCode[1] = '\0';

    char heCode[2];
    strncpy(heCode, studentID + 1, 1);
    heCode[1] = '\0';

    char nganhCode[3];
    strncpy(nganhCode, studentID + 2, 2);
    nganhCode[2] = '\0';

    char khoaCode[3];
    strncpy(khoaCode, studentID + 4, 2);
    khoaCode[2] = '\0';

    char *bacName = getName(bacList, bacCode);
    char *heName = getName(heList, heCode);
    char *nganhName = getName(nganhList, nganhCode);
    char *khoaName = getName(khoaList, khoaCode);

    printf("%s %s %s khoa %s \n", bacName, heName, nganhName, khoaName);
}

int main()
{
	List l;
	Node *bac = NULL;
    Node *khoa = NULL;
    Node *nganh = NULL;
    Node *he = NULL;

    bac = loadData("bac.txt", l);
    khoa = loadData("khoa.txt", l);
    nganh = loadData("nganh.txt", l);
    he = loadData("he.txt", l);

    char ma[10];
    printf("Nhap ma sinh vien: ");
    scanf("%s", &ma);

    Find_MSSV(bac, he, nganh, khoa, ma);
 
  return 0;
}
