#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char mahang[5];
    int soluong;
    float dongia;
    float sotien;
}hanghoa;
hanghoa[] read_DMHH(char*filename)
{ hanghoa hh;
    file*infile=fopen(filename,"rb");
    printf("5s%7s%8s%4s%8s\n","ma hang","ten hang","so lung","don gia");
    fread(&hh,sizeof(hanghoa),1,infile);
    while(!feof(infile))
    {
        printf("5s%7s%8s%4s%8s\n",hh.mahang,hh.tenhang);
        fread(&hh,sizeof(hanghoa),1,infile);
    }
    fclose(infile);
}void print_DMHH(Hanghoa* hh, int n)
{

	printf("%5s%15s%15s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%15s%15d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].sotien);	
	}
}
void print_HH(Hanghoa hh)
{
	printf("%5s%15s%15d%12f%12f\n", hh.mahang, hh.tenhang, hh.soluong, hh.dongia, hh.sotien);
}	

    