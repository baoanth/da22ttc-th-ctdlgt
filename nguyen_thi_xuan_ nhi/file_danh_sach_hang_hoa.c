#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char mh[5];
    int sl;
    float dg;
    float st;
}hanghoa;
hanghoa[] read_DMHH(char*filename)
{ hanghoa hh;
    file*infile=fopen(filename,"rb");
    printf("5s%7s%8s%4s%8s\n","ma hang","ten hang","so lung","don gia");
    fread(&hh,sizeof(hanghoa),1,infile);
    while(!feof(infile))
    {
        printf("5s%7s%8s%4s%8s\n",hh.mh,hh.tenhang);
        fread(&hh,sizeof(hanghoa),1,infile);
    }
    fclose(infile);
}