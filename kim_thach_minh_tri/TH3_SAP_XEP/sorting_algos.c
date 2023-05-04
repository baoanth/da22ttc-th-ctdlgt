#include <stdio.h>
#include <stdlib.h>
#define N 10


//ham in mang
void in_mang(int a[], int n)
{
	int i;
	
	for (i=0; i<n; i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
}


//ham hoan vi
void Hoanvi(int* a,int* b)
{
	int tam;
	
	tam = *a;
	*a = *b;
	*b = tam;
}

//thuat_toan_chen_truc_tiep
void IntertionSort(int a[],int n)
{
	int pos, i;
	int x;
	
	for( i=1 ; i<n ; i++)
	{
		x = a[i];
		pos = i-1;
		while((pos >=0) && (a[pos] > x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		
		a[pos+1] = x;
		in_mang(a,n);
	}
	
	 
}

//thuat_toan_chon_truc_tiep
void SelectionSort(int a[],int n)
{
    int min,i,j;
    
    for ( i=0; i<n-1; i++)
    {
        min = i;
        for ( j = i+1; j<n; j++)
        	if (a[j] < a[min])
				min = j;
        
        Hoanvi(&a[min], &a[i]);
        in_mang(a,n);
    }
}

void InterchangeSort(int a[], int n )
{
 int i, j;
 
	for (i = 0 ; i<n-1 ; i++)
	{
		for (j =i+1; j <= n ; j++)
		{
			if(a[j ]< a[i])
				Hoanvi(&a[i],&a[j]);
			
		}
		in_mang(a,n);	
	}
		
}


void BubleSort(int a[], int n )
{ 
int i, j;

	for (i = 0 ; i<n ; i++)
	{
		for (j =n-1; j >i ; j --)
		{
			if(a[j]< a[j-1])
			Hoanvi(&a[j],&a[j-1]);
	
		}
		in_mang(a,n);	
	}
		
}


int main()
{
	int my_array []={12, 2, 8, 5, 1, 6, 4, 15, 27, 19, 50, 32};
	
	printf("Mang ban dau :");
	in_mang(my_array,N);
	
	printf("Mang sau khi sap xep :\n");
	//IntertionSort(my_array,N);
	//SelectionSort(my_array,N);
	InterchangeSort(my_array,N);
    //BubleSort(my_array,N);
	
	
	return 0;
}
