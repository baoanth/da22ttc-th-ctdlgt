#include <stdio.h>
#include<stdlib.h>
typedef struct 
{
    char[5] mh;
    char[10];
    int sl;
    float dg;
    float st;
    float tenhang;
}HangHoa;

HangHoa[] read_DMHH(char* filename)
{

    file *infile=fopen(filename,"rb");
    HangHoa hhA;
    n=0;
    printf("%8s%10s%7s%12s\n","mahang","dongia","soluong","sotien","tenhang");
    fread(&hhA,sizeof(hanghoa),1,infile);
    HH array[n]=hhA;
    while(!feof(infile))
     {
	    printf("%10s%12s%8d%14f%16f\n",hhA.mahang,hhA.soluong,hhA.dongia,hhA.sotien,hhA.tenhang);
	    fread(&hhA,sizeof(HangHoa),1,infile);
        n++;
      }
    fclose(infile);
    return hh_array;
}
