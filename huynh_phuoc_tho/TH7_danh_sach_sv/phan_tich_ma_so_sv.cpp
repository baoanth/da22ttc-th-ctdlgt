#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SV
{
    char name[200];
    char code[3];
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

void in(Node *p)
{
    while (p != NULL)
    {
        printf("%s\n  %s\n", p->info.code, p->info.name);
        p = p->next;
    }
}

Node *loadData(const char *filename)
{
    FILE *infile = fopen(filename, "r");
    if (infile != NULL)
    {
        Node *head = NULL;
        char line[100];
        while (fgets(line, sizeof(line), infile))
        {
            line[strcspn(line, "\n")] = '\0';
            SV x;
            sscanf(line, "%[^,], %[^\n]", x.code, x.name);
            Node *tmp = createNode(x);
            addNode(&head, tmp);
        }
        fclose(infile);
        return head;
    }
    return NULL;
}

char *getName(Node *p, char code[])
{
    while (p != NULL)
    {
        if (strcmp(p->info.code, code) == 0)
            return p->info.name;

        p = p->next;
    }
    return code;
}

void findStudentInfo(Node *bacList, Node *heList, Node *nganhList, Node *khoaList, const char *studentID)
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
    Node *bac = NULL;
    Node *khoa = NULL;
    Node *nganh = NULL;
    Node *he = NULL;

    bac = loadData("bac.txt");
    khoa = loadData("khoa.txt");
    nganh = loadData("nganh.txt");
    he = loadData("he.txt");

    //	in(he);
    char ma[10];
    printf("Nhap ma sinh vien: ");
    scanf("%s", &ma);

    findStudentInfo(bac, he, nganh, khoa, ma);

    return 0;
}
