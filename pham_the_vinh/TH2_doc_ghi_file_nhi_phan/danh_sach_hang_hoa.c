#include <stdio.h>
#include <stdlib.h>
#define MaxAmount 1000

typedef struct
{
    char mahang[10] ;
    char tenhang[20];
    int soluong;
    float dongia;
    float sotien;
}HangHoa;

HangHoa *read_DMHH(char* filename, int *n)
{
    HangHoa *dmhh = malloc(MaxAmount* sizeof(HangHoa));
    
    FILE *infile = fopen(filename, "rb");

	HangHoa hhA;

	int count =0;
	
	printf("%10s%25s%15s%15s%15s\n","MA HANG", "TEN HANG", "SO LUONG", "DON GIA", "SO TIEN");	

	fread(&hhA, sizeof(HangHoa), 1, infile);

	dmhh[count]=hhA;

	while(!feof(infile))
	{	
		printf("%10s%25s%15d%15f%15f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);	

		count++;
		
		fread(&hhA, sizeof(HangHoa), 1, infile);   

        dmhh[count]=hhA;
	}
	
	fclose(infile);

	*n = count;

    return dmhh;
}

void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%15s%15s%15s\n","MA HANG", "TEN HANG", "SO LUONG", "DON GIA", "SO TIEN");	

	int i;

	for (i=0; i<n; i++)
	{
		printf("%10s%25s%15d%15f%15f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].sotien);	
	}
}

HangHoa find_HH_by_ma(char* mahang, HangHoa* dmhh)
{


}

void input_DMHH(char* filename)
{
	int count;	
}

int main()
{
	HangHoa hh1 = {"A0001", "But chi", 5, 2000, 10000};
	HangHoa hh2 = {"A0002", "But muc", 10, 5000, 50000};
	HangHoa hh3 = {"A0003", "But long", 20, 10000, 200000};
	
	FILE* outfile = fopen("DMHH.dat", "wb");
	
	fwrite(&hh1, sizeof(HangHoa), 1, outfile);
	fwrite(&hh2, sizeof(HangHoa), 1, outfile);
	fwrite(&hh3, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("--- Ghi file thanh cong ---\n");
	else
		printf("--- Loi. Ghi file khong thanh cong ---\n");
	fclose(outfile);   

    int n=0;

    HangHoa* mydmhh=  read_DMHH( "DMHH.dat", &n);
	
	printf("\n\nDanh sach co %d mon hang\n", n);	

	print_DMHH(mydmhh, n);

	return 0;
}
