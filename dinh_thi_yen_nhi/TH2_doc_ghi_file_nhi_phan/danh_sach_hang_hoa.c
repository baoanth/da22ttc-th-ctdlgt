// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200;

typedef struct 
{
	char mahang[2];
	char tenhang[20];
	int soluong;
	float gia;
	float thanhtien;
} Hanghoa;

Hanghoa* read_DMHH(char* filename, int *n);
{
	Hanghoa* hh_array;
	hh_array = malloc(MAX_MOUNT* sizeof(Hanghoa));
	FILE* infile = fopen(filename, "rb");
	Hanghoa hhA;
	int count =0; 
	
	printf ("%5s%20s%13s%20s%20s\n", "Ma hang", "Ten hang ", "So luong", "Don gia", "Thanh tien");
	fread(&hhA, sizeof(Hanghoa), 1, infile);
	hh_array[count] = hhA;
	
	while (!feof(infile))
	{
		printf ("5s%20s%13d%20f%20f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hhA.thanhtien);
		count++;
		
	    fread(&hhA,sizeof(Hanghoa),1,infile);
	    n++;
	} 
	printf ("Danh sach co %d hang hoa")
	fclose (infile);
	return hh_array;

}

int main ()
{
	Hanghoa h1 = ("01","sushi","6", "10","60");
	Hanghoa h2 = ("02","dau tay","8", "10","80");
	Hanghoa h3 = ("03","dua hau","3", "10","30");
	FILE*outfile = fopen("DMHH.DAT", "w");
	fwrite (&h1, sizeof(Hanghoa), 1, outfile );
	fwrite (&h2, sizeof(Hanghoa), 1, outfile );
	fwrite (&h3, sizeof(Hanghoa), 1, outfile );
	
	
	if (fwrite!=0) 
		printf ("write file surcessfully");
		else printf ("error. write file unsurcessfully");
	fclose (outfile);
	int n=0; 
	Hanghoa* mydmhh = read_DMHH("DMHH.DAT", &n);
	printf ("\n Danh muc hang hoa tren co %d mon hang\n", n);
	printf _DMHH(mydmhh)




