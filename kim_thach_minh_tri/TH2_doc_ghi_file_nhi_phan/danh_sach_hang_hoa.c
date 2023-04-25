#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HangHoa
{
    char mh[5];
    int sl;
    float dg;
    float st;
};

HangHoa[] read_DMHH(char *filename)
{
    FILE *f = fopen ()
}

int main()
{
    struct HangHoa mh1 = ("A0101");
    struct HangHoa mh2 = ("B0101");

    printf("Nhap ma hang: ");
    gets(hanghoa.mh);
    printf("Nhap so luong: ");
    scanf("%d",hanghoa.sl);
    printf("Nhap don gia: ");
    scanf("%d",hanghoa.dg);
    hanghoa.st= hanghoa.sl*hanghoa.dg;
    printf("So tien: %d",hanghoa.st);

    
    return 0;
}