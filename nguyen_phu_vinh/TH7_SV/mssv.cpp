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

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

Node* GetNode(mssv_ele x)
{
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Khong du bo nho.");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
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

void load_data(List &l, const char* file_name)
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

 Node* FindNodeByID (List &l, char ma[])
{
	Node *p;
	p=l.pHead;
	
	while ((p!=NULL) && (p->Info.ma != ma))
		p=p->pNext;
	
	return p;	
} 

void PrintList(List &l)
{
    if (l.pHead == NULL)
    {
        printf("Danh sach rong.\n");
    }
    else
    {
        Node* p = l.pHead;
        while (p != NULL)
        {
            printf("%5s %5s\n", p->Info.ma, p->Info.ten);
            p = p->pNext;
        }
    }
}

int main()
{
    List list_bac, list_he, list_nganh, list_khoa;

    Init( list_bac);
    load_data(list_bac, "bac.txt");
    PrintList(list_bac);

    Init( list_he);
    load_data(list_he, "he.txt");
    PrintList(list_he);

    Init( list_nganh);
    load_data(list_nganh, "nganh.txt");
    PrintList(list_nganh);

    Init( list_khoa);
    load_data(list_khoa, "khoa.txt");
    PrintList(list_khoa);

	return 0;
	

}

