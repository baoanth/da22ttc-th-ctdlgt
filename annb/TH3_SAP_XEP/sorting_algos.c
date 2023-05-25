#include <stdio.h>
#include <stdlib.h>

#define N 12


void SelectionSort(int a[], int n)
{
	int min, i,j; // chi so phan tu nho nhut trong day hien hanh
	for( i = 0 ; i<n-1; i++)
	{
		min = i;
		for (j = i+1; j<n; j++)
			if (a[j]<a[min])
				min = j; // ghi nhan vi tri phan tu nho nhat moi
		
		hoan_vi(&a[min], &a[i]);
		print_array(a, n);		
	}
	
}


void hoan_vi(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void print_array(int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

int main()
{
    int my_array[] = {3,5,6,1,7,23,45,11,65,22,44,57};
    printf("Mang nguyen thuy:\n");
    print_array(my_array, N);

    printf("Demo Thuat toan sap xep\n");
    printf("1. Selection sort\n");
    
    
	SelectionSort(my_array, N);
    

    return 0;
}
