# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Mssv_ele
{
    int id;
    char ma [01];
    char ten;
} Mssv_ele;

typedef struct Node
{ 
	Mssv_ele Info;
	Node* pNext;
}Node;

typedef struct List
{
	Node* pHead;
	Node* pTail;
}List;

Node* GetNode(Mssv_ele x)
{
	Node *p;
	p = new Node;
	if (p==NULL)   
	{ 
		printf("Khong du bo nho !"); 
		return NULL; 
	}
	p->Info = x; 
	p->pNext = NULL;
	return p; 
}

void AddFirst(List &l, Node* new_ele)
{
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail  = l.pHead;
	}
	else 
	{	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}

void AddTail(List &l, Node *new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail= l.pHead;
	}
	else
	{
		l.pTail->pNext =new_ele;
		l.pTail=new_ele;
	}
} 

Node* FindNodeByID(List l, int idx)
{
	Node *p;
	p =l.pHead;
	while((p!=NULL) && ( p->Info.id !=idx ))
	p = p-> pNext;
	return p;
}
void Init(list &l)
{
    l.pHead = l.pTail = NULL;
}
void load_data(char filename, list &l)
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char ma[MAX_LINE_LENGTH];
    char ten[MAX_LINE_LENGTH];
    Mssv_ele ele_tam;
    Node node_tam;
}


file fopen(filename,"r");
if (file == NULL)
{
    printf("ko the mo tep vb. \n");
    return1;
}
while (fgets(line, sizeof(line), file))
{
    line[strcspn(line, "\n")] = '\0';
    token = strtok(line, ",");
    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok( NULL,",")
    }
}