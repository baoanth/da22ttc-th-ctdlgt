#include <stdio.h>
#include <stdlib.h>

#define N 12

void print_array(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

void hoan_vi(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[], int n)
{
	int min; // chi so phan tu nho nhat trong day hien hanh
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j; // Ghi nhan vi tri phan tu nho nhat hien hanh
		hoan_vi(&a[min], &a[i]);
		print_array(a, n);
	}
}



void Shift(int a[], int l, int r)
{
	int x, i, j;
	i = l;
	j = 2 * i+1; // (ai , aj ), (ai , aj+1) là các phần tử liên đới
	x = a[i];
	while (j <= r)
	{
		if (j < r) // nếu có đủ 2 phần tử liên đới
			if (a[j] < a[j + 1])
				// xác định phần tử liên đới lớn nhất
				j = j + 1;
		if (a[j] < x)
			break; // thoả quan hệ liên đới, dừng
		else
		{
			a[i] = a[j];
			i = j;
			// xét tiếp khả năng hiệu chỉnh lan truyền
			j = 2 * i+1;
			a[i] = x;
		}
	}
}
void CreateHeap(int a[], int n)
{
	int l;
	l = n / 2; // a[l] là phần tử ghép thêm
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
	printf("\n===========Heap=========\n");
	print_array(a,n);
	printf("=======================\n");

	r = n-1; // r là vị trí đúng cho phần tử nhỏ nhất
	
	while (r > 0)
	{
		
		hoan_vi(&a[0], &a[r]);
		print_array(a,n);
		r = r - 1;
		Shift(a, 0, r);
	}
}
int main()
{
	int my_arr[] = {6, 7, 8, 4, 15, 23, 11, 27, 17, 50, 22, 66};
	print_array(my_arr, N);
	printf("1. Selection sort\n");
	printf("2. Heap sort\n");
	// SelectionSort(my_arr, N);
	HeapSort(my_arr, N);

	return 0;
}
