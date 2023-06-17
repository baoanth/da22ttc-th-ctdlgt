#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct{
    char mahang[5] ;
    char tenhang[20];
    int sl;
    float dg;
    float st;
}HangHoa;


HangHoa * read_DMHH(char* filename, int *n)
{
    HangHoa*  hh_array;
    
    hh_array =  malloc(MAX* sizeof(HangHoa));
    
    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int dem =0;
	
	printf("%10s | %20s | %10s | %10s | %10s\n", "MA HANG" ,"TEN HANG", "SO LUONG", "DON GIA", "SO TIEN");
	
	fread(&hhA, sizeof(HangHoa), 1, infile );
	hh_array[dem]=hhA;

	while(!feof(infile))
	{	
		printf("%10s | %20s | %10d | %10.f | %10.f\n", hhA.mahang, hhA.tenhang, hhA.sl, hhA.dg, hhA.st);	
			
		dem++;
		fread(&hhA, sizeof(HangHoa), 1, infile );        
        hh_array[dem]=hhA;
	}
		
	fclose(infile);
	*n = dem;
    return hh_array;
}

void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s | %20s | %10s | %10s | %10s\n","MA HANG" ,"TEN HANG", "SO LUONG", "DON GIA", "SO TIEN");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s | %20s | %10d | %10.f | %10.f\n", hh[i].mahang, hh[i].tenhang, hh[i].sl, hh[i].dg, hh[i].st);	
	}
}


void input_DMHH(char* filename)
{
	int dem;		
}

int main()
{
	HangHoa h1 = {"A001", "Con Meo mau hong", 5, 20000, 100000};
    HangHoa h2 = {"A002", "Con Meo mau den", 2, 30000, 60000};
    HangHoa h3 = {"A003", "Con Meo mau lam", 7, 20000, 140000};
	FILE* outfile = fopen("DMHH.DAT", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("Ghi tep thanh cong\n");
	else
		printf("Loi! Ghi tep khong thanh cong\n");
	fclose(outfile);   

    int n=0;
    HangHoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;

}
