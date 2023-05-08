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

int main()
{
    int my_array[] = {1,3,5,7,9,12,15,18,21,23};
    printf("Mang nguyen thuy:\n");
    printf_array(my_array, N);



    return 0;
}

