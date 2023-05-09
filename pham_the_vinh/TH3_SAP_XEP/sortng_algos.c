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

void Shift(int a[], int l, int r)
{
	int x, i, j;
	i=l;
	j=2*i;
	x=a[i];
	
	while(j<=r)
	{
		if(j<r)
			if(a[j]<a[j+1])
				j=j+1;
			if(a[j]<x)
				break;
			else
			{
				a[i]=a[j];
				i=j;
				j=2*i;
				a[i]=x;
			}	
	}
	
}

void CreateHeap(int a[], int n)
{
	int l;
	l=n/2;
	
	while(l>0)
	{
		Shift(a, l, n);
		l=l-1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a, n);
	r=n;
	
	while(r>0)
	{
		HoanVi(&a[1], &a[r]);
		print_array(a, n);
		r=r-1;
		Shift(a, 1, r);	
	}
}

void QuickSort(int a[], int l, int r)
{
	int i, j , x;
	
	x=a[(l+r)/2];
	i=l;
	j=r;
	
	do
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			HoanVi(&a[i], &a[j]);
			i++;
			j--;
		}
		
	} while(i<j);
	
	if(l<j)
		QuickSort(a, l, j);
	if(i<r)
		QuickSort(a, i, r);
		
	print_array(a, N);
}

int main()
{
	int x;
	int my_array[]={31, 21, 41, 11, 61, 91 , 81, 71, 51, 1};
	
	printf("Mang ban dau:\n");
	print_array(my_array, N);
	
	printf("\nCac thuat toan sap xep:\n");
	printf("1. Selection Sort\n");
	printf("2. Insertion Sort\n");
	printf("3. Interchange Sort\n");
	printf("4. Buble Sort\n");
	printf("5. Heap Sort\n");
	printf("6. Quick Sort\n");
	
	while(1)
	{
		int my_array[]={31, 21, 41, 11, 61, 91 , 81, 71, 51, 1};
		printf("\nNhap so thu tu cua thuat toan sap xep can dung(Nhap 0 de dung): ");
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
		
		if(x==5)
		{
			printf("5. Heap Sort:\n");
			HeapSort(my_array, N);
		}
		
		if(x==6)
		{
			printf("6. Quick Sort:\n");
			QuickSort(my_array, 0, N);
		}
	}
		
	return 0;
}
