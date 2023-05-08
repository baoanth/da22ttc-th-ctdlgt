#include<stdlio.h>
#include<stdlib.h>
#define N10
void print_array(int a[],int n)
{
    int i;
    for( i=0;i<n;i++)
    {
        printf("d",a[i]);
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
    print_array(a,n);
    }
}
void hoanvi(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void InsertionSort(int a[], int N )
{ 
     int pos, i;
     int x; 

     for(int i=0; i<N ; i++) 
  {
     x = a[i]; pos = i-1; 
     while((pos >= 0)&&(a[pos] > x))
   {
    a[pos+1] = a[pos];
    pos--;
   }
    a[pos+1] = x]; 
  } 
}
void interchangesort(int a[],int N)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<=N;j++)
		if(a[j]<a[i])
		{
		hoanvi(a[i],a[j]);
		}
	}


}







int main()
{
    int my_array[]={12,16,34,4,5,66,8,9,55,99};
    printf("cac phan tu trong mang la ");
    print_array(my_array, N);
    printf("cac phan tu sau khi duoc sap sep");
    selectionsort(my_array,N);
}


