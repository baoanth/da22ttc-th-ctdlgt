// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#define MAX_ANOUNT 200;

 typedef struct
 {
 	char mahang[20];
 	char tenhang[20];
 	int soluong;
 	float gia;
 	float thanhtien;
 } Hanghoa;
   
	Hanghoa* read_DMHH (char* filname, int n);
	{
		Hanghoa hh array[MAX_DMHH]
		FILE* infile = fopen(filname, "rb");
		Hanghoa hhA;
		n=0
		
    printf("%5s%20s%13s%13s%13s\n","mahang" ,"tenhang" ,"soluong" , "gia", "thanhtien");
    fread(&hhA, sizeof(Hanghoa),1, infile);
    
	while(!feof(infile))
	{
		 printf("%5d%20s%13d%13f%13f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hha.thanhtien);
		  fread(&hhA, sizeof(Hanghoa),1, infile);
		  n++;
		  
	}
	printf("danh sach co %d hang hoa");
	fclose (infile);
	return hh_array;
}
int main()
{
	Hanghoa h1 = ("01", "xoai", "5", "10", "50");
	Hanghoa h2 = ("02", "xoai", "5", "10", "50");
	Hanghoa h3 = ("03", "xoai", "5", "10", "50");
}

	

