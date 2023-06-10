#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mssv_ele
{
    char* ma;
    char* ten;

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
        new_ele -> pNext = l.pHead;
        l.pHead = new_ele;
    }
}


void load_data (char* filename, List* l)
{
	 FILE* file = fopen(filename, "r");
    if (file == NULL) 
	{
        printf("Khong the mo file.\n");
        exit(1);
    }

    char line[100];
    char* token;
    char* ma;
    char* ten;
    while (fgets(line, sizeof(line), file))
	 {
        token = strtok(line, ",");
        strcpy(ma, token);
        token = strtok(NULL, ",");
        strcpy(ten, token);

        printf("Mã: %s\n",ma);
        printf("Tên: %s\n",ten);
        
        mssv_ele ele_tam;
        ele_tam.ma = ma;
        ele_tam.ten = ten;
        Node* mssv_ele = GetNode(&mssv_ele );
        if (l->pHead == NULL)
        {
            l->pHead = l->pTail = GetNode;
        }
        else
        {
            l->pTail->next = GetNode;
            l->pTail = GetNode;
        }
        
    }
 
    fclose(file);
    //return 0;
}



void PrintTT ( List* l )
{
   Node *p = l.pHead;
   while ( p==NULL )
   {
   		printf ("\n Danh sach rong.")
   	else
   		printf (" %s %s \n", p -> Info.ma, p -> Info.ten );
   		p = p -> next;
   }
}

int main()
{
    Node* myList = NULL;
    
    printf ("\n: \n");
    inputNode(myList);

}
