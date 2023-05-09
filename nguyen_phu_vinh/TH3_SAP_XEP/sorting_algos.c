#include<stdio.h>
#define N 10
#include<conio.h>
void In_mang( int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
		
	}
	printf("\n");
}

void Hoanvi(int *a,int *b)
{
	int tam;
	tam=*a;
	*a=*b;
	*b=tam;
	
}



// chon truc tiep
void SelectionSort(int a[],int n )
{
	
	int min,i,j;
	for ( i=0; i<n-1 ;i++)
	{
		min=i;
		for (j=i+1 ; j<n ; j++)
		 if(a[j]<a[min])
			 min=j;
	
		Hoanvi(&a[min],&a[i]);
		In_mang(a,n);
	}
	
}
// chen truc tiep
void IntertionSort(int a[],int n)
{
	int pos, i;
	int x;
	for(i=1; i<n; i++)
	{
		x=a[i];
		pos=i-1;
		while((pos>=0) && (a[pos]>x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1]=x;
		In_mang(a,n);
	}
}
// doi cho truc tiep
void InterchangeSort(int a[], int n )
{
	int i,j;
	for(i =0; i<n; i++)
	{
		for(j=i+1; j< n;j++)
		{
			if(a[j]<a[i])
			{
				Hoanvi(&a[i],&a[j]);
				In_mang(a,n);
			}
		
		}
		
	}
	
}
// noi bot
void BubleSort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1; j>i ; j--)
		{
			if(a[j]<a[j-1])
			{
				Hoanvi(&a[j],&a[j-1]);
				In_mang(a,n);
			}
			
		}	
		
			
	}
	
}

// heapsort
void Shift(int a[], int l, int r)
{
	int x, i, j;
	i = l;
	j = 2 * i + 1; 
	x = a[i];
	while (j <= r)
	{
		if (j < r) 
			if (a[j] < a[j + 1])
			
				j = j + 1;
		if (a[j] < x)
			break; 
		else
		{
			a[i] = a[j];
			i = j;
		
			j = 2 * i +1;
			a[i] = x;
		}
	}
}

void CreateHeap(int a[], int n)
{
	int l;
	l = n / 2; 
	while (l >= 0)
	{
		Shift(a, l, n);
		l = l - 1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a, n-1);
		r = n-1; 
	while (r > 0)
	{
		Hoanvi(&a[0], &a[r]);
		In_mang(a,n);
		r = r - 1;
		Shift(a, 0, r);
	}
}


void QuickSort(int a[],int l,int r)
{
	int i,j;
	int x;
	x=a[(l+r)/2];
	i=l;
	j=r;
	do
	{
		while(a[i]<x)
		 i++;
		while(a[j]>x) 
		j--;
		if(i<=j)
		{
			Hoanvi(&a[i],&a[j]);
			In_mang(a,N);
			i++;
			j--;
				
		}
		
	}while(i<j);
	if(l<j)
	QuickSort(a,l,j);
	if(i<r)
	QuickSort(a,i,r);
	
}
int main ()
{
		
	while(1)
	{
		int n,i;
		int my_array[N]= {12, 2, 8, 5, 1, 6, 4, 15,26, 24};
		printf("Mang ban dau:");
		In_mang(my_array,N);
		char chon;
	    printf("Vui long chon so de chon thuat toan sap xep, Nhap 0 de thoat :\n");
	    printf("1. Sap xep chon truc tiep\n2. Sap xep chen truc tiep\n3. Sap xep doi cho truc tiep\n4. Sap xep noi bot\n5. Sap xep HeapSort\n6. Sap xep QuickSort:\n7\n");
	    chon=getch();
	    
		switch(chon)
		{
			case '1':
				{
					printf("==> 1. Sap xep chon truc tiep:\n");
					SelectionSort(my_array,N);
					break;
				}
				
			
			case '2':
				{
					printf("==> 2. Sap xep chen truc tiep:\n");
					IntertionSort(my_array,N);
					
					break;
				}
				
			case '3':
				{
					printf("==> 3. Sap xep doi cho truc tiep:\n");
					InterchangeSort(my_array,N);
					break;
				}
				
			case '4':
				{
					printf("==> 4. Sap xep noi bot:\n");
					BubleSort(my_array,N);
					break;
				}
			case '5':
				{
					printf("==> 5. Sap xep HeapSort:\n");
					HeapSort(my_array,N-1);
					break;
				}
			case '6':
				{
					printf("==> 6. Sap xep QuickSort:\n");
					QuickSort(my_array,0,N-1);
					break;
				}
			case '0':
				return 0;
				
		}
	}
   
}

