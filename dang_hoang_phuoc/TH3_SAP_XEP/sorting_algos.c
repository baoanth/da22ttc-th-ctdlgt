#include <stdio.h>
#include <conio.h>
#define N 14

void print_array(int a[ ], int n)
{
	int i;
    for(i = 0; i < n; i++) 
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void Hoanvi(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[ ], int n)
{
	int min;
	int i, j;
	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		Hoanvi(&a[min], &a[i]);
        print_array(a, n);
	}
}

void InsertionSort(int a[ ], int n)
{
	int pos, i;
	int x;
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
		print_array(a,n);
	}
}

void InterchangeSort(int a[ ], int n)
{
	int i, j;
	for(i = 0; i < n-1; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[i])
			{
				Hoanvi(&a[i], &a[j]);
				print_array(a,n);
			}
		}
	}
}

void BubbleSort(int a[ ], int n)
{
	int i, j;
	for(i = 0; i < n-1; i++)
	{
		for(j = n-1; j > i; j--)
		{
			if(a[j] < a[j-1])
			{
				Hoanvi(&a[j], &a[j-1]);
				print_array(a,n);
			}
		}
	}
}
void Shift(int a[ ], int l , int r)
{
	int x, i, j;
	i = l; 
	j = 2*i+1;
	x = a[i];

	while(j <= r)
	{	
		if(j < r)
			if(a[j] < a[j+1])
				j++;
			if(a[j] < x)
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

void CreateHeap(int a[ ], int n)
{
	int l = n/2;
	while(l >= 0)
	{
		Shift(a, l, n);
		l--;
	}
}

void HeapSort(int a[ ], int n)
{
	CreateHeap(a, n-1);
	printf("=========================Heap=========================\n");
	print_array(a,N);
	printf("======================================================\n");
	int r;
	r = n-1;
	while(r > 0)
	{
		Hoanvi(&a[0], &a[r]);
		print_array(a, n);
		r = r - 1;
		Shift(a, 0, r);
	}
}
void QuickSort(int a[50], int l , int r)
{
	int i, j, x;
	x = a[(l+r)/2];
	i = l; j = r;
	do
	{
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		if(i<=j)
		{
			Hoanvi(&a[i],&a[j]);
			i++;j--;
		}
	}while(i<j);
	if(l<j)
		quickSort(a,l,j);
	if(i<r)
		quickSort(a,i,r);
	print_array(a,14);
}

int main()
{
    while (1)
    {
        char lua_chon;
        int my_array[N] = {3,50,9,6,32,16,92,4,12,16,39,56,48,10};
        printf("Mang Nguyen Thuy: ");
        print_array(my_array, N);
       
   		printf("Vui long nhan vao so tuong ung tung thuat toan de chon, nhan 0 de thoat\n");
        printf("1. Chon truc tiep\n2. Chen truc tiep\n3. Doi cho truc tiep\n4. Noi bot\n5. QuickSort");
      
        lua_chon = getch(); 
        switch (lua_chon)
        {
            case '1':
            {
                printf("-> Chon truc tiep: \n");
                SelectionSort(my_array, N);
                break;
            } 
            case '2':
            {
                printf("-> Chen truc tiep: \n");
                InsertionSort(my_array, N);
                break;
            }
             case '3':
            {
                printf("-> Doi cho truc tiep: \n");
                InterchangeSort(my_array, N);
                break;
            } 
             case '4':
            {
                printf("-> Noi bot: \n");
                BubbleSort(my_array, N);
                break;
            } 
            case '5':
            {
                printf("-> Cay: \n");
                HeapSort(my_array, N);
                break;
            } 
             case '6':
            {
                printf("-> Phan hoach : \n");
                QuickSort(my_array,0, N-1);
                break;
            } 
			
            
            case '0': return 0;
        }
        
	}
	return 0;
}
