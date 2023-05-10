#include <stdio.h>
#include <stdlib.h>
#define N 20
void hoan_vi ( int* a, int* b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
void print_array( int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf ("%5d", a[i]);
    }
    printf ("\n");
}


void InsertionSort ( int a[], int n)
{ 
	int pos, i;
	int x;

for ( i=1; i<n; i++)
{
	x = a[i]; pos = i-1;
	while (( pos >=0) && (a[pos] > x))
	{
		a[pos+1] = a[pos];
		pos--;
	}
		a[pos+1] = x;
		print_array(a, n);
	}
//	hoan_vi( &a[pos+1], &a[i]);
	
}


void SelectionSort ( int a[], int n)
{ 
	int min, i, j;

	for ( i=0; i<n-1; i++)
{
	 min = i;
	for ( j = i+1; j < n; j++)
	if ( a[j] < a[min])
	min = j;
	hoan_vi(&a[min], &a[i]);
	print_array( a, n);
	}
}


void InterchangeSort (int a[], int n)
{
	int i, j;
	for ( i=1; i<n; i++)
	{
		for ( j = i+1; j<=n; j++)
			if ( a[j] < a[i])
	hoan_vi( &a[i], &a[j] );
	print_array(a, n);
	}
		
}


void BubbleSort ( int a[], int n)
{
	int i, j;
	for ( i=1; i<=n; i++)
	{
		for  ( j=n-1; j>i; j--)
			if ( a[j] < a[j-1])
	hoan_vi( &a[j], &a[j-1]);
	print_array(a, n);
	}		
}


void Shift ( int a[], int l, int r )
{
	int x, i, j;
	i = l;
	j = 2*i;
	x = a[i];
	while ( j<=r )
	{
		if ( j<r )
			if ( a[j] < a[j+1])
				j = j+1;
			if ( a[j] < x)
				break;
			else
				{
					a[i] = a[j];
					i = j;
					j = 2*i;
					a[i = x];
				}
	}
}


void CreateHeap ( int a[], int n)
{
	int l;
	l = n/2;
	while ( l > 0)
	{
		Shift ( a, l, n);
		l = l-1;
	}
	
}


void HeapSort ( int a[], int n)
{
	int r;
	CreateHeap (a, n);
	r = n;
	while (r > 0)
	{
		hoan_vi (&a[1], &a[r]);
		r = r-1;
		Shift ( a, 1, r);
		print_array( a, n);
	}
}


void QuickSort ( int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l+r)/2];
	i = l;  j= r;
	do
	{
		while (a[i] < x)  i++;
		while (a[j] > x)  j++;
		if ( i <= j)
		{
			hoan_vi (&a[i], &a[j]);
			i++;  j--;
		}
	
	}
	
	while ( i < j);
	if ( l < j )
		QuickSort (a, l, j);
	if ( i < r )
		QuickSort (a, l, r);
	
	print_array( a, r);
}


int main ()
{

int my_array[] = {1, 3, 7, 9, 5, 8, 4, 13, 10, 18};

 printf ("mang nguyen thuy:\n");
 print_array ( my_array, N);
 
/* printf ("Demo Thuat toan sap xep:\n");
 
 printf ("1. InsertionSort \n");
 InsertionSort ( my_array, N);
 
 printf ("2. SelectionSort \n");
 SelectionSort ( my_array, N);
 
 printf ("3. InterchangeSort \n");
 InterchangeSort ( my_array, N);
 
 printf ("4. BubbleSort \n");
 BubbleSort ( my_array, N);
 
 printf ("5. HeapSort \n");
 HeapSort ( my_array, N);
 
 printf ("6. QuickSort \n);
 QuickSort (my_array, N); */
 
 	
       
        
        printf ("Menu thuat toan\n");
        printf("1. SelectionSort\n");
        printf("2. InsertionSort\n");
        printf("3. InterchangeSort\n");
        printf("4. BubbleSort\n");
        printf("5. HeapSort\n");
        printf("6. QuickSort\n");
       
        
        int chon=1;
		while (1)
	{
		int my_array[] = {1, 3, 7, 9, 5, 8, 4, 13, 10, 18};
        int chon;
		printf("\nnhap lua chon cua ban. Nhap 0 de THOAT:");
        scanf("%d", &chon);
        if (!chon)
        break;
		
        switch (chon)
        {
            case 1:
            	printf ("\nSelectionSort Begin\n");
                SelectionSort(my_array, N);
                printf ("\nSelectionSort End\n");
                break;
            case 2:
            	printf ("\nInsertionSort Begin\n");
                InsertionSort(my_array, N);
                printf ("\nInsertionSort End\n");
                 break;
            case 3:
            	printf ("\nInterchangeSort Begin\n");
                InterchangeSort(my_array, N);
                printf ("\nInterchangeSort End\n");
                 break;
            case 4:
            	printf ("\nBubbleSort Begin\n");
                BubbleSort(my_array, N);
                printf ("\nBubbleSort End\n");
                 break;
            case 5:
            	printf ("\nHeapSort Begin\n");
            	HeapSort(my_array, N);
            	printf ("\nHeapSort End\n");
            	break;
            case 6:
            	printf ("\nQuickSort Begin\n");
            	QuickSort(my_array, 0, N-1);
            	printf ("\nQuickSort End\n");
            	break;

            default:
            	
            break;
        
        }

    }
  return 0;   
}
