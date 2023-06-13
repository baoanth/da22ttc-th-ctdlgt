#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct MssvEle{
    char ma[3] ;
    char ten[MAX_LINE_LENGTH];
    
}MssvEle;

typedef struct Node
{
    MssvEle Info;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
} List;

Node *GetNode(MssvEle x)
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
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

Node *FindEleByMa(List l, char* ma)
{
    Node *p;
    p = l.pHead;

    while ((p != NULL) && (strcmp(p->Info.ma, ma)))
        p = p->pNext;

    return p;
}

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}


int LoadData(char* filename, List &l )
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
    MssvEle ele_tam;
    Node* node_tam;

    // Mở tệp văn bản để đọc
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không thể mở tệp văn bản.\n");
        return 1;
    }

    // Đọc từng dòng trong tệp văn bản
    while (fgets(line, sizeof(line), file)) {
        // Loại bỏ ký tự newline
        line[strcspn(line, "\n")] = '\0';       

        // Phân tách dòng thành hai chuỗi bằng dấu phẩy
        token = strtok(line, ",");
        
        if (token != NULL) {
            strcpy(ele_tam.ma, token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(ele_tam.ten, token);

                // In ra các biến "ma" và "ten"
                //printf("Ma: %s\n", ele_tam.ma);
                //printf("Ten: %s\n", ele_tam.ten);
            }            
        }
        node_tam  = GetNode(ele_tam);
        AddTail(l, node_tam);
    }

    // Đóng tệp văn bản
    fclose(file);    
}

void PrintList(List &l)
{

	if (l.pHead ==NULL)
		printf("Danh sach rong\n");
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5s %20s \n", p->Info.ma, p->Info.ten);
			p = p->pNext;
		}
    }
}		

char* subString(char scr_str[], int start_pos, int len) 
{
    char* res_str = (char*) malloc((len + 1) * sizeof(char));  // C?p ph�t �?ng b? nh? cho chu?i k?t qu?
    int i;
    for (i = 0; i < len; i++) {
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
    PrintList(list_bac);
    PrintList(list_he);
    PrintList(list_nganh);
    PrintList(list_khoa);
    
	char my_mssv[10] = "110101112";
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
