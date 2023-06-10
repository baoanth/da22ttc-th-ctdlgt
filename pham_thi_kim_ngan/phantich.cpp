#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mssv_ele
{
    char ma;
    char* ten;
}mssv_ele;
typedef struct Node
{
    mssv_ele;
    Node->pNext;
}Node;
typedef struct List
{
    Node* pHead;
    Node* pTail;
}list;
Node *GetNode (DonThuc x)
{
    Node *p;
    p= new Node;
    if (p==NULL)
    {
        printf("Khong du bo nho de cap nhat nut moi");
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}
void AddTail( &l, Node *new_ele)
{
    if(l.pHead == NULL)
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
Node* FindNodeByID(List &l,char ma)
{
	Node *p;
	p=l.pHead;
	while ((p!=NULL)&&(p->Infno !=idx))
	p=p->pNext;
	return p;
 
void Init( list &1)
{
    l.pHead=l.pTail=NULL;
}
void LoadData(char* filename,List &1)
{
    char*  file;
    char* token;
    char line[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
    MssvEle else_tam;
    Node node_tam;
    file=fopen(filename,"r")
    if(file==NULL)
    {
    printf("ERRo! \n");
    return 1;

    }
while(fgets,(line,sizeof(line),file));
 {
    line[strcspn(line)]="\0";


token=strtok(line,",");
if(token !=NULL)
{
    strcpy(ele_tam.ma,token);
    token=strtok(NULL,",");
    if(token !=NULL)
    {
        strcpy(ele_tam.ten, token);

    }
}
node_tam=GetNode(ele_tam);
AddTail(l,node_tam);
}
  fclose(file);
}  

void printlist(List &1)
{
    if (i.pHead==NULL)
    printf("danh sach rong\n");
    else
    {
        Node *p;
        p=l.pHead;
        while(p!=NULL)
        {
            printf("%4s%5s\n",p->Infno.mssv,p->Infno.ten);
            p->pNext;
            
        }
    }
}
int main()
{
    list(list_bac);
    list(list_he);
    list(list_nganh);
    list(list_khoa);
    int(list_bac);
    int(list_nganh);
    int(int(list_he);
    int(list_khoa);
    

}