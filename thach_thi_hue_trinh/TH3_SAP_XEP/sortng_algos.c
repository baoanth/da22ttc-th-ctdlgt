#include<stdio.h>
#include<stdlib.h>
#define N 10

void Xuatmang(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");

}

void Hoanvi(int *x, int *y )
{
	int tam;
	
	tam=*x;
	*x=*y;
	*y=tam;  
	    
}

void Selection_Sort( int a[], int n)
{
	int i, j, min;
	
	for (i=0; i<n-1; i++)
	{
		min = i;
		
		for(j=i+1; j<n; j++)
		    if( a[j] < a[min])
		        min = j;
		        
		Hoanvi(&a[min], &a[i]);
		Xuatmang(a,n);
	}
}

void Insertion_Sort (int a[], int n)
{
	int pos, i;
	int x;
	
	for(i=1; i<n; i++)
	{
		x=a[i];
		pos=i-1;
		
		while((pos>=0)&&(a[pos]>x))
		{
			a[pos+1]= a[pos];
			pos--;
		}
		a[pos+1]=x;
		Xuatmang(a,n);
	}	
}
void Interchange_Sort (int a[], int n)
{
	int i,j;
	
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[j]<a[i])
			
				Hoanvi(&a[i],&a[j]);
		}
		Xuatmang(a,n);
					
	}	
}

void Bubble_Sort(int a[], int n)
{
	int i, j;
	
	for(i=0; i<n; i++)
	{
		for(j=n-1; j>i; j--)
		{
			if(a[j]<a[j-1])
				
				Hoanvi(&a[j], &a[j-1]);
		}
		Xuatmang(a,n);	
	}
}

void Shift (int a[], int l, int r)
{
	int x, i, j;
	i=l;
	j=2*i+1; 
	x= a[i];
	
	while(j<=r)
	{
		if(j<r)
			if(a[j]<a[j+1]) j=j+1;
			
			if(a[j]<x) break;
			
			else 
			{
				a[i]= a[j];
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
	
	while(l>=0)
	{
		Shift(a,l,n);
		l=l-1;
	}
}

void Heap_Sort( int a[], int n)
{
	int r;
	CreateHeap(a,n-1);
	r=n-1;
	
	while(r>0)
	{
		Hoanvi(&a[0],&a[r]);
	
		r=r-1;
		Shift(a,0,r);	
		Xuatmang(a,n);	
	}
	
}

void Quick_Sort(int a[], int l, int r)
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
		if(i<= j)
		{
			printf("Hoan vi %2d <=> %2d | ", a[i], a[j]);
			Hoanvi(&a[i],&a[j]);
			Xuatmang(a,N);
			i++; j--;
		
	    }
		
	}
	while(i<=j);
	
	if(l<j) Quick_Sort(a,l,j);
	if(i<r) Quick_Sort(a,i,r);
	
}

int main()
{

	char c;
	int my_array[]={ 2, 8, 12, 5, 1, 6, 4, 15, 27, 19};

	Xuatmang(my_array,N);

while(1)
	{		
		int my_array[] ={ 2, 8, 12, 5, 1, 6, 4, 15, 27, 19};
		
		printf("\nChon cac lua chon sau: \n0.Esc \n1.Selection_Sort \n2.Insertion_Sort \n3.Interchange_Sort \n4.Bubble_Sort \n5.Heap_Sort \n6.Quick_Sort\n");
		scanf("%d",&c);

		if(c==0)	break;
		else if(c==1)
		{
			printf("\n1.SelectionSort\n\n");
			Selection_Sort(my_array, N);
			printf("\n");
		}
		else if(c==2)
		{
		 	printf("\n2.SelectionSort\n\n");
			Insertion_Sort(my_array, N);
			printf("\n");
		}
		else if(c==3)
		{
		 	printf("\n3.InterchangeSort\n\n");
			Interchange_Sort(my_array, N);
			printf("\n");
		}
		else if(c==4)
		{
			printf("\n4.BubbleSort\n\n");
			Bubble_Sort(my_array,N);
			printf("\n");
		}
        else if(c==5)
        {
        	printf("\n5.HeapSort\n\n");
        	Heap_Sort(my_array,N);
        	printf("\n");
        }
        else if(c==6)
        {
        	printf("\n6.QuickSort\n\n");
        	Quick_Sort(my_array,0,N-1);
        	printf("\n");
        }

	}
	
	return 0;
}
