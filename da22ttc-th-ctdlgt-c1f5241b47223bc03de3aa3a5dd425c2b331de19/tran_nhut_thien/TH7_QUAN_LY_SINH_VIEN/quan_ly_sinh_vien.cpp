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
		{
			printf("\n----CHUONG TRINH QUAN LY SINH VIEN----\N");
			printf("1.Them sinh vien moi\n");
			printf("2.xoa thong tin sinh vien\n");
			printf("3.Sua thong tin sinh vien\n");
			printf("4.Hien thi danh sach sinh vien\n");
			printf("5.Luu danh sach sinh vien vao File\n");
			printf("6.Xap xep danh sach sinh vien\n");
			printf("0.Thoat chuong trinh\n");
			printf("Nhap lua chon cua ban:");
			scanf("%d" ,&choice) ;
			
			switch (choice)
			{
				case 0:
				printf("Cam on ban da su dung chuong trinh!\n");
				brea;
				c 
			 } 
			 
		}
    }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
