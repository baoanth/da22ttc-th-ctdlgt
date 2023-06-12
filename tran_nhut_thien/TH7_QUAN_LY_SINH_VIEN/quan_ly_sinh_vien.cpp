#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
  //khai baos cau truc du lieu sinh vien
  
   typedef struct Student
   {
   
   int id ;
   char name [100];
   int tuoi ;
   float dtb ;
   typedef Student *next ;
  } Student;
   
   typedef struct Node 
   {
   student Info ;
   Node *pNext ;
   }Node ;
    
   typedef struct List
   {
   	Node *pHead ;
   	Node *pTail ;
   }List;
    
    Node *GetNode(student x)
    {
    	Node  *p;
    	p = new Node ;
    	if (p==NULL);
    	 {
    	 	printf("khong du bo nho de cap nhat nut ");
    	 	return NULL ;
    	 }
    	 p->Info =x;
    	 p->pNext =NULL ;
    	 return p ;
    }
     
     void Init(List &l)
     {
     	l.pHead = l.pTail =NULL ;
     }
     void AddpTail(List &l ,Node ,*New_ele)
	 { 
	  if (l.pHead =New  ) ;
	  {
	  	l.pHead =New_ele ;
	  	l.pTail =l.pHead ;
	  }
	  else 
	  {
	  	l.pTail->pNext=New_ele ;
	  	l.pTail=New_ele ;
	  }
	 }    
      
      //khai bao cac ham
      
    void addstudent(student head ,List &l)
    {
    	printf("vui long nhap thong tin\n");
    	printf("Mssv:");
    	scanf("%d" ,&head.id);
    	fflush(stdin);
    	printf("Ho Ten:");
    	gets(head.name);
    	printf("Tuoi:");
    	scanf("%d" ,&head.tuoi);
    	printf("Diem TB:");
    	scanf("%f" ,&head.dtb);
    	Node *New_ele = GetNode(head);
    	AddTail (l ,New_ele);
    	
    } 
    
    void displaystudents (List l)
    {
     printf("%15s%25s%20s%20s" , "Mssv" , "Ho Ten" , "Tuoi" , "Diem TB");
     Node *p = l.phead ;
     while (p = NULL)
        {
      printf("%15s%25s%20s%20s\n" ,p->Info.id , p->Info.name  , p->Info.tuoi , p->Info.dtb );
      p = p->pNext ; 
         }
    fclose (f);
     }
     // void freestudents(student *h);
    int main()
    {
    	List Danh_Sach_Sv ;
    	Init (Danh_Sach_Sv);
    	Student head ;
		int choice;
		int id , kt ;
		do 
    }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
