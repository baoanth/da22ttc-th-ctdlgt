#include <stdio.h>
#include <stdlib.h>

#define N 10

void InsertionSort(int a[], int n)
{
    int pos, i;
    int x;
    for(i=1; i<n; i++)
    {
        x= a[i]; pos = i-1;
        
    while((pos >=0)&&(a[pos]>x))
    {
    	a[pos+1]= a[pos];
    	pos--;
    }
	    a[pos+1]=x;
	    print_array(a,n);
	}
}

void SelectionSort(int a[100], int n)
{
    int min,i,j;
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		 if(a[j] < a[min])
		  min = j;	  
		Hoanvi(&a[min], &a[i]);
		print_array(a, n);
	}
}

void InterchangeSort(int a[], int n)
{
	int i,j;
	for(i=0; i<n; i++)
	{
	   for(j =i+1; j<n; j++)
	     if(a[j]<a[i])
	       Hoanvi(&a[i],&a[j]);
	       print_array(a,n);
	}     
}

void BubbleSort(int a[], int n)
{
	int i,j;
	for(i=0; i<n-1; i++)
    {
	  for(j=n-1; j>i; j--)
	     if(a[j]<a[j-1])
	       Hoanvi(&a[j],&a[j-1]);
	       print_array(a,n);
    }
}

void Hoanvi(int* a, int* b)	
{
    int temp;
	temp= *a;
	*a = *b;
	*b = temp;  
}       

void print_array(int a[],int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%5d",a[i]);
    }
    printf("\n");
}

int main()
{
    int my_array[]= {1,2,12,6,4,8,9,7,3,5};
    
    printf("Mang cac day so:\n");
    print_array(my_array,N);
    
    while(1)
	{
		int my_array[]={5,8,3,1,4,6,9,2,7,10};
		int select;    
	    printf("0.EXIT\n");
		printf("1.SelectionSort\n");
		printf("2.InsertionSort\n");
		printf("3.InterchangeSort\n");
		printf("4.BubleSort\n");
		printf("_Chon chuc nang: \n");
		scanf("%d",&select);
		
		if(select==0)
		{
			break;
		}
		else if (select==1)
		{
			SelectionSort(my_array,N);
		}
		else if (select==2)
		{
			InsertionSort(my_array,N);
		}
		else if (select==3)
		{
			InterchangeSort(my_array,N);
		}
		else if (select==4)
		{
			BubbleSort(my_array,N);
		}
	}
   return 0;
}
	  
