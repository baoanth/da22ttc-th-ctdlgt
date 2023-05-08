#include <stdio.h>
#include <stdlib.h>
#define N 10
 
void print_array(int a[], int n)
{
    int i;
    for (i=0; i<n; i++);
    {
        printf("%5d", a[i]);

    }
    printf("\n");
}
int main()
{
    int my_array[] = {2,4,6,8,10,1,3,5,7,9};
    printf("Mang nguyen thuy:\n");
    print_array(my_array, N);

    return 0;
}
