#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mssv_ele
{
    char* ma;
    char* ten;
} mssv_ele;

typedef struct Node
{
    mssv_ele Info;
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
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat cho nut moi!\n");
        return NULL;
    }
    p->Info = x;
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

void load_data(List* l, const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Khong mo duoc tap tin %s \n", file_name);
        return;
    }

    char buffer[50];
    char* token;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        token = strtok(buffer, ",");
        if (token != NULL)
        {
            char* ma = strdup(token);

            token = strtok(NULL, ",");
            if (token != NULL)
            {
                char* ten = strdup(token);

                mssv_ele student;
                student.ma = ma;
                student.ten = ten;

                Node* new_node = GetNode(student);
                AddTail(l, new_node);
            }
        }
    }

    fclose(file);
}

void printStudent(List* l)
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
            printf("%5s %3s\n", p->Info.ma, p->Info.ten);
            p = p->pNext;
        }
    }
}

int main()
{
    List l;
    Init(&l);

    load_data(&l, "bac.txt");
    load_data(&l, "he.txt");
    load_data(&l, "khoa.txt");
    load_data(&l, "nganh.txt");
    printStudent(&l);

    return 0;
}




	
