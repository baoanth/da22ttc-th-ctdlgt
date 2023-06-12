#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

typedef struct mssv_ele
{
    char ma[3];
    char ten[MAX_LINE_LENGTH];

} mssv_ele;

typedef struct Node
{
    mssv_ele Info;
    Node* next;
} Node;

typedef struct List
{
	Node* pHead;
    Node* pTail;
} List;

Node *FindEleByMa(List l, char* ma)
{
    Node *p;
    p = l.pHead;

    while ((p != NULL) && (strcmp(p->Info.ma, ma)))
        p = p->next;

    return p;
}


void Init ( List &l )
{
    l.pHead = l.pTail = NULL;
    
}

Node* GetNode ( mssv_ele x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
    {
        printf ("khong du bo nho");
        return NULL;
    }
    p -> Info = x ;
    p -> next = NULL;
    return p;
}

void AddFirst ( List &l, Node *new_ele )
{
    if ( l. pHead == NULL )
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else 
    {
        new_ele -> next = l.pHead;
        l.pHead = new_ele;
    }
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
        l.pTail->next = new_ele;
        l.pTail = new_ele;
    }
}

int LoadData (char* filename, List &l)
{
	 FILE* file = fopen(filename, "r");
    if (file == NULL) 
	{
        printf("Khong the mo file.\n");
        exit(1);
    }

    char line[100];
    char* token;
    char ma[50];
    char ten[50];
    mssv_ele ele_tam;
    Node* node_tam;
    while (fgets(line, sizeof(line), file))
	 {
	 	line[strcspn(line, "\n")] = '\0';
	 	
        token = strtok(line, ",");
        if (token != NULL)
        {
        	strcpy(ele_tam.ma, token);
        	token = strtok(NULL, ",");
        	if(token != NULL)
        	{
        		strcpy(ele_tam.ten, token);
			}
        
        }
        node_tam = GetNode(ele_tam);
        AddTail(l, node_tam);
    }
 
    fclose(file);
    //return 0;
}



void PrintListTT ( List &l )
{
   if ( l.pHead == NULL )
   
   		printf ("\n Danh sach rong.");
   	else
   	{	Node *p ;
		p = l.pHead;
		while(p!=NULL)
		{
   			printf (" %10s %10s \n", p -> Info.ma, p -> Info.ten );
   			p = p -> next;
   		}
   }
}


   
char* subString(char scr_str[], int start_pos, int len) 
{
    char* res_str = (char*) malloc((len + 1) * sizeof(char));  // C?p ph?t ??ng b? nh? cho chu?i k?t qu?
    int i;
    for (i = 0; i < len; i++)
	 {
        res_str[i] = scr_str[start_pos + i];
    }
    res_str[len] = '\0';
    //printf("\n%s\n", res_str);

    return res_str;
}

int main()
{
    List list_bac, list_khoa, list_he, list_nganh;
    
    Init(list_bac);
    Init(list_khoa);
    Init(list_he);
    Init(list_nganh);
    
	
	LoadData("bac.txt", list_bac); 
	LoadData("he.txt", list_he); 
	LoadData("nganh.txt", list_nganh); 
	LoadData("khoa.txt", list_khoa); 
	
	printf("\n Danh sach bac:\n");
    PrintListTT(list_bac);
    printf("\n Danh sach he:\n");
    PrintListTT(list_he);
    printf("\n Danh sach nganh:\n");
    PrintListTT(list_nganh);
    printf("\n Danh sach khoa:\n");
    PrintListTT(list_khoa);
    
	char my_mssv[10] ;/* = "110101112";*/
	printf ("\n nhap vao ma so sinh vien can tim: ");
	scanf ("%s", my_mssv);
	printf("==========Ket qua tim kiem cho %s ==========\n", my_mssv);    

    char* sub1 = subString(my_mssv,0,1);
    char* sub2 = subString(my_mssv,1,1);
    char* sub3 = subString(my_mssv,2,2);
    char* sub4 = subString(my_mssv,4,2);
       
	
	Node* p  = FindEleByMa(list_bac, sub1);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p  = FindEleByMa(list_he, sub2);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p  = FindEleByMa(list_nganh, sub3);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	p  = FindEleByMa(list_khoa, sub4);
	printf("%5s %20s \n", p->Info.ma, p->Info.ten);	
	
	
    
	return 0;


}


