#include <stdio.h>
#include <conio.h>
#define N 10

void Pr(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
}

void Hoan_Vi(int *a, int *b)
{
	int tam = *a;
	*a = *b;
	*b = tam;
}

void Insertion_Sort(int a[], int n) //1. Chen truc tiep
{
	int pos, i;
	int x;
	
	for(i=0; i<n; i++)
	{
		x=a[i];
		pos = i-1;
		while(pos>=0 && a[pos]>x)
		{
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
		Pr(a, n);
	}
}

void Selection_Sort(int a[], int n) //2. Chon truc tiep
{
	int min;
	int i, j;
		
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;
			Hoan_Vi(&a[min], &a[i]);
			Pr(a, n);
	}	
}

void Interchange_Sort(int a[], int n) //3. Doi cho truc tiep
{
	int i, j;
	
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
			if(a[i]>a[j])
				Hoan_Vi(&a[i], &a[j]);
			Pr(a, n);	
	}		
}

void Bubble_Sort(int a[], int n) //4. Noi bot
{
	int i, j;
	for(i=0; i<n-1; i++)
	{
		for(j=n-1; j>i; j--)
			if(a[j]<a[j-1])
				Hoan_Vi(&a[j], &a[j-1]);
			Pr(a, n);
	}	
}

int main()
{
	int my_array[] = {10, 22, 36, 64, 7, 1, 2, 5, 11, 45};
	int sl;
	printf("Mang ta co duoc: ");
	Pr(my_array, N);
	
	while(1)
	{
		int my_array[] = {10, 22, 36, 64, 7, 1, 2, 5, 11, 45};
		printf("\nMoi ban lua chon cach sap xep: \n");
		printf("1. Chen truc tiep\n");
		printf("2. Chon truc tiep\n");
		printf("3. Doi cho truc tiep\n");
		printf("4. Noi bot\n");
		printf("0. EXIT\n");
		printf("\nChuc nang so: ");
		scanf("%d", &sl);
	
		if(sl==0)
		{
			break;
		}
		else
		{
			if(sl==1)
			{
				Insertion_Sort(my_array, N);
			}
			else
			{
				if(sl==2)
				{
					Selection_Sort(my_array, N);
				}
				else
				{
					if(sl==3)
					{
						Interchange_Sort(my_array, N);
					}
					else
					{
						if(sl==4)
						{
							Bubble_Sort(my_array, N);
						}
					}
				}
			}	
		}	
	}
}
