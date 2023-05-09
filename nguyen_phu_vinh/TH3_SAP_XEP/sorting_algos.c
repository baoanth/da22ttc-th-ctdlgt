#include<stdio.h>
#define N 10
#include<conio.h>
void In_mang( int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
		
	}
	printf("\n");
}

void Hoanvi(int *a,int *b)
{
	int tam;
	tam=*a;
	*a=*b;
	*b=tam;
	
}



// chon truc tiep
void SelectionSort(int a[],int n )
{
	
	int min,i,j;
	for ( i=0; i<n-1 ;i++)
	{
		min=i;
		for (j=i+1 ; j<n ; j++)
		 if(a[j]<a[min])
			 min=j;
	
		Hoanvi(&a[min],&a[i]);
		In_mang(a,n);
	}
	
}
// chen truc tiep
void IntertionSort(int a[],int n)
{
	int pos, i;
	int x;
	for(i=1; i<n; i++)
	{
		x=a[i];
		pos=i-1;
		while((pos>=0) && (a[pos]>x))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1]=x;
		In_mang(a,n);
	}
}
// doi cho truc tiep
void InterchangeSort(int a[], int n )
{
	int i,j;
	for(i =0; i<n; i++)
	{
		for(j=i+1; j< n;j++)
		{
			if(a[j]<a[i])
			{
				Hoanvi(&a[i],&a[j]);
				In_mang(a,n);
			}
		
		}
		
	}
	
}
// noi bot
void BubleSort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1; j>i ; j--)
		{
			if(a[j]<a[j-1])
			{
				Hoanvi(&a[j],&a[j-1]);
				In_mang(a,n);
			}
			
		}	
		
			
	}
	
}



int main ()
{
	while(1)
	{
		int n,i;
		int my_array[N]= {12, 2, 8, 5, 1, 6, 4, 15,26, 24};
		printf("Mang ban dau:");
		In_mang(my_array,N);
		char chon;
	    printf("Vui long chon so de chon thuat toan sap xep, Nhap 0 de thoat :\n");
	    printf("1. Sap xep chon truc tiep\n2. Sap xep chen truc tiep\n3. Sap xep doi cho truc tiep\n4. Sap xep noi bot\n");
	    chon=getch();
	    
		switch(chon)
		{
			case '1':
				{
					printf("==> 1. Sap xep chon truc tiep:\n");
					SelectionSort(my_array,N);
					break;
				}
				
			
			case '2':
				{
					printf("==> 2. Sap xep chen truc tiep:\n");
					IntertionSort(my_array,N);
					
					break;
				}
				
			case '3':
				{
					printf("==> 3. Sap xep doi cho truc tiep:\n");
					InterchangeSort(my_array,N);
					break;
				}
				
			case '4':
				{
					printf("==> 4. Sap xep noi bot:\n");
					BubleSort(my_array,N);
					break;
				}
			
			case '0':
				return 0;
				
				
	
		}
	}
   
}





