#include <stdio.h>
#include <stdlib.h>
#define MaxAmount 1000

typedef struct
{
    char mahang[10] ;
    char tenhang[30];
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

	fread(&hhA, sizeof(HangHoa), 1, infile);

	dmhh[count]=hhA;

	while(!feof(infile))
	{
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

void find_HH_by_ma(char * mahang,HangHoa* hhct,int n ){
	int i,dem = 0;
	for(i = 0;i<n;i++){
		if(strcmp(hhct[i].mahang, mahang)==0){
			dem++;
		
			printf("\n--- Da tim thay hang hoa co ma %s ---\n", mahang);
			print_DMHH(&hhct[i],1); 
		} 			
	}
	
	if(dem == 0) printf("--- Khong tim thay hang hoa co ma %s ---", mahang);
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
	
	printf("\nDanh sach co %d loai hang hoa\n", n);	

	print_DMHH(mydmhh, n);
	
	char mahang[10];
	printf("\nNhap ma hang can tim ");
	gets(mahang);
	
	find_HH_by_ma(mahang,mydmhh,n);
	
	return 0;
}
