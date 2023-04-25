#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

typedef struct HangHoa{
	int stt;
    char mahang[6];
    char tenhang[20];
    int soluong;
    float dongia;
    float sotien;
}HangHoa;

HangHoa* read_DMHH(char* filename, int* count){
    FILE *infile = fopen(filename, "rb");
    HangHoa hhA;
    HangHoa *dmhh;
    int i = 0;

    dmhh = malloc(sizeof(HangHoa)*MAX_SIZE);
    dmhh[i] = hhA;

	fread(&hhA, sizeof(HangHoa), 1, infile );
	
	printf("%5s %10s %15s %10s %20s %20s\n", "STT", "MA HANG", "TEN HANG", "SO LG", "DON GIA", "SO TIEN");
	while(!feof(infile))
	{	
		printf("%5d %10s %15s %10d %20.2f %20.2f\n", hhA.stt, hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);	
		fread(&hhA, sizeof(HangHoa), 1, infile );
        i++;
        dmhh[i] = hhA;
	}

	fclose(infile);

    *count = i;
    return dmhh;
}

int main()
{
	HangHoa hh1 = {1, "A1010", "tra sua", 100, 5000, 500000};
    HangHoa hh2 = {2, "A1011", "tra dao", 100, 2500, 250000};
    HangHoa hh3 = {3, "A1012", "hong tra", 100, 8500, 850000};
    HangHoa hh4 = {4, "A1013", "sua tuoi duong den", 100, 15000, 1500000};
	FILE* outfile = fopen("dmhh.dat", "w");
	
	fwrite(&hh1, sizeof(HangHoa), 1, outfile);
    fwrite(&hh2, sizeof(HangHoa), 1, outfile);
    fwrite(&hh3, sizeof(HangHoa), 1, outfile);
    fwrite(&hh4, sizeof(HangHoa), 1, outfile);
	
	fclose(outfile);
    
    int count;

    HangHoa* myhh = read_DMHH("dmhh.dat", &count);

    printf("\nDa nhap thanh cong %d hang hoa", count);
	return 0;
}






