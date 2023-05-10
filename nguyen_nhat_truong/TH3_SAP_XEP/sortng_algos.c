#include<stdio.h>
#include<stdlib.h>

#define N 10

void print_array(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void hoanvi(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort (int a[], int n)
{
	int min;
	int i,j;
	for (i=0; i<n-1; i++)
	{
		min = i;
		for( j=i+1; j<n; j++)
		   if(a[j]< a[min])
		     min = j;
		
		hoanvi(&a[min], &a[i]);
		print_array(a, n);
	}
	
}

void InsertionSort(int a[], int n)
{
	int pos, i, x;
	for (i=1; i<n; i++)
	{
		x=a[i];
		pos=i-1;
		while((pos>=0) && (a[pos]>x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
		print_array(a, n);
	}
}

void InterchangeSort(int a[], int n)
{
	int i,j;
	for(i=1; i<n; i++)
	{
	    for(j=i+1; j<n; j++)
	    if(a[j]<a[i])
		hoanvi(&a[i],&a[j]);
		print_array(a,n);
	}
        
}

void BubleSort(int a[], int n)
{
	int i, j;
	for(i=1; i<n-1; i++)
	{
	    for(j = n-1; j>i; j--)
		if(a[j]<a[j-1])
		hoanvi(&a[j],&a[j-1]);
		print_array(a,n);
	}
	
}

void Shift (int a[ ], int l, int r )
{ 
    int x, i, j;
    i = l;
    j =2*i+1; 
    x = a[i];
    while (j<=r)
    {
        if (j<r) 
        if (a[j]<a[j+1])
        j = j+1;
        if (a[j]<x)
           break; 
        else
        { 
            a[i] = a[j];
            i = j;
            j = 2*i+1;
            a[i] = x;
        }
    }
}

void CreateHeap(int a[], int n)
{
	int l;
	l= n/2;
	while(l>=0)
	{
		Shift(a,l,n);
        l = l-1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a,n-1);
	printf("\n-----Heap-----\n");
	print_array(a,n);
	printf("--------------\n");
	
	r = n-1;
	
	while(r>0)
	{
		hoanvi(&a[0],&a[r]);
		print_array(a,n);
		r = r-1;
		Shift(a,0,r);
		
	}
}

int main()
{
	int my_arr[] = {12,4,26,10,97,1,9,30,13,95};
	print_array(my_arr,N);
	while(1)
	{
		int my_arr[] = {12,4,26,10,97,1,9,30,13,95};
		int lc;
		printf("0. EXIT\n");
		printf("1. Selection sort\n");
		printf("2.Insertion sort\n");
		printf("3.Interchange sort\n");
		printf("4.Buble sort\n");
		printf("5.Heap sort\n");
		printf("...\n");
		printf("chon chuc nang\n");
		scanf("%d", &lc);
		if(lc == 0)
		{
			break;
		}
		else if(lc == 1)
		{
			SelectionSort(my_arr, N);
		}
		else if(lc == 2)
		{
			InsertionSort(my_arr, N);
		}
		else if(lc == 3)
		{
		    InterchangeSort(my_arr, N);	
		}
		else if(lc == 4)
		{
			BubleSort(my_arr, N);
		}
		else if(lc == 5)
		{
			HeapSort(my_arr, N);
		}
	}
	/*printf("1. Selection sort\n");
	SelectionSort(my_arr, N);
	printf("2.Insertion sort\n");
	InsertionSort(my_arr, N);
	printf("3.Interchange sort\n");
	InterchangeSort(my_arr, N);
	printf("4.Buble sort\n");
	BubleSort(my_arr, N);*/
	
	
	return 0;
}


