#include<stdio.h>
#include<stdlib.h>
#define N 7

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

int main()
{ 
	int my_arr[] = {3, 5, 7, 6, 8, 9, 61};
	print_array(my_arr, N);
	//	InsertionSort(my_arr, N);
    //	print_array(my_arr, N);

	while(1)
	{
		int my_array[] = {3, 5, 7, 6, 8, 9, 61};	 
    	int lc; 
		printf("0. EXIT\n");
		printf("1. sap xep chen truc tiep \n");
		printf("2. sap xep chon truc tiep \n");
		printf("3. sap xep noi bot \n");
		printf("4. sap xep doi cho truc tiep \n");
		printf("-----------------------------------\n");
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
		
	}
	return 0;
	
}

