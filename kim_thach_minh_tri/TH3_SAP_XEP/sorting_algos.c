#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int a[],int n)
{
    int min;
    for (int i=0, i<n-1, i++)
    {
        min = i;
        for (int j = i+1; j<n; j++)
        if (a[j] < a[min]
		{
			 min = j;
        }
        
        Hoanvi(a[min], a[i]);
    }
}

int main()
{
	
	return 0;
}
