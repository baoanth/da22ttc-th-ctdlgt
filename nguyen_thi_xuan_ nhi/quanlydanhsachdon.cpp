#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int mssv;
    char hoten[100];
    int tuoi;
    float dtb;
    struct student *next;
}student;
typedef struct danhsachsinhvien
{
    student *head;
    int size;
}danhsachsinhvien;
void khoitao_dssv(danhsachsinhvien *ds)
{
    ds->head = NULL;
    ds->size = 0; 
}

void addstduent(danhsachsinhvien)