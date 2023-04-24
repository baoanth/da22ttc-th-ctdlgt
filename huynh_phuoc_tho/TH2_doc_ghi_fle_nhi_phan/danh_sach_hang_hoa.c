#include <stdio.h>
#include <stdlib.h>
#defile AMOUNT 200

type struct HangHoa{
    char mahang [5];
    char tenhang[20];
    int soluong;
    float dongia;
    float sotien;
}HangHoa;

HangHoa* read_DSHH(char* filename, int n)

int main()
{
    FILE * intfile = fopen("DSHH.dat", "rb");
	
	struct HangHoa hhA;
	
	printf("%5s %12s %13s %10s %10s \n", "mahang", "tenhang","soluong","dongia","sotien");
	fread(&hhA, sizeof(struct HangHoa), 1, infile);
	
	while(!feof(infile))
	{
		printf("%5d %12d %13s %10s %10s \n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dogia, hhA.sotien);
		
		fread(&hhA, sizeof(struct HangHoa), 1, infile);
	}
	fclose(infile);
    return 0;
}


int main()
{
	struct mahang hhA1 = {samsum, a, 300, 2500};
    struct mahang hhA2 = {samsum, s, 500, 3000};
    struct mahang hhA3 = {samsum, m, 700, 5000};

	FILE *outfile = fopen("DSHH.dat", "w");
	
	fwrite(&hhA1, sizeof(struct HangHoa), 1, outfile);
    fwrite(&hhA2, sizeof(struct HangHoa), 1, outfile);
    fwrite(&hhA3, sizeof(struct HangHoa), 1, outfile);
	
	if(fwrite!=0) printf("Ghi file thanh cong roi!");
	else printf("ERROR! Gi file KHONG thanh cong!");
	
	fclose(outfile);
}