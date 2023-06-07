#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct mssv_ele
{
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
    
} mssv_ele;

typedef struct Node
{
    mssv_ele info;
    struct Node* pNext;
} Node;

typedef struct List
{
    Node* pHead;
    Node* pTail;
} List;

void Init(List* l)
{
    l->pHead = l->pTail = NULL;
}

Node* GetNode(mssv_ele x)
{
    Node* p;
    p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho\n");
        return NULL;
    }
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(List* l, Node* new_ele)
{
    if (l->pHead == NULL)
    {
        l->pHead = new_ele;
        l->pTail = l->pHead;
    }
    else
    {
        l->pTail->pNext = new_ele;
        l->pTail = new_ele;
    }
}

void load_data(char* filename, List* l)
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
            mssv_ele ele_tam;
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

void printSV(List* l)
{
    if (l->pHead == NULL)
    {
        printf("Danh sach rong\n");
    }
    else
    {
        Node* p = l->pHead;
        while (p != NULL)
        {
            printf("%10s%10s\n", p->info.ma, p->info.ten);
            p = p->pNext;
        }
    }
}

int main()
{
    List l;
    Init(&l);

    load_data("he.txt", &l);

    printSV(&l);

    return 0;
}

