#include <stdio.h>
#include <string.h>

typedef struct TTSV
{
    
    char ma[2];
    char ten[100];
} TTSV;

typedef struct Node
{
    TTSV Info;
    Node *pNext;

} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(TTSV x)
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

        new_ele->pNext = l.pHead;

        l.pHead = new_ele;
    }
}

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
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
void PrintList(List l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        printf("Ma: %s \nTen: %s \n", p->Info.ma, p->Info.ten);
        p = p->pNext;
    }
}




void LoadData(char *filename, List &l)
{
    FILE *f = fopen(filename, "r");
    TTSV sv_tam;
    char chuoi_tam[100];
    char *tach_chuoi;
    
    if (f == NULL)
    {
        printf("Khong tim thay file");
        return;
    }

    while (fgets(chuoi_tam, sizeof(chuoi_tam), f))
    {
        chuoi_tam[strcspn(chuoi_tam, "\r\n")] = '\0'; 
        tach_chuoi = strtok(chuoi_tam, ",");
        strcpy(sv_tam.ma, tach_chuoi);
        tach_chuoi = strtok(NULL, ",");
        strcpy(sv_tam.ten, tach_chuoi);
        Node *new_node = GetNode(sv_tam);
        AddTail(l, new_node);
    }

    fclose(f);
}


char* Findname( char *id,List l)
{
    Node *p = l.pHead;
    while ((p != NULL))
    {
        if (strcmp(p->Info.ma,id)==0)
            return p->Info.ten;
        p = p->pNext;
    }
    return NULL;
    

}


int main()
{
    List list_bac, list_khoa, list_he, list_nganh;
    Init(list_bac);
    Init(list_khoa);
    Init(list_he);
    Init(list_nganh);

    LoadData("bac.txt", list_bac);
    LoadData("khoa.txt", list_khoa );
    LoadData("he.txt", list_he );
    LoadData("nganh.txt", list_nganh);

    PrintList(list_bac);
    printf("==========================================\n");
    PrintList(list_khoa);
    printf("==========================================\n");
    PrintList(list_he);
    printf("==========================================\n");
    PrintList(list_nganh);

	char id[10];

    printf("Nhap id : ");
    scanf("%s", &id);

    char bac_list[2], he_list[2], nganh_list[3], khoa_list[3], id[4];
    strncpy(bac, id, 1);
    bac[1] = '\0';
    strncpy(he, id + 1, 1);
    he[1] = '\0';
    strncpy(nganh, id + 2, 2);
    nganh[2] = '\0';
    strncpy(khoa, id + 4, 2);
    khoa[2] = '\0';
    strncpy(id_sv, id + 6, 3);
    id_sv[3] = '\0';
    
    FindByID( id);
    
    return 0;
}
