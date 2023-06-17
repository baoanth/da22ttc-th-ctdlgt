#include <stdio.h>

#define TABLE_SIZE 29

int Hash(int key) 
{
    return key % TABLE_SIZE;
}

void Insert(int table[], int key) 
{
    printf("Key = %d\n", key);
    int index = Hash(key);
    printf("    Index1 = %d\n", index);
    
    int i = 0;

    while (table[index] != -1) 
	{
        i++;
        index = (Hash(key) + i * i) % TABLE_SIZE;
        printf("    Index%d = %d\n",i+1, index);
        if (i >= TABLE_SIZE) 
		{
            printf("Bang bam day. Khong the chen gia tri %d.\n", key);
            return;
        }
    }

    table[index] = key;
}

void Print_Hash_Table(int table[]) 
{
    printf("Bang bam:\n");
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        if (table[i] != -1) 
		{
            printf("[%d]: %d\n", i, table[i]);
        } 
		else 
		{
            printf("[%d]: __\n", i);
        }
    }
}

//Viet ham main
int main() 
{
    int Hash_Table[TABLE_SIZE];

    // Khoi tao bang bam
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        Hash_Table[i] = -1;
    }



	int k;
	
//Dieu kien de chay chuong trinh
	do
	{
    	printf("Ban muon nhap bao nhieu gia tri: ");
		scanf("%d", &k);
	
    	if(k<=0)     
			printf("Ban da nhap sai. Yeu cau ban nhap vao so duong de chuong trinh chay.\n\n");
    }while(k<=0);
	
	for(int i = 1; i<=k; i++)
	{	
		int tmp;
		printf("Nhap vao gia tri thu %d: ", i);
		scanf("%d", &tmp);
		Insert(Hash_Table, tmp);
	}
	











    //Chen gia tri vao bang bam
//    Insert(Hash_Table, 32);//3
//    Insert(Hash_Table, 61);//3  4
//    Insert(Hash_Table, 90);//3  7    3+2^2
//    Insert(Hash_Table, 119);//3  12    3+3^2
//    Insert(Hash_Table, 148);//3  19   3+4^2
//    Insert(Hash_Table, 177);//3  28    3+5^2
//    Insert(Hash_Table, 206);//3  39--->10      (3+6^2)(mod29)

    // In bang bam
    Print_Hash_Table(Hash_Table);

    return 0;
}

