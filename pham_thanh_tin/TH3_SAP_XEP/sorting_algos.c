# include <stdio.h>
# include <stdlib.h>
# define N 12

void print_array(int a[], int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("%5d", a[i]);
    }
    printf("\n");
}
void Hoanvi(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

// chon truc tiep
void Selectionsort(int a[], int n)
{
    int min, i, j;
    for(i=0; i<n-1; i++)
    {
	    min = i;
	    for(j = i+1; j<n; j++)
	        if(a[j] < a[min])
	            min = j;
	    Hoanvi(&a[min], &a[i]);
	    print_array(a,n);
	}

}
// chen truc tiep
void Insertionsort(int a[], int n)
{
    int pos, i;
    int x;
    for(i=1; i<n; i++)
    {
	    x = a[i];
	    pos = i-1;
	    while((pos>=0) && (a[pos] > x))
	    {
	    	a[pos+1] = a[pos];
	    	pos--;
	    }	
	    a[pos+1] = x;
	    print_array(a,n);
	}
}

//doi cho truc tiep
void Interchangesort(int a[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
	{    for(j= i+1; j<n; j++)
	        if(a[j]<a[i])
	            Hoanvi(&a[i], &a[j]);
	        print_array(a, n);
    }    
}
// noi bot
void Bubblesort(int a[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {   for(j= n-1; j>i; j--)
            if(a[j]<a[j-1])
                Hoanvi(&a[j],&a[j-1]);
            print_array(a, n);
	}		    
}

// sap xep cay
void Shift(int a[], int l, int r)
{
    int x, i, j;
    i=l;
    j=2*i+1;
    x=a[i];
    while(j<=r)
    {
	    if(j<r)
	        if(a[j]<a[j+1])
	            j++;
	        if(a[j]<x)
	            break;
	        else
	        {
	        	a[i]=a[j];
	            i=j;
	            j=2*i+1;
	            a[i]=x;
			}
	}
}

void CreateHeap(int a[], int n)
{
    int l;
    l = n/2;
    while(l >= 0)
    {
	    Shift(a,l,n);
	    l = l-1;
	}
}

void Heapsort(int a[], int n)
{
    int r;
    CreateHeap(a,n-1);
    r=n-1;
    while(r>0)
    {
	    Hoanvi(&a[0], &a[r]);
	    r = r-1;
	    Shift(a, 0, r);
	    print_array(a, n);
	}
}

//phan hoach
void Quicksort(int a[], int l, int r)
{
    int x, i, j;
    x = a[(l+r)/2];
    i=l;
    j=r;
    do 
    {
	    while(a[i] < x) i++;
	    while(a[j] > x) j--;
		if(i<=j)
		{
		    Hoanvi(&a[i], &a[j]);
		    i++; j--;
		}	
	}while(i<j);
	if(l<j)
	    Quicksort(a, l, j);
	if(i<r)
	    Quicksort(a, i, r); 
	    print_array(a, N);
}

int main()
{
   int my_array[] = {17,10,18,12,13,19,20,11,14,16,21,15};

   printf("Xuat mang:\n");
   print_array(my_array, N);
   printf("\n");
   
   /*printf("1. Selection sort\n");
   Selectionsort(my_array, N);
   printf("2. Insertion sort\n");
   Insertionsort(my_array, N);
   printf("3. Interchange sort\n");
   Interchangesort(my_array, N);
   printf("4. Bubble sort\n");
   Bubblesort(my_array, N);*/
  
while(1)
{
	int my_array[] = {17,10,18,12,13,19,20,11,14,16,21,15};
    int select;
        
    printf("1. Selection sort\n");
    printf("2. Insertion sort\n");
    printf("3. Interchange sort\n");
    printf("4. Bubble sort\n");
    printf("5. Heap sort\n");
    printf("6. Quick sort\n");
    printf("Nhap 0 exit\n");
    printf("Moi nhap phuong phap sap xep tren: \n");
    scanf("%d", &select);
    
    if(!select)
        break;
    switch(select)
    {
	    case 1:
	    	printf("\n-----Selection Sort-----\n");
	    	printf("Begin\n");
	        Selectionsort(my_array, N);
	        printf("End\n");
	        break;
	    case 2:
	    	printf("\n-----Insertion Sort-----\n");
	    	printf("Begin\n");
	        Insertionsort(my_array, N);
	        printf("End\n");
	        break;
	    case 3:
	    	printf("\n-----Interchange Sort-----\n");
	    	printf("Begin\n");
	        Interchangesort(my_array, N);
	        printf("End\n");
	        break;
	    case 4:
	    	printf("\n-----Bubble Sort-----\n");
	    	printf("Begin\n");
	        Bubblesort(my_array, N);
	        printf("End\n");
	        break;
	    case 5:
	    	printf("\n-----Heap Sort-----\n");
	    	printf("Begin\n");
	        Heapsort(my_array, N);
	        printf("End\n");
	        break;
	    case 6:
	    	printf("\n-----Quick Sort-----\n");
	    	printf("Begin\n");
	        Quicksort(my_array, 0, N-1);
	        printf("End\n");
	        break;
	    default:
	        break;
	}
}
 
return 0;
}
