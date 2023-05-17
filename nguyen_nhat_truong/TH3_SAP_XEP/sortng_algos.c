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
	for (i = 0 ; i<n ; i++)
	{
		for (j =i+1; j < n ; j++)
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

void Shift(int a[], int l, int r)
{
	int x, i, j;
	i=l;
	j=2*i+1;
	x=a[i];
	
	while(j<=r)
	{
		if(j<r)
			if(a[j]<a[j+1])	j=j+1;
			
		if(a[j]<x)	break;
			else 
			{
				a[i]=a[j];
				i=j;
				j=2*i+1;
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
		Shift(a,l,n);
		l=l-1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a,n-1);
	r=n-1;
	
	while(r>0)
	{
		Hoanvi(&a[0],&a[r]);
		r=r-1;
		Shift(a,0,r);
		xuatmang(a, n);
	}
}

void QuickSort(int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l+r)/2]; 
	i =l; 
	j =r;
	
	do
	{	
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j)
		{
			Hoanvi(&a[i],&a[j]);
			xuatmang(a, N);
			i++;
			j--;
		}
	}while(i < j);
	
	if(l < j)	QuickSort(a,l,j);
	if(i < r)	QuickSort(a,i,r);
}

int main()
{

	int c;
	int my_array[] = {50,12,84,62,7,24,2,9,35,41};
	
	xuatmang(my_array, N);

while(1)
{		
	int my_array[] = {50,12,84,62,7,24,2,9,35,41};
	printf("\nChon cac lua chon sau:\n0.Exit\n1.SelectionSort\n2.InsertionSort\n3.InterchangeSort\n4.BubleSort\n5.HeapSort\n6.QuickSort\n");
	scanf("%d",&c);

	if(c==0)	break;
		else if(c==1)
		{
			printf("\n1.SelectionSort\n\n");
			SelectionSort(my_array, N);
			printf("\n------------\n");
		}
		else if(c==2)
		{
		 	printf("\n2.SelectionSort\n\n");
			InsertionSort(my_array, N);
			printf("\n------------\n");
		}
		else if(c==3)
		{
		 	printf("\n3.InterchangeSort\n\n");
			InterchangeSort(my_array, N);
			printf("\n------------\n");
		}
		else if(c==4)
		{
			printf("\n4.BubleSort\n\n");
			BubleSort(my_array, N);
			printf("\n------------\n");
		}
		else if(c==5)
		{
			printf("\n5.HeapSort\n\n");
			HeapSort(my_array, N);
			printf("\n------------\n");
		}
	else if(c==6)
		{
			printf("\n6.QuickSort\n\n");
			QuickSort(my_array , 0, N-1);
			printf("\n------------\n");
		}
	return 0;

}
}
