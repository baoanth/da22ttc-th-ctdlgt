#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SV
{
    char name[10];
    char code[10];
} SV;

typedef struct Node
{
    SV info;
    struct Node *next;
} Node;

Node *createNode(SV x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    return p;
}

void addNode(Node **head, Node *p)
{
    if (*head == NULL)
        *head = p;
    else
    {
        Node *q = *head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

Node *loadData(const char *filename)
{
    FILE *infile = fopen(filename, "r");
    if (infile != NULL)
    {
        Node *head = NULL;
        char line[30];
        while (fgets(line, sizeof(line), infile))
        {
            char *token;
            SV x;

            token = strtok(line, ",");
            strcpy(x.code, token);
            token = strtok(NULL, ",");
            strcpy(x.name, token);

            Node *tmp = createNode(x);
            addNode(&head, tmp);
        }
        fclose(infile);
        return head;
    }
    else 
        return NULL;
}

void findStudentInfo(Node *bacList, Node *heList, Node *nganhList, Node *khoaList, const char *studentID)
{
    if (strlen(studentID) != 9)
    {
        printf("Ma so sinh vien khong hop le\n");
        return;
    }

    char bacCode[3];
    strncpy(bacCode, studentID, 1);
    bacCode[1] = '\0';

    char heCode[3];
    strncpy(heCode, studentID + 1, 1);
    heCode[1] = '\0';

    char nganhCode[4];
    strncpy(nganhCode, studentID + 2, 2);
    nganhCode[2] = '\0';

    char khoaCode[4];
    strncpy(khoaCode, studentID + 4, 2);
    khoaCode[2] = '\0';

    Node *bacNode = bacList;
    while (bacNode != NULL)
    {
        if (strcmp(bacNode->info.code, bacCode) == 0)
        {
            break;
        }
        bacNode = bacNode->next;
    }

    Node *heNode = heList;
    while (heNode != NULL)
    {
        if (strcmp(heNode->info.code, heCode) == 0)
        {
            break;
        }
        heNode = heNode->next;
    }

    Node *nganhNode = nganhList;
    while (nganhNode != NULL)
    {
        if (strcmp(nganhNode->info.code, nganhCode) == 0)
        {
            break;
        }
        nganhNode = nganhNode->next;
    }

    Node *khoaNode = khoaList;
    while (khoaNode != NULL)
    {
        if (strcmp(khoaNode->info.code, khoaCode) == 0)
        {
            break;
        }
        khoaNode = khoaNode->next;
    }

    if (bacNode == NULL || heNode == NULL || nganhNode == NULL || khoaNode == NULL)
    {
        printf("Khong tim thay thong tin sinh vien\n");
        return;
    }

    printf("%s %s %s Khoa %s\n", heNode->info.name, bacNode->info.name, nganhNode->info.name, khoaNode->info.name);
}

int main()
{
    Node *bac = NULL;
    Node *khoa = NULL;
    Node *nganh = NULL;
    Node *he = NULL;

    bac = loadData("bac.txt");
    khoa = loadData("khoa.txt");
    nganh = loadData("nganh.txt");
    he = loadData("he.txt");

    char ma[10];
    printf("Nhap ma sinh vien: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = '\0';

    findStudentInfo(bac, he, nganh, khoa, ma);

    return 0;
}
