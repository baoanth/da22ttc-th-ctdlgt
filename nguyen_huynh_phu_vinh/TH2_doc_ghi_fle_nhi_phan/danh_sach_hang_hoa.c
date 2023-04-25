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
	HangHoa hh1 = {1, "A1010", "Ps1", 167, 2500, hh1.soluong*hh1.dongia};
    HangHoa hh2 = {2, "A1011", "Ps2", 286, 5000, hh2.soluong*hh2.dongia};
    HangHoa hh3 = {3, "A1012", "Ps3", 965, 8500, hh3.soluong*hh3.dongia};
    HangHoa hh4 = {4, "A1013", "Ps4", 5790, 15000, hh4.soluong*hh4.dongia};
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
