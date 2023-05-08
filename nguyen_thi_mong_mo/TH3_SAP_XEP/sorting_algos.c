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
	int min; // chi so phan tu nho nhat trong day hien hanh
	int i,j;
	for(i=0; i<n-1; i++ )
	{
		min=i;		
		for ( j=i+1; j<n; j++)		
			if(a[j]< a[min])
				min = j; // Ghi nhan vi tri phan tu nho nhat hien hanh
		hoan_vi(&a[min], &a[i]);		
		print_array(a, n);		
	}
	
}




int main()
{
  int my_arr[] = {6,7,8,4,15,23,11,27,17,50,22,66};
  print_array(my_arr,N);
  printf("1. Selection sort\n");
  SelectionSort(my_arr, N);  
 
  return 0;

}
