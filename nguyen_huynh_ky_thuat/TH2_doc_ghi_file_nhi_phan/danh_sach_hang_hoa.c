#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200

typedef struct{
	
	char mahang[10];
	char tenhang[50];
	int soluong;
	float gia;
	float thanhtien;
}HangHoa;

HangHoa * read_DMHH(char* filename, int *n)
{
	HangHoa* hh_array;
	
	hh_array = malloc(MAX_AMOUNT* sizeof(HangHoa));
	
	FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int count =0;
	printf("%15s%20s%10s%12s%12s\n","Ma Hang","Ten Hang","So Luong","Don Gia","So Tien");
	fread(&hhA, sizeof(HangHoa),1,infile);
	hh_array[count]=hhA;
	
	
	
	while(!feof(infile))
	{
		printf("%15s%20s%10s%12f%12f\n","Ma Hang","Ten Hang","So Luong","Don Gia","So Tien");
		count++;
		fread(&hhA, sizeof(HangHoa),1, infile);
		hh_array[count]=hhA;
	}
	
	fclose(infile);
	*n = count;
	return hh_array;

}


void input_DMHH(char* filename)
{
	int count;
	
}

int main()
{


	HangHoa h1 = {"A001", "Sach English", 1, 10, 100};
    HangHoa h2 = {"A002", "May Tinh Casio", 2, 20, 200};
    HangHoa h3 = {"A003", "Ao So Mi", 5, 1000, 5000};
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
	printf_DMHH(mydmhh, n);
	return 0;

}


