#include<stdio.h>
#include<stdlib.h>
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

int main()
{
	int my_array[] = {1,3,5,7,9,2,4,6,8,10};
    print_array(my_array, N);
    
    while(1)
    {
    	int my_array[] = {1,3,5,7,9,2,4,6,8,10};
		int lc;
		
		printf("0. EXIT\n");
		printf("1. Chen truc tiep\n");
		printf("2. Chon truc tiep\n");
		printf("3. Doi cho truc tiep\n");
		printf("4. Noi bot\n");
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
				
   }
   
	return 0;
}