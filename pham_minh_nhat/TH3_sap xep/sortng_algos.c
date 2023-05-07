#include <stdio.h>
#include <stdio.h>
#define N 10 
void print_array(int a[],int n)
{
	int i;
	for (i = 0;i<n;i++)
	{
		printf("%5d",a[i]);
		
	}
	printf("\n");
}
void hoan_vi(int *a,int *b)
{
	int tam;
	tam =*a;
	*a = *b;
	*b = tam;
	
}
void SelectionSort(int a[],int n)
{
    int min; 
    for (int i=0;i<N-1 ; i++) 
    {
      min = i;
     
      for(int j = i+1; j <N ; j++ )
	   
       if(a[j]< a [min])
       
           min = j; 
	   Hoanvi(a[min] , a[i]);
	   print_array(a,n);
	   
    }
    
}
void InsertionSort (int a[],int N)
{
   int pos, i;
	int x // luu gia tri a[] tranh bi ghi de khi doi cho cac phan tu 
	for(int i=1;i<n;i++)
   {
   
		x=a[i]
		pos =i-1 
		while((pos >=0)&&(a[pos]>x))
		{
	        a[pos+1] = a[pos];
	        pos--
		}
		a[pos+1] = x ;
		print_array(a,n);
   }
}
void InterchaeSort(int a[],int n)
{
	int i,j;
	for(i = 0;i< n-1 ;i++)
	{
		for(j = i+1; j < n ;j++)
		{
			if (a[j]<a[i])
			{
				hoan_vi(%a[i],&a[j]);
				
			}
		}
	}   print_array(a,n);
	
}
int main()
{
	while(1)
	{
		char lua_chon;
		int my_array[N] = {12,2,8,5,1,6,4,15,3,9};
		printf("Mang ban Dau:");
		printf_array(my_array,N);
		printf("Vui long nhan vao so tuonng ung tung thuat toan de chon , nhan 0 de thoat \n");
		printf("1.chon truc tiep \n2.Chen truc tiep \n3.Doi cho truc tiep \n4.Noi bot \n");
	    lua_chon = getch();
	    swith (lua_chon)
	    {
	    	case '1':
	    	{
	    		printf("-> chon truc tiep: \n");
	    		selectionsort(my_array,N);
	    		break;
	    		
	    	}
	        case '2':
	    	{
	    		printf("-> chon truc tiep: \n");
	    		InsertionSort(my_array,N);
	    		break;
	    	}
	       case '3':
	    	{
	    		printf("->chon truc tiep: \n");
	    		InterchaeSort(my_array,N);
	    		break;
	    	}
	    }
	}   

 return 0;
    
} 

	
	
	
	
	
	
	
	
	
	
	
	
	


