#include <stdio.h>

#define TABLE_SIZE 29

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int table[], int key) {
    printf("Key = %d\n", key);
    int index = hash(key);
    printf("    Index1 = %d\n", index);
    
    int i = 0;

    while (table[index] != -1) {
        i++;
        index = (hash(key) + i * i) % TABLE_SIZE;
        printf("    Index%d = %d\n",i+1, index);
        if (i >= TABLE_SIZE) {
            printf("Bang bam day. Khong the chen gia tri %d.\n", key);
            return;
        }
    }

    table[index] = key;
}

void printHashTable(int table[]) {
    printf("Bang bam:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1) {
            printf("[%d]: %d\n", i, table[i]);
        } else {
            printf("[%d]: __\n", i);
        }
    }
}

int main() {
    int hashTable[TABLE_SIZE];

    // Kh?i t?o b?ng bam
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Chèn giá tr? vào b?ng bam
    insert(hashTable, 6);
    insert(hashTable, 14);
    insert(hashTable, 22);
    insert(hashTable, 30);
    insert(hashTable, 12);
    insert(hashTable, 32);
    insert(hashTable, 61);

    // In b?ng bam
    printHashTable(hashTable);

    return 0;
}
