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

			j = 2 * i + 1;
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
	CreateHeap(a, n - 1);
	printf("======Heap=====\n");
	r = n - 1;
	while (r > 0)
	{
		Hoanvi(&a[0], &a[r]);
		in_mang(a, n);
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
			printf("Hoan vi %4d <==> %2d :",a[i],a[j]);
			Hoanvi(&a[i], &a[j]);
			in_mang(a, 10);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
}

void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	int i, j, k;

	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
	in_mang(a, N);
}

void MergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void RadixSort(int a[], int n)
{
	int i;
	int b[n], m = a[0], exp = 1;

	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
		}
	}

	while (m / exp > 0)
	{
		int bucket[10] = {0};
		for (i = 0; i < n; i++)
		{
			bucket[a[i] / exp % 10]++;
		}

		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}

		for (i = n - 1; i >= 0; i--)
		{
			b[--bucket[a[i] / exp % 10]] = a[i];
		}

		for (i = 0; i < n; i++)
		{
			a[i] = b[i];
		}

		exp *= 10;
		in_mang(a, n);
	}
}

void CountingSort(int a[], int n)
{
	int i;
	int b[n], c[101] = {0};

	
	for (i = 0; i < n; i++)
	{
		c[a[i]]++;
	}

	
	for (i = 1; i <= 100; i++)
	{
		c[i] += c[i - 1];
	}

	
	for (i = n - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}

	
	for (i = 0; i < n; i++)
	{
		a[i] = b[i];
		in_mang(a, n);
	}
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
		printf("1. SX chon truc tiep\n2. SX chen truc tiep\n3. SX doi cho truc tiep\n4. SX noi bot\n5. SX cay\n6. SX phan hoach\n7. SX tron\n8. SX theo co so\n9. SX dem\n");
		printf("Nhap lua chon: ");
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

		case 7:
		{
			printf("==> SX tron:\n");
			MergeSort(my_array, 0, N - 1);
			break;
		}

		case 8:
		{
			printf("==> SX theo co so:\n");
			RadixSort(my_array, N);
			break;
		}

		case 9:
		{
			printf("==> SX dem:\n");
			CountingSort(my_array, N);
			break;
		}

		case 0:
			return 0;
		}
	}
	return 0;
}