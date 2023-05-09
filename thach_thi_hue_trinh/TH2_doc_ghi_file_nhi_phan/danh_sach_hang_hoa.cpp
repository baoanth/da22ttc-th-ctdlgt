#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct{
    char mahang[5] ;
    char tenhang[20];
    int sl;
    float dg;
    float tt;
}HangHoa;


HangHoa * read_DMHH(char* filename, int *n)
{
    HangHoa*  hh_array;

    hh_array =(HangHoa*)  malloc(MAX* sizeof(HangHoa));

    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int dem =0;

	printf("%10s | %20s | %10s | %10s | %10s\n", "MA HANG" ,"TEN HANG", "SO LUONG", "DON GIA", "THANH TIEN");

	fread(&hhA, sizeof(HangHoa), 1, infile );
	hh_array[dem]=hhA;

	while(!feof(infile))
	{	
		printf("%10s | %20s | %10d | %10.0f | %10.3f\n", hhA.mahang, hhA.tenhang, hhA.sl, hhA.dg, hhA.tt);	

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
	printf("%10s | %20s | %10s | %10s | %10s\n","MA HANG" ,"TEN HANG", "SO LUONG", "DON GIA", "THANH TIEN");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s | %20s | %10d | %10.0f | %10.3f\n", hh[i].mahang, hh[i].tenhang, hh[i].sl, hh[i].dg, hh[i].tt);	
	}
}


void input_DMHH(char* filename)
{
	int dem;		
}

int main()
{
	HangHoa h1 = {"A001", "Meo Ai cap", 5, 10, 50 };
    HangHoa h2 = {"A002", "Meo Anh long ngan", 2, 30, 60 };
    HangHoa h3 = {"A003", "Meo Han Quoc", 7, 20, 140};
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
