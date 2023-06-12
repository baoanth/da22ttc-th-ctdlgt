#include<stdio.h>
#define N 10

void print_array(int a[], int n)
{
	int i;
	for(i=0; i<n;i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void print_array1(int a[], int n)
{
	int i;
	for(i=1; i<=n;i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void Hoanvi(int* a, int* b)
{
	int tam;
	tam = *a;
	*a = *b;
	*b = tam;	
}

void InsertionSort(int a[], int n)
{
	int pos, i;
	int x;
	
	for(i=0;i<n;i++)
	{
		x = a[i]; pos = i-1;
		while((pos>= 0)&&(a[pos] > x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
	    a[pos+1] = x;
		print_array(a, n);	
	}
}

void SelectionSort(int a[], int n)
{
	int min;
	 for (int i = 0; i <n-1 ; i++){
		min = i;
		for(int j = i+1; j <n; j++)
		  if (a[j]< a[min])
		     min = j;
		Hoanvi(&a[min], &a[i]);
		print_array(a, n);
	}
}

void InterchangeSort(int a[], int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		    if(a[i] > a[j])
		Hoanvi(&a[i], &a[j]);
		print_array(a, n); 
	}
}

void BubbleSort(int a[], int n)
{
	int i,j;
	for(i=0; i<n-1; i++)
	{
		for(j=n-1; j>i; j--)
	        if (a[j] < a[j-1])
	            Hoanvi(&a[j], &a[j-1]);
	        print_array(a, n);
	}
}

void Shift(int a[], int l, int r)
{
	int x, i, j;
	i = l;
	j = 2*i+1;
	x = a[i];
	while (j<=r)
	{
		if (j<r)
		   if(a[j] < a[j+1])
		      j=j+1;
		if(a[j] < x)
		   break;
		else{
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
	l = n/2;
	while(l >= 0)
	{
		Shift(a,l,n);
		l = l - 1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a,n-1);
	printf("--------------heap--------------------\n");
    print_array(a,n);
    printf("--------------------------------------\n");
	r = n-1;
	while(r > 0)
	{
		Hoanvi(&a[0], &a[r]);
		print_array(a, n);
		r = r - 1;
		Shift(a,0,r);
	}
}

void QuickSort(int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l + r)/2];
	i = l;
	j = r;
	do{
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if (i<= j)
		{
			Hoanvi(&a[i], &a[j]);
				print_array(a, 10);
			i++ ; j--;
		}
	} while(i<j);
	if(l < j)
		QuickSort(a,l,j);
	if(i < r)
		QuickSort(a,i,r);
	print_array(a, 10);
}

int main()
{
	int my_array[] = {10,8,6,4,2,1,3,5,7,9};
    print_array(my_array, N);
   
    while(1)
    {
    	int my_array[] = {10,8,6,4,2,1,3,5,7,9};
		int lc;
		
		printf("0. EXIT\n");
		printf("1. Chen truc tiep\n");
		printf("2. Chon truc tiep\n");
		printf("3. Doi cho truc tiep\n");
		printf("4. Noi bot\n");
		printf("5. Heap Sort\n");
		printf("6. Quick Sort\n");
		printf("-------\\-------\n");
		printf("Moi chon chuc nang: ");
		scanf("%d", &lc);
		
		if(lc == 0)
		{
			break;
		}
		if(lc == 1)
		{
			InsertionSort(my_array, N);
		}
		if(lc == 2)
		{
			SelectionSort(my_array, N);	
		}
		if(lc == 3)
		{
			InterchangeSort(my_array, N);
		}
		if(lc == 4)
		{
			BubbleSort(my_array, N);
		}
		if(lc == 5)
		{
			HeapSort(my_array, N);
		}
		if(lc == 6)
		{
			QuickSort(my_array, 0, N);
		}
   }
   
	return 0;
}
