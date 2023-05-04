#include<stdio.h>
#include<stdlib.h>

#define N 10

void print_array(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}

void HoanVi(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// chon truc tiep
void SelectionSort (int a[100], int n)
{
	int min;
	int i,j;
	for (i=0 ; i <n-1 ;i++)
	{
	    min = i;
	for (j=i+1 ; j<n ;j++)
	if (a[j] < a[min])
		min = j;
		HoanVi (&a[min],&a[i]);	  
		print_array(a,n);
    }
}

// chen truc tiep
void InsertionSort(int a[],int n)
{
	int pos ,i;
	int x;
	for (i=1; i<n; i++)
	{
		x=a[i]; pos = i-1;
    
	while((pos>=0)&&(a[pos]>x))	
    {
	    a[pos+1]=a[pos];
	    pos--;
    }
	    a[pos+1]=x;
	    print_array(a,n);
}
}

//doi cho truc tiep
void InterchangeSort(int a[], int n)
{
	int i, j;
	for (i=1; i<n; i++)
	{
	for (j=i+1; j<n; j++)
	if (a[j]<a[i])
	    HoanVi(&a[i],&a[j]);
		print_array(a,n);
    }
}

//noi bot
void BubleSort(int a[], int n)
{
	int i,j;
	for (i=1; i<n-1; i++)
	{
	for (j=n-1; j>i; j--)
	    if (a[j]<a[j-1])
	    HoanVi (&a[j],&a[j-1]);
	    print_array(a,n);
    }
}

// ham main
int main()
{
	int my_array[]= {5,8,3,1,4,6,9,2,7,10};
	print_array(my_array,N);
	/*printf("1.SelectionSort\n");
	SelectionSort(my_array,N);
	printf("2.InsertionSort\n");
	InsertionSort(my_array,N);
	printf("3.InterchangeSort\n");
	InterchangeSort(my_array,N);
	printf("4.BubleSort\n");
	BubleSort(my_array,N);*/
	
	while(1)
	{
		int my_array[]={5,8,3,1,4,6,9,2,7,10};
		int select;
		
		printf("0.EXIT\n");
		printf("1.SelectionSort\n");
		printf("2.InsertionSort\n");
		printf("3.InterchangeSort\n");
		printf("4.BubleSort\n");
		printf("__________Chon chuc nang di bo teo:__________\n");
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
			BubleSort(my_array,N);
		}
	}
	
return 0;	
}

