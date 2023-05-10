#include<stdio.h>
#include<stdio.h>
#define MAX 200
typedef struct {
    char mahang[10]
    char tenhang[20]
    int sl;
    float dg;
    float st;

} HangHoa;
HangHoa read_DMHH(char filename, int *n)
{
    HangHoa hh_array
    hh_array = malloc(max sizeo(fhanghoa));
    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int dem =0;
    printf("%10s | %20s | %10s | %10sN GIA | %10s\n", "MA HANG" ,"TEN HANG", "SO LUONG", "DO", "SO TIEN");
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
    HangHoa h1 {"A001","iphone 12",5, 30000, 200000};
    HangHoa h2 {"A002","iphone13",3, 2000, 40000};
    HangHoa h3 {"A003","iphone14 pro",4 5000, 7500};

        fwrite(&h1, sizeof(HangHoa), 1, outfile);
        fwrite(&h2, sizeof(HangHoa),1, outfile);
        fwrite(&h3, sizeof(HangHoa),1 , outfile);


}
