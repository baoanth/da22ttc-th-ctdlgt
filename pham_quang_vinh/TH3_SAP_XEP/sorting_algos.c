#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10


void print_array(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", a[i]);		
	}
	printf("\n");
}

void hoan_vi(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[], int n)
{
	int min; // chi so phan tu nho nhat trong day hien hanh
	int i,j;
	for(i=0; i<n-1; i++ )
	{
		min=i;		
		for ( j=i+1; j<n; j++)		
			if(a[j]< a[min])
				min = j; // Ghi nhan vi tri phan tu nho nhat hien hanh
		hoan_vi(&a[min], &a[i]);		
		print_array(a, n);		
	}
	
}
void InsertionSort(int a[], int n)
{
	int pos,i;
	int x; //Luu gia tri a[i] tranh bi ghi de khi doi cho cac phan tu 
	for (i=1;i<n;i++) //doan a[0] da sap
{
	x = a[i]; pos= i-1; //tim vi tri chen x
	while ((pos >=0)&&(a[pos]>x))
	{
		a[pos +1] =a[pos];
		pos--;
	}
	a[pos+1]=x;
	print_array(a, n);
}
}
void InterchangeSort (int a[] ,int n)
{
	int i,j;
	for (i=0; i<n;i++)
    for (j=i+1;j< n;j++)
	if(a[j]<a[i])
	{
		hoan_vi(&a[i],&a[j]);
		print_array(a, n);
	}

}
void BubleSort(int a[],int n)
{
	int i,j;
	for (i=0;i<n-1;i++)
	for (j =n-1;j>i;j--)
	if(a[j]<a[j-1])
	{
			hoan_vi(&a[j],&a[j-1]);
			print_array(a, n);
	}

}
int main()
{
	while (1)
	{
		char lua_chon;
		  int my_array[N] = {7,6,8,9,4,12,13,10,19,15,33};
		  printf("Mang ban dau:");
		  print_array(my_array,N);
		  printf("Vui long nhap vao so tuong ung thuat toan de chon,nhan 0 de thoat\n");
		  printf("1.Chon truc tiep\n2.Chen truc tiep\n3.Doi truc tiep\n4.Noi bot\nSo:");
		  lua_chon = getch();
		  switch (lua_chon)
		  {
		  	case '1':
		  		{
				  printf("->Chon truc tiep:\n");
		  		  SelectionSort(my_array,N);
		  		  break;
		  		}
		  case '2':
		  		{
				  printf("->Chen truc tiep:\n");
		  		  InsertionSort(my_array,N);
		  		  break;
		  		}
		  case '3':
		  		{
				  printf("->Doi cho truc tiep:\n");
		  		  InterchangeSort(my_array,N);
		  		  break;
		  		}
		  case '4':
		  		{
				  printf("->Noi bot:\n");
		  		  BubleSort(my_array,N);
		  		  break;
		  		}	
		  case '0':
		  return 0;
		  }
	}
	return 0;
}
