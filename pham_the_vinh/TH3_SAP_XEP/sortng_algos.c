#include <stdio.h>
#define N 10

void print_array(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void HoanVi(int *a, int *b)
{
	int tam;
	tam = *a;
	*a = *b;
	*b = tam;	
}

void SelectionSort(int a[], int n)
{
	int min, i, j;
	
	for(i=0; i<n-1; i++)
	{
		min=i;
		
		for(j=i+1; j<n; j++)
			if(a[j] < a[min])
				min=j;
				HoanVi(&a[min], &a[i]);	
			print_array(a, n);
	}
	
}

void InsertionSort(int a[], int n)
{
	int pos, i, x;
	
	for(i=0; i<n; i++)
	{
		x=a[i];
		pos=i-1;
		
		while((pos>=0)&&(a[pos]>x))
		{
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
		print_array(a, n);
	}
}

void InterchangeSort(int a[], int n)
{
	int i, j;
	
	for(i=0; i<=n; i++)
	{
		for(j=i+1; j<=n-1; j++)
			if(a[j]<a[i])
				HoanVi(&a[i], &a[j]);
			print_array(a, n);
	}	
}

void BubleSort(int a[], int n)
{
	int i, j;
	
	for(i=0; i<=n; i++)
	{
		for(j=n-1; j>i; j--)
			if(a[j]<a[j-1])
				HoanVi(&a[j], &a[j-1]);
			print_array(a, n);
	}
}

int main()
{
	int x;
	int my_array[]={3, 2, 4, 1, 6, 9 , 8, 7, 5, 10};
	
	printf("Mang ban dau:\n");
	print_array(my_array, N);
	
	printf("\nCac thuat toan sap xep:\n");
	printf("1. Selection Sort\n");
	printf("2. Insertion Sort\n");
	printf("3. Interchange Sort\n");
	printf("4. Buble Sort\n");

	while(1)
	{
		int my_array[]={3, 2, 4, 1, 6, 9 , 8, 7, 5, 10};
		printf("\nNhap so thu tu cua thuat toan sap xep can dung: ");
		scanf("%d", &x);
		
		if(x==0)
		{
			break;
		}
		
		if(x==1)
		{
			printf("1. Selection Sort:\n");
			SelectionSort(my_array, N);
		}
	
		if(x==2)
		{
			printf("2. Insertion Sort:\n");
			InsertionSort(my_array, N);
		}
	
		if(x==3)
		{
			printf("3. Interchange Sort:\n");
			InterchangeSort(my_array, N);
		}
	
		if(x==4)
		{
			printf("4. Buble Sort:\n");
			BubleSort(my_array, N);
		}

	}

	return 0;
}
