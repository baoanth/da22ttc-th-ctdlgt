#include <stdio.h>
#include <stdlib.h>
#define N 10
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

int main ()
{

int my_array[] = {1, 3, 7, 9, 5, 8, 4, 13, 10, 18};

 /*printf ("mang nguyen thuy:\n");
 print_array ( my_array, N);
 
 printf ("Demo Thuat toan sap xep:\n");
 
 printf ("1. InsertionSort \n");
 InsertionSort ( my_array, N);
 
 printf ("2. SelectionSort \n");
 SelectionSort ( my_array, N);
 
 printf ("3. InterchangeSort \n");
 InterchangeSort ( my_array, N);
 
 printf ("4. BubbleSort \n");
 BubbleSort ( my_array, N);*/
 
 while (1)
 {
 	int my_array[] = {1, 3, 7, 9, 5, 8, 4, 13, 10, 18};
 	int key;
 	
 	printf("Cac chuc nang chinh cua chuong trinh:\n");
 	printf("0.EXIT\n");
 	printf("1.InsertionSort\n");
 	printf("2.SelectionSort\n");
 	printf("3.InterchangeSort\n");
 	printf("4.BubbleSort");
 	scanf ("%d", &key);
 	
 
  return 0;   
}
