// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 1000

typedef struct{
    char mh[5] ;
    char th[20];
    int sl;
    float dg;
    float st;
}HangHoa;


HangHoa * read_DMHH(char* filename, int *n)
{
    HangHoa*  dmhh;
    
    dmhh =  malloc(sizeof(HangHoa)*MAX_AMOUNT);
    
    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int count =0;
	
	printf("%15s%20s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	fread(&hhA, sizeof(HangHoa), 1, infile );
	dmhh[count]=hhA;

	while(!feof(infile))
	{
		printf("%15s%20s%10d%12.2f%12.2f\n", hhA.mh, hhA.th, hhA.sl, hhA.dg, hhA.st);			
		count++;
		fread(&hhA, sizeof(HangHoa), 1, infile );        
        dmhh[count]=hhA;
	}
	
	fclose(infile);
	*n = count;
    return dmhh;
}


void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s%25s%10d%12.2f%12.2f\n", hh[i].mh, hh[i].th, hh[i].sl, hh[i].dg, hh[i].st);	
	}
}


void input_DMHH(char* filename)
{
	int count;
	
}



int main()
{

	HangHoa h1 = {"A001", "Book", 10, 10000, 100000};
    HangHoa h2 = {"A002", "Pen", 5, 5000, 25000};
    HangHoa h3 = {"A003", "NoteBook", 10, 1000, 100000};
	FILE* outfile = fopen("DMHH.dat", "wb");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("Ghi thanh cong\n");
	else
		printf("LOI! Ghi khong thanh cong\n");
	fclose(outfile);   

    int n;
    HangHoa* mydmhh=  read_DMHH( "DMHH.dat", &n );
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;

}
