#include <stdio.h>
#include <stdlib.h>

#define N 10

void hoan_vi(int* a, int* b)
{
    int temp;
    temp= *a;
    *a = *b;
    *b = temp;
}

void print_array(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
    
        printf("%5d", a[i]);
	}
    printf("\n");
}



void InsertionSort(int a[], int n)
{
	int pos, i;
	int x; 
	for(i=1; i<n; i++)
	{
		x=a[i]; pos= i-1; 
		
		while((pos >=0)&&(a [pos]>x))
        {
            a[pos+1] = a[pos];
            pos--;

        }
        a[pos+1] = x ; 
		
		print_array(a, n);
		
	}	
}


void InterchangeSort(int a[], int n)
{
    int i,j;
    for(i=0; i<n; i++)
        for (j =i+1; j<n; j++)
            if(a[j]<a[i])
     	    	hoan_vi(&a[i], &a[j]);
    print_array(a, n);

}


void BubbleSort(int a[], int n)
{
	int i, j;
	for (i=0; i<n ;i++)
		for (j =N-1; j >i ; j --)
			if (a[j]<a[j-1])
				hoan_vi(&a[j], &a[j-1]);
	print_array(a,n);
	
}


void SelectionSort(int a[], int n)
{
	int min; 
	for(int i=0; i<n-1; i++)
	{
		min=i;
		for(int j=i+1; j<n; j++)
			if (a[j]<a[min])
				min = j; 
		hoan_vi(&a[min], &a[i]);
		print_array(a,n);
		
	}

}


int main()
{
    int my_array[] = {9,8,6,5,7,4,3,1,2,10};
    printf("mang cac day so :\n");
    print_array(my_array,N);
    
    printf("thuat toan sap xep\n");
    
    printf("1. chen truc tiep(Insertion Sort)\n");
    //InsertionSort(my_array, N);
    
    printf("2. doi cho truc tiep(Interchange Sort)\n");
    //InterchangeSort(my_array,N);
    
    printf("3. noi bot(Bubble Sort)\n");
    BubbleSort(my_array,N);
    
    printf("4. chon truc tiep (Selection Sort)\n");
    SelectionSort(my_array,N);
    
    
    

    return 0;
}