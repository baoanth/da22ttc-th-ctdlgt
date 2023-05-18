#include<stdio.h>
#include<conio.h>

#define N 12

void print_array(int a[],int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}
void print_array1(int a[],int n)
{
	int i;
	for (i=1; i<n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void hoan_vi(int* a,int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
 
void SelectionSort(int a[],int n)
{
	int min;
	int i,j;
	
	for( i=0; i<n-1; i++)
	{
		min=i;
		
		for( j=i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;
		hoan_vi(&a[min], &a[i]);
		print_array(a,n);
		
			
	}
}


void InsertionSort(int a[],int n)
{
	int pos, i;
	int x;
	for(i=1; i<n; i++)
	{
		x = a[i]; pos = i-1;
		while((pos>=0)&&(a[pos]>x))
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
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
			if(a[j] < a[i])
			hoan_vi(&a[i], &a[j]);
			print_array(a,n);
			
	}
}


void BubleSort(int a[], int n)
{
	int i,j;
	for(i=0; i<n-1; i++)
	{
		for(j=N-1; j>i; j--)
			if(a[j] < a[j-1])
			hoan_vi(&a[j], &a[j-1]);
			print_array(a,n);
	}
}

void Shift (int a[],int l,int r)
{
	int x, i, j;
	i = l;
	j = 2*i+1;
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

void CreateHeap (int a[], int n)
{
	int l;
	l = n/2; 
	while (l >= 0)
	{
		Shift(a,l,n);
		l = l -1;
		
	}
}

void HeapSort (int a[], int n)
{
	int r;
	CreateHeap(a,n-1);
	r = n-1;
	while(r > 0)
	{
		hoan_vi(&a[0],&a[r]);
		r = r -1;
		Shift(a,0,r);
		print_array1(a,n);
	}
}

void QuickSort(int a[], int l,int r)
{
	int i,j;
	int x;
	x = a[(l+r)/2];
	i = l; j = r;
	do 
	{
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j)
		{
			hoan_vi(&a[i],&a[j]);
			print_array(a,N);
			i++ ; j-- ;
			
		}
	}	while(i < j);
	if(l < j)
		QuickSort(a,l,j);
	if(i < r)
		QuickSort(a,i,r);
		
}



int main()
{
	int my_arr[] = {60,68,18,16,54,35,37,27,25,21,13,10};
	print_array1(my_arr,N);
	
	while(1)
	{
		int my_arr[] = {60,68,18,16,54,35,37,27,25,21,13,10};
		int lc;
		printf("0. EXIT\n");
		printf("1. sap xep chen truc tiep \n");
		printf("2. sap xep chon truc tiep \n");
		printf("3. sap xep doi cho truc tiep \n");
		printf("4. sap xep noi bot \n");
		printf("5. sap xep cay \n");
		printf("6. sap xep phan hoach \n");
		printf("--------------------------------\n");
		printf("moi chon chuc nang \n");
		scanf("%d",&lc);
		if(lc == 0)
		{
			break;
			
		}
		else if(lc == 1)
		{
			InsertionSort(my_arr,N);
			
		}
		else if(lc == 2)
		{
			SelectionSort(my_arr,N);

		}
		else if(lc == 3)
		{
			InterchangeSort(my_arr,N);
			
		}
		else if(lc == 4)
		{
			BubleSort(my_arr,N);
			
		}
		else if(lc == 5)
		{
			HeapSort(my_arr,N);
		
		}
		else if(lc == 6)
		{
			QuickSort(my_arr,0,N-1);
		}










	}






	/*int my_arr[] = {7,8,9,3,15,23,11,27,17,50,22,60};
	print_array(my_arr,N);
	printf("1. Selection Sort\n");
	SelectionSort(my_arr,N);
	printf("2. Insertion Sort\n");
	InsertionSort(my_arr,N);
	printf("3. Interchange Sort\n");
	InterchangeSort(my_arr,N);
	printf("4. Buble Sort\n");
	BubleSort(my_arr,N);*/
	
	
	
	return 0;
	
}

	
