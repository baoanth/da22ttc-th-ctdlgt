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

// cay
void Shift (int a[], int l, int r)
{
    int x, i, j;
    i = l; 
    j = 2*i+1;
    x = a[i];
    while (j<=r)
    {
        if (j < r ) 
            if (a[j] < a[j+1])
                j ++;
            if (a[j] < x)
                break;
            else
            {
                a[i] = a[j];
                i = j;
                j = 2*i+1;
                a[i] = x;
            }
    }
}
void CreateHeap(int a[], int n)
{
    int l;
    l = n/2;
    while (l >= 0)
    {
        Shift(a, l, n);
        l = l -1 ;
    }
}
void HeapSort (int a[], int n)
{
    int r;
    CreateHeap( a, n -1);
    r = n -1;
    while(r> 0)
    {
        Hoanvi(&a[0], &a[r]);
        r = r -1;
        Shift(a, 0, r);
        print_array(a, n);
    }
    
}
void QuickSort(int a[],  int l, int r)
{
    int i, j;
    int x;
    x =a[(l+r)/2];
    i = l;
    j = r;
    do
    {
        while( a[i] < x)  i++;
        while( a[j] > x)  j--;
        if( i <= j)
        {
            Hoanvi(&a[i], &a[j]);
            i++;
            j--;
        }
    }while (i < j);
    if(l < j)
        QuickSort(a, l, j);
    if(i < r)
        QuickSort(a, i, r);
    print_array(a, N);
    
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
        printf("5. HeapSort\n");
        printf("6. QuickSort\n");
        printf("Nhap 0 de EXIT\n");
        printf("chon mot trong nhung cach tren:  ");
        scanf("%d", &select);
		if(!select)
			break; 
        switch (select)
        {
            case 1:
            	printf("\n ----SelectionSort----\n");
                SelectionSort(my_array, N);
                printf("\n----END----\n");
                break;
            case 2:
            	printf("\n----�nertionSort----\n");
                InsertionSort(my_array, N);
                printf("\n----END----\n");
                break;
            case 3:
            	printf("\n----InterchangeSort----\n");
                InterchangeSort(my_array, N);
                printf("\n----END----\n");
                break;
            case 4:
            	printf("\n----BubbleSort----\n");
                BubbleSort(my_array, N);
                printf("\n----END----\n");
                break;
            case 5:
            	printf("\n----HeapSort----\n");
            	HeapSort(my_array, N);
            	printf("\n----END----\n");
            	break;
            case 6:
                printf("\n----QuickSort----\n");
                QuickSort(my_array, 0, N - 1);
            	printf("\n----END----\n");


            default:
            	
                break;
        
        }

    }

    return 0;

}
