#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200

typedef struct{
	char mahang[5];
	char tenhang[20];
	int  soluong;
	float dongia;
	float thanhtien;	
}HangHoa;

HangHoa* read_DMHH(char* filename, int *n)
{
	HangHoa* hh_array;
	hh_array = malloc(MAX_AMOUNT* sizeof(HangHoa));
	
	FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int count= 0;
	
	printf("%5s%12s%10s%15s%12s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
    fread(&hhA, sizeof(HangHoa), 1, infile);
    hh_array[count]=hhA;
    
	while(!feof(infile))
	{
		printf("%5s%12s%10s%15s%12s\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.thanhtien);
		
		count++;
		fread(&hhA, sizeof(HangHoa), 1, infile);
	    hh_array[count]=hhA;
		
	}
	
	fclose(infile);	
	*n = count;
	return hh_array;
}
void printf_DMHH(HangHoa* hh, int n)
{
	printf("%5s%12s%10s%15s%12s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%12s%10s%15s%12s\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].thanhtien);
	}	
}
	
void input_DMHH(char* filename)
{
	int count;
	my_dmhh = read_DMHH("DMHH", &count);
	
}



int main()
{
	HangHoa h1 = {"A001", "ca chep", 5, 20000, 100000};
	HangHoa h2 = {"A002", "ca loc", 3, 30000, 90000};
	HangHoa h3 = {"A003", "ca ro", 8, 10000, 80000};
  		
    FILE* outfile = fopen("DMHH.DAT", "w");
    
    fwrite(&h1, sizeof(HangHoa), 1, outfile);
    fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    
    if (fwrite!=0)
        printf("write file successfully");
    else
	    printf("ERROR! write file unsuccessfully");
       
     fclose(outfile); 
	 
	 int n=0;
	 HangHoa* mydmhh= read_DMHH("DMHH.DAT", &n);
	 
	 printf("\nDanh sach tren co %d mon hang\n ", n);
	 printf_DMHH(mydmhh, n);
	 return 0; 
		
}	

