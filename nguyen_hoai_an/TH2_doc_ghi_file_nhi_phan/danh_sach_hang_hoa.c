#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 1000

typedef struct{
    char mahang[10] ;
    char tenhang[30];
    int soluong;
    float gia;
    float thanhtien;
}Hanghoa;

Hanghoa * read_DMHH(char* filename, int *n)
{
    Hanghoa*  hh_array;
    
    hh_array = malloc(MAX_AMOUNT* sizeof(Hanghoa));
    
    FILE *infile = fopen(filename, "rb");
	Hanghoa hhA;
	int count = 0;
	
	printf("%10s %20s %15s %25s %25s\n","Ma Hang","Ten hang","So luong","Don gia","So tien");	
 
	fread(&hhA, sizeof(Hanghoa), 1, infile);
	hh_array[count] = hhA;


	while(!feof(infile))
	{	
		printf("%10s %20s %15d %25f %25f\n",hhA.mahang,hhA.tenhang,hhA.soluong,hhA.gia,hhA.thanhtien);	
		
		count++;
		fread(&hhA, sizeof(Hanghoa), 1, infile);   
        hh_array[count]=hhA;
	}
	
	fclose(infile);
	*n = count;
    return hh_array;
}

void print_DMHH(Hanghoa* hh, int n)
{
	printf("%10s %20s %20s %20s %20s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s %20s %15d %25f %25f\n",hh[i].mahang,hh[i].tenhang,hh[i].soluong,hh[i].gia,hh[i].thanhtien);	
	}
}

void input_DMHH(char* filename)
{
	int count;

}

int main()
{
	Hanghoa h1 = {"A0101","Sua Co gai Ha Lan", 10, 20000, 200000};
    Hanghoa h2 = {"B0101", "Sua Ong Tho", 15, 10000, 150000};

	FILE* outfile = fopen("DMHH.DAT", "wb");
	
	fwrite(&h1, sizeof(Hanghoa), 1, outfile);
	fwrite(&h2, sizeof(Hanghoa), 1, outfile);
 
	
	if (fwrite!=0)
		printf("Mo file thanh cong\n");
	else
		printf("ERROR!\n");
	fclose(outfile);   

    int n;
    Hanghoa* mydmhh = read_DMHH( "DMHH.DAT", &n);
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;
}
