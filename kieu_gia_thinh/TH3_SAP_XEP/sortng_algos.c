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

void print_array1(int a[], int n)
{
	int i;
	
	for(i = 1; i<=n; i++)
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
//Heap Sort
void Shift (int a[], int l, int r)
{
	int x, i, j;
	i=l;
	j=2*i;
	x=a[i];
	
	while(j<=r)
	{
		if(j<r)
			if(a[j]<a[j+1])
				j = j+1;
			if(a[j]<x)
				break;
			else
			{
				a[i] = a[j];
				i = j;
				j = 2 * i;
				a[i] = x;
				
			}		
	}
}

void CreateHeap(int a[], int n)
{
	int l;
	l = n/2;
	while(l>0)
	{
		Shift(a, l, n);
		l = l - 1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a, n);
	r = n;
	while(r>0)
	{
		Hoanvi(&a[1], &a[r]);
		r = r-1;
		Shift(a, 1, r);
		print_array1(a, n);
	}
}
//Quick Sort

void QuickSort(int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l+r)/2];
	i = l; j = r;
	do
	{
		while(a[i]<x) 
		i++;
		while(a[j]>x)
		j--;
		
		if(i<=j)
		{
			Hoanvi(&a[i], &a[j]);
			i++, j--;
			
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
	int tam[N],i;
	int my_array[] = {4, 6, 2, 7, 5, 9, 8, 10, 65, 22};
<<<<<<< HEAD
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
=======
	print_array(my_array, N);
	for( i = 0; i<N;i++)
	{
		tam[i+1] = my_array[i]; 	
	}
	
	while(1)
	{
		int my_array[] = {4, 6, 2, 7, 5, 9, 8, 10, 65, 22};
		int lc;
		
		printf("0. EXIT\n");
		printf("1. Selection Sort\n");
		printf("2. Insertion Sort\n");
		printf("3. Interchange Sort\n");
		printf("4. Buble Sort\n");
		printf("5. Heap Sort\n");
		printf("6. Quick Sort\n");
		printf("--------------------------\n");
		printf("Nhap vao lua chon\n");
		scanf("%d", &lc);
		
		if(lc==0)
		{
			break;
		}
		else if(lc==1)
		{
			Selection_Sort(my_array, N);
		}
		else if(lc==2)
		{
			Insertion_Sort(my_array, N);
		}
		else if(lc==3)
		{
			Interchange_Sort(my_array, N);	
		}
		else if(lc==4)
		{
			Buble_Sort(my_array, N);
		}
		else if(lc==5)
		{
			HeapSort( tam, N);
		}
		else if(lc==6)
		{
			QuickSort(my_array, 0, N-1);
		}
	}
	
	

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
<<<<<<< HEAD

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






=======
>>>>>>> 34905ce81823c637f0ea9119a70428347d6a69ce
	
>>>>>>> 5d589f3b4e81d921ad8d3b294e7e052061cd23d1
	return  0;
}
