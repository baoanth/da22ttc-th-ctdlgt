#include <stdio.h>
#include <stdlib.h>

#define N 12


void print_array(int a[], int n)
{
    int i;
    for(i = 1; i< n; i++)
    {
        printf("%3d", &a[i]);
    }
}

int main()
{
    int my_array[] = {1,45,6,8,35,7,9,24,15,36,72,47};
    
    printf("Xuat mang :\n");
    print_array(my_array, N);
    printf("\n");
    

    return 0;

}
