#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student 
{int msv;
char hovaten[100];
int tuoi;
float dtb;
struct Student *next;
}student;


void addstudentvoid (*sv)
{
    SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
    printf("Nhap ma so sinh vien: ");
    scant("%d",&sv->msv);
    printf("Nhap ten sinh vien: ");
    scant("%d",&sv->hovaten);
    printf("Nhap tuoi sinh vien: ");
    scant("%d",&sv->tuoi);
    printf("Nhap diem: ");
    scant("%f",&sv->dtb);
    sv->next=NUL
}return 0;






    

