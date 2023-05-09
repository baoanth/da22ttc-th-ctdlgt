#include<stdio.h>
#include<stdlib.h>
#define N10

void print_array(int a[],int n)
{
    int i;
    for( i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}

void selectionsort(int a[],int N)
{
    int min,i,j;
    for( i=0;i<N-1;i++)
    {
    min = i;
    for(j =i+1;j<N;j++)
    if(a[j]<a[min])
    min=j;
    hoanvi(&a[min],&a[i]);
    print_array(a,N);
    }
}

int hoanvi(int* a,int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int a[],int N )
{ 
     int pos, i;
     int x; 

     for(i=0; i<N ; i++) 
  {
     x = a[i]; pos = i-1; 
     while((pos >= 0)&&(a[pos] > x))
   {
    a[pos+1] = a[pos];
    pos--;
   }
       a[pos+1] = x; 
       print_array(a,N);
  } 
  
}

void interchangesort(int a[],int N)
{
	int i,j;
	for(i=0;i<N;i++)
    { 
		for(j=i+1;j<=N;j++)
		if(a[j]<a[i])
	  
		hoanvi(&a[i],&a[j]);
        print_array(a,N);
      
	}
}



void bublesort(int a[],int N)
{
    int i,j;
    for(i=0;i<N-1;i++)
    for(j=N-1;j>i;j--)
    if(a[i]<a[j-1])
    hoanvi(&a[j],&a[j-1]);
    print_array(a,N);

}


void shift(int a[],int l,int r)
 {
 	int x;
   int i=0;
    int j=2*i+1;
    while (j<=r)
    {
        if (j<r)
        if (a[j]<a[j-1])
        if(a[j]<x)
        break;
        else
           {  
                a[i]=a[j];
                i=j;
                j=2*i+1;
                a[i]=x;
             }
    }
 }
void createheap(int a[],int n)
{
    int l;
    l=n/2;
    while ( l>0)
    {
        shift(a,l,n);
        l=l-1;

    }
}
void heapsort( int a[],int n)
{
    int r;
    createheap(a,n);
     r=n;
    while(r>0)
    {
        hoan_vi(a[1],a[r]);
        r=r-1;
        shift(a,1,r);
    }
}

void QuickSort(int a[], int l, int r)
{
int i, j;
int x;
x = a[(l+r)/2]; 
i =l; j = r;
do {
while(a[i] < x) i++;
while(a[j] > x) j--;
if(i <= j)
{
Hoanvi(a[i],a[j]);
i++ ; j--;
}
}while(i < j);
if(l < j)
QuickSort(a,l,j);
if(i < r)
QuickSort(a,l,r);
}

