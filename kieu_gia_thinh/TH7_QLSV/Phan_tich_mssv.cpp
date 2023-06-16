#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_LINE_LENGTH 100
//Khai bao 3 cau truc du lieu
typedef struct Mssv_Ele
{
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
} Mssv_Ele;

typedef struct Node
{
    Mssv_Ele Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

//Viet ham GetNode(Person x)
Node *GetNode(Mssv_Ele x)
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

//Viet ham void AddFirst(List &l, Node *new_ele)
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
        l.pHead = new_ele;
    }
}

//Viet ham void AddTail(List &l, Node *new_ele)
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

//Viet ham Init
void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}

//Viet ham Load_Data
int Load_Data(char* filename, List &l )
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
    Mssv_Ele ele_tam;
    Node* node_tam;

    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tap van ban\n");
        return 1;
    }

    
    while (fgets(line, sizeof(line), file)) 
	{
        line[strcspn(line, "\n")] = '\0';       

        token = strtok(line, ",");
        
        if (token != NULL) 
		{
            strcpy(ele_tam.ma, token);
            token = strtok(NULL, ",");
            if (token != NULL)
			{
                strcpy(ele_tam.ten, token);
            }            
        }
        node_tam  = GetNode(ele_tam);
        AddTail(l, node_tam);
    }

    fclose(file);    
}


//Viet ham Print_List(List &l)
void Print_List(List &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5s %20s\n", p->Info.ma, p->Info.ten);
			p = p->pNext;
		}		
	}      
}

//Viet ham tim kiem
Node *FindEleByMa(List l, char* ma)
{
    Node *p;
    p = l.pHead;

    while ((p != NULL) && (strcmp(p->Info.ma, ma)))
        p = p->pNext;

    return p;
}
//Ham Sub_String
char* Sub_String(char scr_str[], int start_pos, int len) 
{
    char* res_str = (char*) malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++) 
	{
        res_str[i] = scr_str[start_pos + i];
    }
    res_str[len] = '\0';

    return res_str;
}

int main()
{
    List list_bac, list_khoa, list_he, list_nganh;
    Init(list_bac);
    Init(list_khoa);
    Init(list_he);
    Init(list_nganh);
    
	
	Load_Data("bac.txt", list_bac); 
	Load_Data("he.txt", list_he); 
	Load_Data("nganh.txt", list_nganh); 
	Load_Data("khoa.txt", list_khoa); 
    Print_List(list_bac);
    Print_List(list_he);
    Print_List(list_nganh);
    Print_List(list_khoa);
    char my_mssv[10];
    
    do
    {
    	printf("Moi ban nhap vao ma so sinh vien (gom 9 chu so): ");
		scanf("%s", my_mssv);
		if (strlen(my_mssv) != 9)
   	 	{
      	 	printf("Ma so sinh vien khong hop le\n");
   		}
    } while(strlen(my_mssv) != 9);
    
   	printf("***Ket qua phan tich mssv %s la: ***\n", my_mssv);    

    char* sub1 = Sub_String(my_mssv, 0, 1);
    char* sub2 = Sub_String(my_mssv, 1, 1);
    char* sub3 = Sub_String(my_mssv, 2, 2);
    char* sub4 = Sub_String(my_mssv, 4, 2);
       
	
	Node* p  = FindEleByMa(list_bac, sub1);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p = FindEleByMa(list_he, sub2);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p = FindEleByMa(list_nganh, sub3);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p = FindEleByMa(list_khoa, sub4);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	

	return 0;
}

