#include<stdio.h>
#include<stdlib.h>

#define N 10

void print_array(int a[], int n)
{
	int i;
	
	for(i = 0; i<n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void Hoanvi(int *a, int *b)
{
	int tam;
	tam = *a; 
	*a = *b;
	*b = tam;
}

void Selection_Sort(int a[], int n)
{
	int min, i, j;
	
	for(i = 0; i < n-1; i++)
	{
		min = i;
		
		for(j = i+1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		Hoanvi(&a[min], &a[i]);
		print_array(a, n);			
	}
}

void Insertion_Sort(int a[], int n)
{
	int pos, i;
	int  x;
	
	for(i = 1; i < n; i++)
	{
		x = a[i];
		pos = i-1;
		
		while((pos >= 0) && (a[pos] > x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
		print_array(a, n);	
	}
}

void Interchange_Sort(int a[], int n)
{
	int i, j;
	
	for(i = 0; i < n-1; i++)
	{
		for(j = i+1; j<n; j++)
			if(a[j] < a[i])
				Hoanvi(&a[i], &a[j]);
				print_array(a, n);
	}				
}

void Buble_Sort(int a[], int n)
{ 
	int i, j;
	
	for (i = 0 ; i<n-1 ; i++)
	{
		for (j =n-1; j >i ; j --)
		{
			if(a[j]< a[j-1])
			Hoanvi(&a[j], &a[j-1]);
			print_array(a, n);
		}
	}
}

int main()
{
	int my_array[] = {4, 6, 2, 7, 5, 9, 8, 10, 65, 22};
//	print_array(my_array, N);
//	printf("1. SelectionSort\n");
//	Selection_Sort(my_array, N);
//	
//	printf("2. InsertionSort\n");
//	Insertion_Sort(my_array, N);
//	
//	printf("3. InterchangeSort\n");
//	Interchange_Sort(my_array, N);
//	
//	printf("4.BubleSort\n");
//	Buble_Sort(my_array, N);
while(1)
{
	int my_array[] = {4, 6, 2, 7, 5, 9, 8, 10, 65, 22};
		
	int lc;
	printf("0. EXIT\n");
	printf("1. Sap xep chen truc tiep\n");
	printf("2. Sap xep chon truc tiep\n");
	printf("3. Sap xep doi cho truc tiep\n");
	printf("4. Sap xep noi bot\n");
	printf("--------------------------------\n");
	printf("Moi luc chon chuc nang\n");
	scanf("%d", &lc);
	
	if(lc == 0)
	{
		break;
	}
	else if (lc == 1)
	{
		Selection_Sort(my_array, N);
	}
	else if (lc == 2)
	{
		Insertion_Sort(my_array, N);
	}
	else if (lc == 3)
	{
		Interchange_Sort(my_array, N);
	}
	else if (lc == 4)
	{
		Buble_Sort(my_array, N);
	}
}
	
	return  0;
}
