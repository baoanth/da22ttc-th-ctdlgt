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
	for (i=0; i<n-1 ;i++){
	
		for (j =N-1; j >i ; j --)
		
			if (a[j]<a[j-1])
				hoan_vi(&a[j], &a[j-1]);
	print_array(a,n);
}
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

void Shift(int a[], int l, int r )
{
    int x, i, j;
    i= l;
    j= 2*i;
    x= a[i];
    while(j<=r)
    {
        if (i<r)
            if (a[j] < a[j+1])
                j= j+1;
            if (a[j] < x)
                break;
            else
            {
                a[i]= a[j];
                i= j;
                j= 2*i;
                a[i]= x; 

            }
    }
}

void CreateHeap(int a[], int n )
{
    int l;
    l= n/2;;
    while( l>0)
    {
        Shift(a, l, n);
        l= l-1;
    }
}


void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a, n);
	r= n;
	while(r>0)
	{
		hoan_vi(&a[1], &a[r]);
		r= r-1;
		Shift(a,1,r);
		print_array(a,n);
	}
}


void QuickSort(int a[], int l, int r)
{
	int i, j;
	int x;
	x= a[(l+r)/2];
	i=l; j=r;
	do 
	{
	
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j)
		{
			hoan_vi(&a[i], &a[j]);
			i++; j--;
		}
	}while (i < j);
	if(l < j)
		QuickSort(a,l,j);
	if(i < r)
		QuickSort(a,i,r);
}

int main()
{
    int my_array[] = {9,8,6,5,7,4,3,1,2,10};
    printf("mang cac day so :\n");
    print_array(my_array,N);

    
    
    	
    	
    	
    
    printf("thuat toan sap xep\n");

    printf("1. chon truc tiep (Selection Sort)\n");
  //  SelectionSort(my_array,N);
    
    printf("2. chen truc tiep(Insertion Sort)\n");
 //   InsertionSort(my_array, N);
    
    printf("3. doi cho truc tiep(Interchange Sort)\n");
 //   InterchangeSort(my_array,N);
    
    printf("4. noi bot(Bubble Sort)\n");
 //   BubbleSort(my_array,N);
    
    printf("5. cau truc du lieu(Heap)\n");
//    HeapSort(my_array,N);
    
    printf("6. phuong phap sap xep phan hoach(QuickSort)\n");
 //   QuickSort(my_array,N);
    
  
    int chon = 1;
    while(1)
    {   //int my_array[] = {9,8,6,5,7,4,3,1,2,10};
    
    	printf("nhap so muon chon, nhan 0 de EXIT \n");
    	scanf("%d", &chon);
    	if(!chon)
    		break;
    	switch(chon)
    	{
    		case 1:
                printf("1. chon truc tiep (Selection Sort)\n");
    			SelectionSort(my_array,N);
                break;
            case 2:
                printf("2. chen truc tiep(Insertion Sort)\n");
                InsertionSort(my_array, N);
                break;
            case 3:
                printf("3. doi cho truc tiep(Interchange Sort)\n");
                InterchangeSort(my_array,N);
                break;
            case 4:
                printf("4. noi bot(Bubble Sort)\n");
                BubbleSort(my_array,N);
                break;
            case 5:
            	printf("5. cau truc du lieu(Heap)\n");
  				HeapSort(my_array,N);
  				break;
  			case 6:
  				printf("6. phuong phap sap xep phan hoach(QuickSort)\n");
 			    QuickSort(my_array,N);
    			default:
    			break;
    	}
    }  
    return 0;
}