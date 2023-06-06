#include<stdio.h>

typedef struct Node
{
    char *Info;
    Node* next;
}Node;

Node* creNode(char *x)
{
    Node* p = new Node;
    p->Info = x;
    p->next = NULL;
    return p;

}

void addNode(Node* head, Node* p )
{
     if (head == NULL)
        head = p;
    else
    {
        Node *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

Node* loadData(Node* p, char * filename)
{
    Node* tmp = NULL;
    FILE* infile = fopen(filename, "r");
    while(!feof(infile))
    {
        char x[100];
        getline(infile,x,',');
        tmp = creNode(x);
        addNode(p, tmp);
    }
    return p;
}

void in(Node* head)
{
    while(head != NULL)
    {
        printf("%s", head->Info);
    }
}
int main()
{
    Node* head = NULL;
    head = loadData(head, "bac.txt");
    in(head);
    return 0;

}
