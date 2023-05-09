#include<stdio.h>
#include<stdlib.h>
#define N 8

void print_array(int a[],int n)
{
	int i;
	for (i=0; i<n; i++)
	{
     printf ("%4d", a[i]);
	}
	printf ("\n");
}

void Hoan_vi(int* a, int* b)
{
	int tam;
	tam = *a;
	*a = *b;
	*b=tam;
	
	
}
void SelectionSort( int a[],int n )
{
	int min, i, j;
	for (i=0; i<n-1; i++)
	{
		min = i;
    	for (j=i+1; j<n; j++)
    	{
    		if (a[j]< a[min])
    		min =j;
    	}
    	Hoan_vi ( &a[min], &a[i]); 
		 print_array(a, n); 
	}

}

void InsertionSort(int a[], int n )
{ 
    int pos, i;
    int x; 
    for(i=1; i<n; i++)
    {
    	x=a[i]; pos = i-1;
    	while ((pos >= 0)&&(a[pos]>x))
    	{
    		a[pos+1] = a[pos];
    		pos--;
    	}
    	a[pos+1] = x;
    	print_array(a, n);
    }

}
void InterchangeSort( int a[],int n)
{
	int i,j;
	for ( i=1; i<n; i++)
	{
		for ( j=i+1; j<n; j++)
   	    if (a[i]< a[j])
	    Hoan_vi(&a[i],&a[j]);
	    print_array(a, n);
	}
}

void BubbleSort(int a[], int n )
{ 
    int i, j;
    for (i = 1 ; i<n-1 ; i++)
    {
        for (j =n-1; j >i ; j --)
        if(a[j]< a[j-1])
        Hoan_vi(&a[j],&a[j-1]);
        print_array(a, n);
    }
   
}
void Shift (int a[], int l, int r )
{ 
    int x, i, j;
    i=l;
    j=2*i+1;//(ai, aj), (ai, aj+1)
    x=a[i];
    while(j<=r)
    {
        if (j<r)
		if (a[j]< a[j+1])
		j= j+1;	
		if (a[j]< x)
		break; 
        else 
        {
        	a[i]= a[j];
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
	while(l >=0)
	{
		Shift ( a, l, n);
		l =l -1;
	}
}
void HeapSort(int a[], int n )
{
	int r;
	CreateHeap(a, n-1);
	r = n-1;
	while(r>0)
	{
		Hoan_vi( &a[0], &a[r]);
		r = r - 1;
		Shift(a,0,r);
		print_array(a, n);
	}
}
void QuickSort( int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l+r)/2];
	i = l; 
	j = r;
	do
	{
		while( a[i] < x) i++;
		while( a[j] > x) j--;
		if (i <= j)
		{
			Hoan_vi( &a[i],&a[j]);
				print_array(a, N);
			i++; j--;
		}
	}while(i<j);
	
		if(l<j) 
			QuickSort(a,l,j);
		if(i<r)
			QuickSort(a,i,r);
	   
	}


int main()
{ 
	int my_arr[] = {3, 5, 7, 6, 8, 9, 61, 96};
	print_array(my_arr, N);
	//	InsertionSort(my_arr, N);
    //	print_array(my_arr, N);

	while(1)
	{
		int my_array[] = {3, 5, 7, 6, 8, 9, 61, 96};	 
    	int lc; 
		printf("0. EXIT\n");
		printf("1. sap xep chen truc tiep \n");
		printf("2. sap xep chon truc tiep \n");
		printf("3. sap xep noi bot \n");
		printf("4. sap xep doi cho truc tiep \n");
		printf("5. sap xep cay \n");
		printf("6. sap xep phan hoach \n");
		printf("moi chon chuc nang \n");
		scanf("%d", &lc);
		if(lc == 0)
		{
			break;
		}
		else if(lc == 1)
		{		
			InsertionSort(my_array, N);	
		}
		else if(lc == 2)
		{
			SelectionSort(my_array, N);	
		}
		else if (lc == 3)
		{		
			BubbleSort(my_array, N);
		}
		else if(lc == 4)
		{
    		InterchangeSort(my_array, N);
		}
		else if(lc == 5)
		{
			HeapSort(my_array, N);
		}
		else if(lc == 6)
		{
			QuickSort(my_array,0, N-1);
		}
		
	}
	return 0;
	
}

