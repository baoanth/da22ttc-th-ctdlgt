#include<stdio.h>
#define N 10

void xuatmang(int a[], int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	
	printf("\n");
}


void Hoanvi(int *a, int *b)
{
	int tam;
	
	tam=*a;
	*a=*b;
	*b=tam;	
	
}

void SelectionSort(int a[], int n)
{
	int i, j ,min;
	
	for(i=0; i<n-1; i++)
	{
		min=i;
		
		for(j=i+1;j<n;j++)
			if( a[j]<a[min])	min=j;
			
		Hoanvi(&a[min],&a[i]);
		
		xuatmang(a, n);
		
	}
}

void InsertionSort(int a[], int n)
{
	int pos, i;
	int x;
	
	for(i=1;i<n;i++)
	{
		x=a[i];
		pos= i-1;
	
		while((pos>=0)&&(a[pos])>x)
		{
			a[pos+1]=a[pos];
			pos--;
		}
	
	a[pos+1]=x;
	
	xuatmang(a, n);
	}
}

void InterchangeSort(int a[], int n )
{ 
	int i, j;
	for (i = 0 ; i<n-1 ; i++)
	{
		for (j =i+1; j <= n ; j++)
		{
			if(a[j]< a[i])
			Hoanvi(&a[i],&a[j]);	
		}	
		xuatmang(a, n);
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
		xuatmang(a, n);
	}
}

int main()
{

	int c;
	int my_array[] = {54,12,68,46,23,1,85,79,38,5};
	
	xuatmang(my_array, N);
		
	printf("\nChon 1 trong 4 cach sap xep sau:\n1.SelectionSort\n2.InsertionSort\n3.InterchangeSort\n4.BubleSort\n");
	scanf("%c",&c);
	
	switch(c)
	{
		case '1':
			printf("\n1.SelectionSort\n\n");
			SelectionSort(my_array, N);
			break;
			
		case '2':
			printf("\n2.SelectionSort\n\n");
			InsertionSort(my_array, N);
			break;	
			
		case '3':
			printf("\n3.InterchangeSort\n\n");
			InterchangeSort(my_array, N);
			break;	
			
		case '4':
			printf("\n4.BubleSort\n\n");
			BubleSort(my_array, N);
			break;	
	}
	
	return 0;
}


