#include <stdio.h>
#include <stdlib.h>
#define N 10

// ham in mang
void in_mang(int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

// ham hoan vi
void Hoanvi(int *a, int *b)
{
	int tam;

	tam = *a;
	*a = *b;
	*b = tam;
}

// thuat_toan_chen_truc_tiep
void IntertionSort(int a[], int n)
{
	int pos, i;
	int x;

	for (i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while ((pos >= 0) && (a[pos] > x))
		{
			a[pos + 1] = a[pos];
			pos--;
		}

		a[pos + 1] = x;
		in_mang(a, n);
	}
}

// thuat_toan_chon_truc_tiep
void SelectionSort(int a[], int n)
{
	int min, i, j;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;

		Hoanvi(&a[min], &a[i]);
		in_mang(a, n);
	}
}

void InterchangeSort(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				Hoanvi(&a[i], &a[j]);
				in_mang(a, n);
			}
		}
	}
}

void BubleSort(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				Hoanvi(&a[j], &a[j - 1]);
				in_mang(a, n);
			}
		}
	}
}

void Shift(int a[], int l, int r)
{
	int x, i, j;
	i = l;
	j = 2 * i + 1; 
	x = a[i];
	while (j <= r)
	{
		if (j < r) 
			if (a[j] < a[j + 1])
			
				j = j + 1;
		if (a[j] < x)
			break; 
		else
		{
			a[i] = a[j];
			i = j;
		
			j = 2 * i +1;
			a[i] = x;
		}
	}
}

void CreateHeap(int a[], int n)
{
	int l;
	l = n / 2; 
	while (l >= 0)
	{
		Shift(a, l, n);
		l = l - 1;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a, n-1);
		r = n-1; 
	while (r > 0)
	{
		Hoanvi(&a[0], &a[r]);
		in_mang(a,n);
		r = r - 1;
		Shift(a, 0, r);
	}
}

void QuickSort(int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l + r) / 2];
	i = l;
	j = r;
	do
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			Hoanvi(&a[i], &a[j]);
			in_mang(a,10);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
		
}

int main()
{

	while (1)
	{
		int my_array[] = {12, 2, 8, 5, 1, 6, 4, 15, 26, 24, 50};

		printf("Mang ban dau :");
		in_mang(my_array, N);

		int chon;
		printf("Vui long chon so tuong ung de chon thuat toan sap xep, Nhap 0 de thoat :\n");
		printf("1. SX chon truc tiep\n2. SX chen truc tiep\n3. SX doi cho truc tiep\n4. SX noi bot\n5. SX cay\n6. SX pham hoach\n");
		scanf("%d", &chon);

		switch (chon)
		{
		case 1:
		{
			printf("==> SX chon truc tiep:\n");
			SelectionSort(my_array, N);
			break;
		}

		case 2:
		{
			printf("==> SX chen truc tiep:\n");
			IntertionSort(my_array, N);
			break;
		}

		case 3:
		{
			printf("==> SX doi cho truc tiep:\n");
			InterchangeSort(my_array, N);
			break;
		}

		case 4:
		{
			printf("==> SX noi bot:\n");
			BubleSort(my_array, N);
			break;
		}

		case 5:
		{
			printf("==> SX cay:\n");
			HeapSort(my_array, N);
			break;
		}

		case 6:
		{
			printf("==> SX phan hoach:\n");
			QuickSort(my_array, 0, N - 1);
			break;
		}

		case 0:
			return 0;
		}
	}
	return 0;
}
