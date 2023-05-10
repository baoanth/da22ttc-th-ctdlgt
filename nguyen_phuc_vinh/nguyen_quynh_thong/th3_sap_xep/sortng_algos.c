#include <stdio.h>
#include <stdlib.h>
#define N10
void in_mang(int a[],int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%5d",a[i]);
		
	}
	printf("\n");
}
void hoaanvi(int a, int b)
{
	int tam;
	tam=*a;
	*a=*b;
	*b=tam;
	
}
void insertionsort (int a[]),int N[])
{
	int pos,i;
	int x;
		for (int i=0; i<N-1; i++)
{
	x=a[i]
    pos=i-1
	while((pos>=0)&&(a[pos]>x)) 
{  
	a[pos+1]=a[pos];
	pos--j;
}
    a[pos+1]=x;
}  
}
void slectionsort(int a[], int N)
{
    int min;
    for(int m=0; i<n-1)
{
        
	min=i;		
	for (int j= i+1; j<n; j++)		
	if (a[j] < a[min])
		
{ 		
		min=j;
}
		hoanvi (a[min], a[i]);
}		
}
int main()
{
	int my_array[12,2,8,5,1,6,4,15]
    for(int i=0; i<N; i++)
    
    printf("mang nam dau =%4d");
}
void InterchangeSort(int a[], int N )
{ 
    int i, j;
    for (i = 1 ; i<N ; i++)
    for (j =i+1; j <= N ; j++)
    if(a[j ]< a[i])

Hoanvi(a[i],a[j]);
}

