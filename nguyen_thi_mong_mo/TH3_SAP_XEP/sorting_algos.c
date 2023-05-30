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
	j = 2 * i + 1; // (ai , aj ), (ai , aj+1) l� c�c ph?n t? li�n d?i
	x = a[i];
	while (j <= r)
	{
		if (j < r) // n?u c� d? 2 ph?n t? li�n d?i
			if (a[j] < a[j + 1])
				// x�c d?nh ph?n t? li�n d?i l?n nh?t
				j = j + 1;
		if (a[j] < x)
			break; // tho? quan h? li�n d?i, d?ng
		else
		{
			a[i] = a[j];
			i = j;
			// x�t ti?p kh? nang hi?u ch?nh lan truy?n
			j = 2 * i + 1;
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
	CreateHeap(a, n - 1);

	printf("\n ==========Heap===========\n");
	print_array(a, n);
	printf(" =========================\n");

	r = n - 1; // r là vị trí đúng cho phần tử nhỏ nhất

	while (r > 0)
	{
		hoan_vi(&a[0], &a[r]);
		r = r - 1;
		Shift(a, 0, r);
		print_array(a, n);
	}
}

void QuickSort(int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l + r) / 2]; // ch?n ph?n t? gi?a l�m gi� tr? m?c
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
			printf("Hoan vi %4d <--> %2d", a[i], a[j]);
			hoan_vi(&a[i], &a[j]);						
			print_array(a, N);
			i++;
			j--;
		}
	} 
	while (i < j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
}

int main()
{
	int my_arr[] = {6, 7, 8, 4, 15, 23, 11, 27, 17, 50, 22, 66};

	print_array(my_arr, N);
	printf("1. Selection sort\n");
<<<<<<< HEAD
	printf("2. Heap sort\n");
	printf("3. Quick sort\n");
	// SelectionSort(my_arr, N);
	//HeapSort(my_arr, N);
	QuickSort(my_arr, 0, N);
=======
	printf("2. Insertiontion sort\n");
	printf("3. Interchange sort\n");
	printf("4. Bubble sort\n");
	printf("5. Heap sort\n");
	printf("6. Quick sort\n");
	int chon = 1;
	

	while (1)
	{
		printf("Nhap lua chon cua ban, nhap 0 de THOAT: ");
		scanf("%d", &chon);
		if (!chon)
			break;
		switch (chon)
		{
		case 1:
			printf("\n***Selection Sort Begin***\n");
			SelectionSort(my_arr, N);
			printf("\n***Selection Sort End***\n");
			break;

		case 5:
			printf("\n***Heap Sort Begin***\n");
			HeapSort(my_arr, N);
			printf("\n***Heap Sort End***\n");

		default:
			break;
		}
	}

>>>>>>> af61a97d66a90c9125b7556c4febe2cd2840c984
	return 0;
}
// SelectionSort(my_arr, N);
// HeapSort(my_arr, N);
