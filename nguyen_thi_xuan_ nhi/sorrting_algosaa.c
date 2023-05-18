#include<stdio.h>
#include<stdlib.h>
#define N10

void print_array(int a[],int n)
{
    int i;
    for( i=0;i<n;i++)
    {
        printf("7%d",a[i]);
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

int hoanvi(int*a,int*b)
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

void shift(int a[],int 1,int r)
{
    int x,i,j;
    i=1;
    j=2*i
    x=a[i];
    while (j<=r)
    {
        if(j<r)
        if(a[j]<a[j+1])
        j=j+1;
        if(a[j]<x)
        break;
        else
        {
            a[i]=a[j];
            i=j;
            j=2*i;
            a[i]=x;
        }
    } 
}

void CreateHeap(int a[], int N )
{
     int l;
    l = N/2; 
    while (l > 0)
     {
       Shift(a,l,N);
       l = l -1;
    }
}

void HeapSort (int a[], int N)
{ 
    int r;
    CreateHeap(a,N)
    r = N; 
    while(r > 0)
     {
       Hoanvi(a[1],a[r]);
       r = r -1;
       Shift(a,1,r);
    }
}




















int main()
{
	int N;
    int my_array[]={12,16,34,4,5,66,8,9,55,99};
    printf("\ncac phan tu trong mang la ");
    print_array(my_array, N);
    printf("\ncac phan tu sau khi duoc sap sep");
    selectionsort(my_array,N);
    printf("\n cac phan tu chon truc tiep la");
    InsertionSort(my_array,N);
    printf("\nbublesort");
    bublesort(my_array,N);
    printf("\ninterchangesort ");
    interchangesort(my_array,N);
    HeapSort()

}


