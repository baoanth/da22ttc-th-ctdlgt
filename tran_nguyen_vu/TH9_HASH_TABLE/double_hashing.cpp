#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

#define TABLE_SIZE 10

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int hash1(int key)
{
    return key % TABLE_SIZE;
}

int hash2(int key)
{
    return 7 - (key % 7);
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

int doubleHashing(int key, int attempt)
{
    return (hash1(key) + attempt * hash2(key)) % TABLE_SIZE;
}
void bang_bam(int key, int index)
{
    int y = 1;
    do
    {

        gotoxy(9, y);
        printf("<- %d", key);
        usleep(100000);
        if ((y - 1) == index)
            break;
        gotoxy(9, y);
        for (int i = 0; i < 10; i++)
            printf(" ");
        y++;

    } while ((y - 1) != index || y < TABLE_SIZE);
    if (y == TABLE_SIZE+1)
    {
        gotoxy(0, 12);
        printf("Bang bam day. Khong the chen %d.\n", key);
        sleep(3);
    }
}

void insert(int table[], int key)
{
    int attempt = 0;
    int index;
    system("cls");
    printf("Thu chen  = %d\n", key);
    usleep(100000);
    do
    {
        system("cls");
        printHashTable(table);
        index = doubleHashing(key, attempt);
        // printf("  Index = %d\n", index);
        if (table[index] == -1)
        {
            table[index] = key;
            bang_bam(key, index);
            system("cls");
            printHashTable(table);
            usleep(100000);
            break;
        }
        attempt++;
    } while (attempt < TABLE_SIZE);

    if (attempt == TABLE_SIZE)
    {
        printf("Bang bam day. Khong the chen %d.\n", key);
        bang_bam(key, index);
    }
}

int main()
{
    int hashTable[TABLE_SIZE];

    // Kh?i t?o b?ng bam
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
    srand((int)time(0));
    // Ch�n gi� tr? v�o b?ng bam
    // insert(hashTable, 4);
    // insert(hashTable, 14);
    // insert(hashTable, 24);
    // insert(hashTable, 34);
    // insert(hashTable, 44);
    // insert(hashTable, 54);
    // insert(hashTable, 64);
    // insert(hashTable, 74);
    // insert(hashTable, 15);

    for (int i = 0; i < 10; i++)
    {
        int gia_tri = random(1, 100);
        insert(hashTable, gia_tri);
    }
    // In b?ng 
    system("cls");
    printHashTable(hashTable);

    return 0;
}
