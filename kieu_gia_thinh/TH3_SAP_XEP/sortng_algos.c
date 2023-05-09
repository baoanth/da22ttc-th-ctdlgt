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
	
	for (i = 1 ; i<n-1 ; i++)
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
	print_array(my_array, N);
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
		int lc;
		printf("Nhap vao chuc nang ma ban muon\n");
		scanf("%d", &lc);
		
		if(lc==0)
		{
			printf("1. EXIT\n");
		} 
		else if(lc==1)
		{
			printf("1. SelectionSort\n");
			Selection_Sort(my_array, N);
		}
	}






	
	return  0;
}
