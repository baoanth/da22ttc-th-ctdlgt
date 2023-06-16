#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char code[3];
    char name[50];
    struct Node* next;
};

struct LinkedList 
{
    struct Node* head;
};

void addNode(struct LinkedList* list, char code[], char name[]) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->code, code);
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) 
	{
        list->head = newNode;
    }
    else 
	{
        struct Node* current = list->head;
        while (current->next != NULL) 
		{
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct LinkedList* list) 
{
    struct Node* current = list->head;
    while (current != NULL) 
	{
        printf("%s, %s\n", current->code, current->name);
        current = current->next;
    }
}

char* getNameByCode(struct LinkedList* list, char code[]) 
{
    struct Node* current = list->head;
    while (current != NULL) 
	{
        if (strcmp(current->code, code) == 0) 
		{
            return current->name;
        }
        current = current->next;
    }
    return "Unknown";
}

void load_data(struct LinkedList* nganhList, struct LinkedList* bacList, struct LinkedList* heList, struct LinkedList* khoaList) 
{
    
    FILE* nganhFile = fopen("nganh.txt", "r");
    if (nganhFile != NULL) 
	{
        char line[100];
        while (fgets(line, sizeof(line), nganhFile)) 
		{
            char code[3], name[50];
            sscanf(line, "%[^,], %[^\n]", code, name);
            addNode(nganhList, code, name);
        }
        fclose(nganhFile);
    }

 
    FILE* bacFile = fopen("bac.txt", "r");
    if (bacFile != NULL) 
	{
        char line[100];
        while (fgets(line, sizeof(line), bacFile)) 
		{
            char code[3], name[50];
            sscanf(line, "%[^,], %[^\n]", code, name);
            addNode(bacList, code, name);
        }
        fclose(bacFile);
    }

   
   
    FILE* heFile = fopen("he.txt", "r");
    if (heFile != NULL) 
	
	{
        char line[100];
        while (fgets(line, sizeof(line), heFile)) 
		{
            char code[3], name[50];
            sscanf(line, "%[^,], %[^\n]", code, name);
            addNode(heList, code, name);
        }
        fclose(heFile);
    }

  
  
    FILE* khoaFile = fopen("khoa.txt", "r");
    if (khoaFile != NULL)
	 {
        char line[100];
        while (fgets(line, sizeof(line), khoaFile)) 
		{
            char code[3], name[50];
            sscanf(line, "%[^,], %[^\n]", code, name);
            addNode(khoaList, code, name);
        }
        fclose(khoaFile);
    }
}

void get_student_info(char studentCode[], struct LinkedList* nganhList, struct LinkedList* bacList, struct LinkedList* heList, struct LinkedList* khoaList) 
{
    char bacCode[3];
    strncpy(bacCode, studentCode, 1);
    bacCode[1] = '\0';

    char heCode[3];
    strncpy(heCode, studentCode + 1, 1);
    heCode[1] = '\0';

    char nganhCode[3];
    strncpy(nganhCode, studentCode + 2, 2);
    nganhCode[2] = '\0';

    char khoaCode[3];
    strncpy(khoaCode, studentCode + 4, 2);
    khoaCode[2] = '\0';

    char id[4];
    strncpy(id, studentCode + 6, 3);
    id[3] = '\0';

    char* bacName = getNameByCode(bacList, bacCode);
    char* heName = getNameByCode(heList, heCode);
    char* nganhName = getNameByCode(nganhList, nganhCode);
    char* khoaName = getNameByCode(khoaList, khoaCode);

    printf("%s %s %s Khoa %s\n", bacName, heName, nganhName, khoaName, id);
}

int main() 
{
    struct LinkedList nganhList, bacList, heList, khoaList;
    nganhList.head = NULL;
    bacList.head = NULL;
    heList.head = NULL;
    khoaList.head = NULL;

    load_data(&nganhList, &bacList, &heList, &khoaList);

    char studentCode[10];
    printf("Nhap MSSV: ");
    scanf("%s", studentCode);

    get_student_info(studentCode, &nganhList, &bacList, &heList, &khoaList);

    return 0;
}





