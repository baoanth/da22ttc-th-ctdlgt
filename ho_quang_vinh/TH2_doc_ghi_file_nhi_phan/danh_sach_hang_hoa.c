#include<stdio.h>
#include<string.h>
#defile AMOUNT 200
type struct {
    char mahang[5];
    char tenhang[20];
    int soluong;
    float gia;
    float thanhtien;
}
   HangHoa * read_DMHH(char* filename, int *n)
int main()  
{
	FILE * infile = fopen("DMHH.dat", "rb");
	struct hanghoa hhA;
	
	
	
	printf("%5d%20d%8s%20s%10s\n", "Ma hang", "Ten hang", "So luong","Don gia","So Tien");
	
	fread(&hhA, sizeof(struct Hanghoa), 1, infile);
	

	while(!feof(infile))
	{
		printf("%5d%20d%8s%20f%10s\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hhA sotien);
		
		fread(&hhA, sizeof(struct Hanghoa), 1, infile);
	}
	
	fclose(infile);	
	return 0;
	
}
int main()
{
    struct mahang hha1 ={1, iphone, 12, 300, 2500 };
    struct mahang hhA2 ={1, iphone, 13, 500, 3500};
	struct mahang hhA3 ={1, iphone, 14, 700, 5500};
	FILE* outfile = fopen("DMHH.dat", "w");

    fwrite(&hhA1, sizeof(struct Hanghoa ), 1, outfile);
	fwrite(&hhA2, sizeof(struct Hanghoa ), 1, outfile);
	fwrite(&hhA3, sizeof(struct Hanghoa), 1, outfile);
	
	
	if (fwrite !=0)
	printf("write file successfully");
	else
	printf("EROR! write file successfully");
	fclose(outfile);

}

