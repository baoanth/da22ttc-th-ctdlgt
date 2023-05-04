#include<stdio.h>
#include<stdlib.h>
#define N 12

void print_array(int a[],int n)

{
	int i;
	for ( i=0; i<N-1; i++)
	{
		printf("%5d",a[i]);
		
	}
	printf("\n");
}
void hoan_vi(int*a,int*b )
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[], int n)
{
	int min;
	int i,j;
	for( i=0; i<n-1; i++)
	{
		
		min=i;
		
		for ( j=i+1; j<n; j++)
		    if(a[j]<a[min])
		       min = j;
		hoan_vi(&a[min],&a[i]);
		print_array(a, n);       
	}
}

void InsertionSort (int a[], int n)
{
	int pos, i;
	int x;
	for( i=1;i<n;i++)
	{
		x = a[i]; pos = i-1;
		while((pos >=0)&&(a[pos]>x))
		{
			a[pos+1] = a[pos];
			pos--;
		
		}
		a[pos+1] = x;
		print_array(a,n);
		
		
	}
}
void InterchangeSort(int a[], int n)
		{
			int i,j;
			for (i=1; i<N ; i++)
			     {
			     	for (j=i+1;j<=n;j++)
			              if(a[j]<a[i])
			              hoan_vi (a[i],a[j]);
			              print_array(a,n);
			     }    
		}
		
void BubleSort (int a[], int n)
{
	int i,j;
	for(i=0; i<n-1;i++)
	{     
		for (j =n-1; j>i; j--)
			if(a[j]<a[j-1])
	    		hoan_vi(&a[j],&a[j-1]);
	       print_array(a,n);		
	}
}


int main()
{
	int my_arr[] = {12,4,10,26,97,1,9,30,13,95,97,99};
	print_array(my_arr,N);
	printf("1. Selection sort\n");
	SelectionSort(my_arr,N);
	printf("2.Insertion sort\n");
	InsertionSort(my_arr,N);
	printf("3.InterchangeSort\n");
	InterchangeSort(my_arr,N);
	printf("4.BubleSort\n");
	BubleSort(my_arr,N);
	return 0;
}

