#include <stdio.h>
#include <stdlib.h>

#define N 10


void printf_array(int a[],int n)
{
  int i;
  for (i=0; i<n; i++)
  {
    printf("%5d", a[i]);
  }
  printf("\n");
}
void hoan_vi(int *a, int *b)
{
	int tam;
	tam = *a;
	*a = *b;
	*b = tam;
}

void SelectionSort(int a[ ], int n)
{
	int min;
	int i, j;
	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		hoan_vi(&a[min], &a[i]);
        print_array(a, n);
	}
}

int main()
{
    int my_array[] = {1,5,3,9,7,21,15,23,12,18};
    printf("Mang nguyen thuy:\n");
    printf_array(my_array, N);



    return 0;
}

