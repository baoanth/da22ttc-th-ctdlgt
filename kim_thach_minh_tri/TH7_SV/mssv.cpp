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
        printf("%s %s \n", p->Info.ma, p->Info.ten);
        p = p->pNext;
    }
}

//void LoadData (char *filename, List &l)
//{
//    
//    FILE *f = fopen(filename, "r");
//    TTSV sv_tam;
//    char chuoi_tam[100];
//    char *tach_chuoi;
//    if (filename == NULL)
//    {
//        printf("Khong tim thay file");
//        return;
//    }
//    else
//    {
//        while (!feof(f))
//        {
//            fgets(chuoi_tam, sizeof(chuoi_tam), f);
//            if (chuoi_tam != NULL)
//            {
//                tach_chuoi = strtok(chuoi_tam, ",");
//                strcpy(sv_tam.ma, tach_chuoi);
//                if (chuoi_tam != NULL)
//                {
//                    tach_chuoi = strtok(NULL, ",");
//                    strcpy(sv_tam.ten, tach_chuoi);
//                }
//            }
//            Node *new_node = GetNode(sv_tam);
//            AddTail(l, new_node);
//        }
//    }
//   
//}
//

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


void FindByID(List l_bac, List l_he, List l_nganh, List l_khoa, char *id)
{
   
    char bac[2], he[2], nganh[3], khoa[3], id_sv[4];
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

   
    Node *p_bac = l_bac.pHead;
    while (p_bac != NULL)
    {
        if (strcmp(p_bac->Info.ma, bac) == 0)
        {
            Node *p_he = p_bac->pNext;
            while (p_he != NULL)
            {
                if (strcmp(p_he->Info.ma, he) == 0)
                {
                    Node *p_nganh = p_he->pNext;
                    while (p_nganh != NULL)
                    {
                        if (strcmp(p_nganh->Info.ma, nganh) == 0)
                        {
                            Node *p_khoa = p_nganh->pNext;
                            while (p_khoa != NULL)
                            {
                                if (strcmp(p_khoa->Info.ma, khoa) == 0)
                                {
                                    Node *p_sv = p_khoa->pNext;
                                    while (p_sv != NULL)
                                    {
                                        if (strcmp(p_sv->Info.ma, id_sv) == 0)
                                        {
                                            printf("Ma so sinh vien: %s\n", id);
                                            printf("Ten sinh vien: %s\n", p_sv->Info.ten);
                                            return;
                                        }
                                        p_sv = p_sv->pNext;
                                    }
                                }
                                p_khoa = p_khoa->pNext;
                            }
                        }
                        p_nganh = p_nganh->pNext;
                    }
                }
                p_he = p_he->pNext;
            }
        }
        p_bac = p_bac->pNext;
    }
    printf("Khong tim thay sinh vien co ma so %s\n", id);
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
    
    FindByID(list_bac, list_he, list_nganh, list_khoa, id);
    
    return 0;
}
