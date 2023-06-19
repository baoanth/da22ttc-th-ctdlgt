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

Node* FindEleByMa(List l, char* ma)
{
    Node* p;
    p = l.pHead;

    while((p!=NULL) && (strcmp(p->info.ma, ma)))
        p =p->pNext;
    return p;

}
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

char* subString(char scr_str[], int start_pos, int len)
{
    char* res_str = (char*)malloc((len +1)* sizeof(char));
    int i;
    for(i = 0; i <len ; i++)
    {
        res_str[i] = scr_str[start_pos +i];

    }
    res_str[len]= '\0';
    return res_str;

}

int main()
{
   /* List l;
    Init(&l);

    load_data("bac.txt", &l);
    printSV(&l);

    return 0;*/

    List list_bac, list_he, list_nganh, list_khoa;
    Init(&list_bac);
    Init(&list_he);
    Init(&list_nganh);
    Init(&list_khoa);

    load_data("bac.txt", &list_bac);
    load_data("he.txt", &list_he);
    load_data("nganh.txt", &list_nganh);
    load_data("khoa.txt", &list_khoa);
    printSV(&list_bac);
    printSV(&list_he);
    printSV(&list_nganh);
    printSV(&list_khoa);
    
    char my_mssv[10];
    printf("Nhap ma so sinh vien : ");
    scanf("%s", my_mssv);

    char* sub1 = subString(my_mssv,0,1);
    char* sub2 = subString(my_mssv,1,1);
    char* sub3 = subString(my_mssv,2,2);
    char* sub4 = subString(my_mssv,4,2);
       
	Node* p  = FindEleByMa(list_bac, sub1);
	printf("%5s %20s \n", p->info.ma, p->info.ten);	
	
	p  = FindEleByMa(list_he, sub2);
	printf("%5s %20s \n", p->info.ma, p->info.ten);	
	
	p  = FindEleByMa(list_nganh, sub3);
	printf("%5s %20s \n", p->info.ma, p->info.ten);	
	
	p  = FindEleByMa(list_khoa, sub4);
	printf("%5s %20s \n", p->info.ma, p->info.ten);	
	
	return 0;
}

