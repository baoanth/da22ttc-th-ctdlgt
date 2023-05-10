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
    printf("Nhap 0 exit\n");
    printf("Moi nhap phuong phap sap xep tren: \n");
    scanf("%d", &select);
    
    switch(select)
    {
	    case 1:
	        Selectionsort(my_array, N);
	        break;
	    case 2:
	        Insertionsort(my_array, N);
	        break;
	    case 3:
	        Interchangesort(my_array, N);
	        break;
	    case 4:
	        Bubblesort(my_array, N);
	        break;
	    default:
	        break;
	}
}
 
return 0;
}