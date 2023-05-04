#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void print_array(int arr[], int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void insertion_sort(int arr[], int len) {
    int i, key, j;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int len) {
    int i, j, min_idx;
    for (i = 0; i < len - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void interchange_sort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubble_sort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int my_array[N];
    srand(time(NULL));

   
    for (int i = 0; i < N; i++) {
        my_array[i] = rand() % 100;
    }

    printf("Mang ban dau: ");
    print_array(my_array, N);

    printf("\n1. Insertion sort\n");
    printf("2. Selection sort\n");
    printf("3. Interchange sort\n");
    printf("4. Bubble sort\n");
    printf("0. Thoat\n");

    int choice;
    do 
	{
        printf("\nChon thu tu sap xep (0-4): ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                insertion_sort(my_array, N);
                printf("Mang sau khi sap xep bang Insertion sort: ");
                print_array(my_array, N);
                break;
            case 2:
                selection_sort(my_array, N);
                printf("Mang sau khi sap xep bang Selection sort: ");
                print_array(my_array, N);
                break;
            case 3:
                interchange_sort(my_array, N);
                printf("Mang sau khi sap xep bang Interchange sort: ");
                print_array(my_array, N);
                break;
            case 4:
			    bubble_sort(my_array, N);
				printf("Mang sau khi sap xep bang Bubble Sort: ");
				print_array(my_array, N);
				break;
			case 0:
			    printf("Thoat chuong trinh...\n");
				break;
			
			    printf("khong co lua chon nay! Nhap lai! \n");
	    }
    } while (choice !=0);
    
    return 0;
}

