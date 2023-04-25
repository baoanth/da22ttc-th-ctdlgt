// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200

typedef struct{
    char mahang[5] ;
    char tenhang[20];
    int soluong;
    float gia;
    float giatien;
}HangHoa;

HangHoa * read_DMHH(char* filename, int *n)
{
    HangHoa*  hh_array;
    
    hh_array =  malloc(MAX_AMOUNT* sizeof(HangHoa));
    
    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int count =0;
	
	printf("%15s%20s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	

	fread(&hhA, sizeof(HangHoa), 1, infile );
	hh_array[count]=hhA;

	while(!feof(infile))
	{	
		printf("%15s%20s%10d%12f%12f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hhA.giatien);	
			
		count++;
		fread(&hhA, sizeof(HangHoa), 1, infile );        
        hh_array[count]=hhA;
	}
	
	fclose(infile);
	*n = count;
    return hh_array;
}

void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s%25s%10d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].gia, hh[i].giatien);	
	}
}


void input_DMHH(char* filename)
{
	int count;
	
}

int main()
{


	HangHoa h1 = {"A001", "Iphone x", 5, 300, 2500};
    HangHoa h2 = {"A002", "Iphone 13", 5, 700, 5500};
    HangHoa h3 = {"A003", "Iphone 15", 5, 5000, 5000};
	FILE* outfile = fopen("DMHH.DAT", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("Write file successfully\n");
	else
		printf("ERROR! Write file unsuccessfully\n");
	fclose(outfile);   

    int n=0;
    HangHoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;

}


