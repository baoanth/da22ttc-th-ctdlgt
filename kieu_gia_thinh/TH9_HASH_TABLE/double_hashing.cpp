#include <stdio.h>

#define TABLE_SIZE 10

//Viet ham hash1(int key)
int Hash1(int key) 
{
    return key % TABLE_SIZE;
}

////Viet ham hash2(int key)
int Hash2(int key) 
{
    return 7 - (key % 7);
}


int Double_Hashing(int key, int attempt) 
{
    return (Hash1(key) + attempt * Hash2(key)) % TABLE_SIZE;
	//Vi so lon qua co the bi tran Table. Nen mod10 de khong tran ra ngoai Table
}

//Viet ham void Insert
void Insert(int table[], int key) 
{
    int attempt = 0;
    int index;
    
	printf("Thu chen  = %d\n", key);
	
    do 
	{
        index = Double_Hashing(key, attempt);
        printf("  Index = %d\n", index);
        if (table[index] == -1) {
            table[index] = key;
            break;
        }
        attempt++;
    } while (attempt < TABLE_SIZE);

    if (attempt == TABLE_SIZE) 
	{
        printf("Bang bam day. Khong he chen gia tri %d.\n", key);
    }
}

//Viet ham In
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

    //Khoi tao bang bam
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
//    Insert(Hash_Table, 4);
//    Insert(Hash_Table, 14);
//    Insert(Hash_Table, 24);
//    Insert(Hash_Table, 34);
//    Insert(Hash_Table, 44);
//    Insert(Hash_Table, 54);
//	  Insert(Hash_Table, 64);
//	  Insert(Hash_Table, 74);
//	  Insert(Hash_Table, 15);
    // In bang bam
    Print_Hash_Table(Hash_Table);

    return 0;
}
