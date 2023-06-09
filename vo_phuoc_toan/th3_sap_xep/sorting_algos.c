#include<bits/stdc++.h>

using namespace std;

void swap(int &a , int &b)
{
    int tam = a;
    a = b;
    b = tam;
}

void in(int a[100],int n)
{
    for(int i = 0; i< n; i++)
	{
        cout << a[i] << " ";

    }
    cout<< "\n";
}

void in1(int a[100],int n)
{
    for(int i = 1; i<= n; i++)
	{
        cout << a[i] << " ";

    }
    cout<< "\n";
}
void nhap (int a[100],int n){
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
}

void selectionSort(int a[100],int n)
{
    int min ;
    for(int i = 0; i< n; i++)
	{
        for(int j = i+1; j < n; j++)
		{
            min = i;
            if(a[j] < a[min])
			{
                min = j;
            }
            swap(a[i],a[min]);
            in(a,n);
        }
    }

}

void insertionSort(int a[100], int n)
{
    int pos = 0, x;
    for(int i = 1; i<n;i++)
	{
        x = a[i];
        pos = i-1;
        while(pos >=0 && a[pos] > x)
		{
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
        in(a,n);
    }

}

void interchangeSort(int a[100],int n)
{
	for(int i = 0; i< n; i++)
	{
		for(int j = i+1 ;j< n;j++)
		{
			if(a[i] > a[j])
			{
				swap(a[i],a[j]);
				
			}
		}
		in(a,n);
	}
}

void bubbleSort(int a[100],int n)
{
	for(int i = 0 ;i< n;i++)
	{
		for(int j = n -1;j>0;j--){
			if(a[j] < a[j-1])
			{
				swap(a[j],a[j-1]);
			}
			in(a,n);
		}	
	}	
}

void quickSort(int a[100], int l , int r,int n)
{
	int i, j, x;
	x = a[(l+r)/2];
	i = l; j = r;
	do
	{
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}while(i<j);
	if(l<j)
		quickSort(a,l,j,n);
	if(i<r)
		quickSort(a,i,r,n);
	in(a,n);
}

void Shift(int a[100], int l , int r)
{
	int x, i , j;
	i = l; 
	j = 2*i+1;
	x =a[i];

	while(j<=r)
	{	
		if(j<r)
			if(a[j]<a[j+1])
				j++;
			if(a[j]<x)
				break;
			else 
			{
				a[i] = a[j];
				i =j;
				j =2*i+1;
				a[i] = x;
			}		
	}
}

void CreHeap(int a[100], int n)
{
	int l = n/2;
	while(l>=0)
	{
		Shift(a,l,n);
		l--;
	}
}

void heapSort(int a[100], int n)
{
	CreHeap(a,n-1);
	in(a,n);
	printf("=====");
	int r = n-1;
	while(r>0)
	{
	//	printf("%d\n",r);
		swap(a[0],a[r]);
		in(a,n);
		r--;
		Shift(a,0,r);
	//	printf("%d\n",r);
	}
	//printf("ket thuc heapsort");
}

int main()
{
	int a[]={8,9,0,4,1,7,5,3,2,6};
	int n = 10;
	in(a,n);
	while(1)
	{
		int a[]={8,9,0,4,1,7,5,3,2,6}; 
    	int lc; 
		cout << "0. EXIT\n";
		cout << "1. sap xep chen truc tiep \n";
		cout << "2. sap xep chon truc tiep \n";
		cout << "3. sap xep doi cho truc tiep \n";
		cout << "4. sap xep noi bot \n";
		cout << "5. quickSort \n";
		cout << "6. HeapSort \n";
		cout << "-----------------------------------\n";
		cout << "moi chon chuc nang \n";
		cin>> lc;
		if(lc == 0)
		{
			break;
		}
		else if(lc == 1)
		{
		
			insertionSort(a,n);	
		}
		else if(lc == 2)
		{
		
			selectionSort(a,n);	
		}
		else if (lc == 3)
		{
		
			interchangeSort(a,n);
		}
		else if(lc == 4)
		{
    		bubbleSort(a,n);
		}
		else if(lc == 5)
		{
			quickSort(a,0,n-1,n);
			in(a,n);
		}
		else if (lc == 6)
		{
			heapSort(a,n);
		
		}
			
		
	}



    return 0;
}

