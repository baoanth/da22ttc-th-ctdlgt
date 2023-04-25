#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

typedef struct HangHoa{
    char mahang[5];
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

	while(!feof(infile))
	{	
		printf("%5s %25s %5d %f %f", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);	
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
	HangHoa hh1 = {"A1010", "Ps1", 10, 100, 1000};
    HangHoa hh2 = {"A1011", "Ps2", 10, 200, 2000};
    HangHoa hh3 = {"A1012", "Ps3", 10, 300, 3000};
    HangHoa hh4 = {"A1013", "Ps4", 10, 400, 4000};
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
