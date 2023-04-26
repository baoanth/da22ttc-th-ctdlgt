
#include <stdio.h>
#include <stdlib.h>
#define max_amount 100

struct Hanghoa
{
    int sl;
    char mh[50];
    char tenhang[50];
    float dg;
    float st;

}Hanghoa ;
HangHoa* read_DMHH(char* filename, int *n){
	Hanghoa* hh_array[max_amount];
	hh_array= malloc(max_amount*sizeof(Hanghoa));
	FILE* infile = fopen(filename,"rb");
	Hanghoa hhA;
	int count =0;
	
	printf("%5s%12s%8s%12s%12s\n","Ma Hang","Ten hang"," So luong","Don gia","So tien");
    fread(&hhA, sizeof(HangHoa),1,infile);
    hh_array[count]=hhA;
	
	while (!feof(infile)){
		
		printf("%5d%12s%8d%12s%12s\n", hhA.mh , hhA.tenhang, hhA.sl, hhA.dg, hhA.st);
		fread(&hhA, sizeof(HangHoa),1,infile);
		 hh_array[count]=hhA;
	}
	fclose(infile);
	
}
