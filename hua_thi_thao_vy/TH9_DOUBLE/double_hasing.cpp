#include <stdio.h>

#define TABLE_SIZE 10

int hash1(int key) 
{
    return key % TABLE_SIZE;
}

int hash2(int key) 
{
    return 7 - (key % 7);
}

int doubleHashing(int key, int attempt) 
{
    return (hash1(key) + attempt * hash2(key)) % TABLE_SIZE;
}

void insert(int table[], int key) 
{
    int attempt = 0;
    int index;
	printf("Thu chen  = %d\n", key);
    do {
        index = doubleHashing(key, attempt);
        printf("  Index = %d\n", index);
        if (table[index] == -1) 
		{
            table[index] = key;
            break;
        }
        attempt++;
    } while (attempt < TABLE_SIZE);

    if (attempt == TABLE_SIZE) {
        printf("Bang bam day. Khong the chen gia tri %d.\n", key);
    }
}

void printHashTable(int table[]) 
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

int main() 
{
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        hashTable[i] = -1;
    }

    insert(hashTable, 12);
    insert(hashTable, 4);
    insert(hashTable, 26);
    insert(hashTable, 10);
    insert(hashTable, 97);
    insert(hashTable, 9);

    printHashTable(hashTable);

    return 0;
}
