#include <stdio.h>
#include <stdlib.h>

#define N 10


void print_array(int a[], int n)
{
    int i;
    for(i = 0; i< n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

void Hoanvi (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b ;
    *b = temp;
}
// chon truc tiep
void SelectionSort(int a[], int n)
{
    int min, i, j;
    for (  i =0 ; i< n-1 ; i++)
    {
        min = i;
        for ( j= i+1 ; j< n; j++)
        	if (a[j] < a[min])
            	min =j;
        Hoanvi (&a[min], &a[i]);
        print_array(a,n);

        
    }
}
// chen truc tiep
void InsertionSort (int a[], int n)
{
    int pos, i;
    int x;
    for (i=1 ; i<n ; i++)
    {
        x = a[i]; 
        pos = i-1;
        while((pos >=0 )&& (a[pos] > x))
        {
            a[pos+1] = a[pos];
            pos--;

        }
        a[pos+1 ] =x ;
        print_array(a, n);
    
    }
}
// doi cho truc tiep
void InterchangeSort(int a[], int n)
{
    int i,j;
    for (i =0 ; i<n ; i++)
    {
    	for (j = i+1 ; j< n ; j++)
            if(a[j] < a[i])
                Hoanvi(&a[i], &a[j]);
        print_array(a, n);
    }
    

}
// noi not
void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i<n-1 ;i++ )
    {
        for (j = n-1 ; j>i ; j --)
            if(a[j]<a[j-1])
                Hoanvi(&a[j],&a[j-1]);
        print_array(a, n);
    }
    
    
}


int main()
{
    int my_array[] = {1,45,6,8,35,7,9,24,15,36};
    
    printf("Xuat mang :\n");
    print_array(my_array, N);
    printf("\n");
 
   /*printf("demo 1. SelectionSort\n");
    SelectionSort(my_array, N);
    printf("demo 2. InsertionSort\n");
    InsertionSort(my_array, N);
    printf("demo 3. InterchangeSort\n");
    InterchangeSort(my_array, N);
    printf("demo 4. BubbleSort\n");
    BubleSort(my_array, N);*/ 

    while (1)
    {   
        int my_array[] = {1,45,6,8,35,7,9,24,15,36};
        int select;
        printf("1. SelectionSort\n");
        printf("2. InsertionSort\n");
        printf("3. InterchangeSort\n");
        printf("4. BubbleSort\n");
        printf("Nhap 0 de EXIT\n");
        printf("chon mot trong nhung cach tren:\n");
        scanf("%d", &select);

        switch (select)
        {
            case 1:
                SelectionSort(my_array, N);
            case 2:
                InsertionSort(my_array, N);
            case 3:
                InterchangeSort(my_array, N);
            case 4:
                BubbleSort(my_array, N);

            default:
            	
            break;
        
        }

    }

    return 0;

}
