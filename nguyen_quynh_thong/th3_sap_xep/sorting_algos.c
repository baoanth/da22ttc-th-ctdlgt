#include <stdio.h>
#include <stdlib.h>

#define N 12


void print_array(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", a[i]);		
	}
	printf("\n");
}

void hoan_vi(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[], int n)
{
	int min;
	int i,j;
	for(i=0; i<n-1; i++ )
	{
		min=i;		
		for ( j=i+1; j<n; j++)		
			if(a[j]< a[min])
				min = j; 
		hoan_vi(&a[min], &a[i]);		
		print_array(a, n);		
	}
	
}
int main()
{
  int my_arr[] = {7,6,8,9,4,12,13,10,19,15,33};
  print_array(my_arr,N);
  printf("1. Selection sort\n");
  SelectionSort(my_arr, N);  
 
  return 0;

}
