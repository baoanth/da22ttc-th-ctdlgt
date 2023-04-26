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
	
	printf("%5s%12s%10s%15s%20s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
    fread(&hhA, sizeof(HangHoa), 1, infile);
    hh_array[count]=hhA;
    
	while(!feof(infile))
	{
		printf("%5s%12s%10d%20f%20f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.thanhtien);
		
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
	printf("%5s%12s%10s%15s%20s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%12s%10d%20f%20f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].thanhtien);
	}	
}

void print_HH(HangHoa hh)
{
	printf("%5s%12s%10d%20f%20f\n", hh.mahang, hh.tenhang, hh.soluong, hh.dongia, hh.thanhtien);

}

int  find_HH_by_ma(char*mahang, HangHoa*hh_array, int count, HangHoa*hh_kq)
{
	int i = 0;
	while( i< count )
	{
		if( strcmp(hh_array[i].mahang, mahang)==0)
		{
			*hh_kq = hh_array[i];
			return 1;
		}
		i++;
	}
	return 0;
     


}	
void input_DMHH(char* filename)
{
	int count;
	//my_dmhh = read_DMHH("DMHH", &count);
	
}



int main()
{
	HangHoa h1 = {"A001", "iphone 3", 5, 20000, 100000};
	HangHoa h2 = {"A002", "iphone 4", 3, 30000, 90000};
	HangHoa h3 = {"A003", "iphone 5
    ", 8, 10000, 80000};
  		
    FILE* outfile = fopen("DMHH.DAT", "w");
    
    fwrite(&h1, sizeof(HangHoa), 1, outfile);
    fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    
    if (fwrite!=0)
        printf("\nwrite file successfully\n");
    else
	    printf("\nERROR! write file unsuccessfully\n");
       
     fclose(outfile); 
	 
	 int n=0;
	 HangHoa* mydmhh= read_DMHH("DMHH.DAT", &n);
	 
	 printf("\nDanh sach tren co %d mon hang\n ", n);
	 printf_DMHH(mydmhh, n);


    
     HangHoa hhX;
	 char* mahangX = "A002";
	 int found = find_HH_by_ma(mahangX, mydmhh, n, &hhX);
	 printf("found = %d \n", found);

     if(found)
	 {

		printf("Da tim thay hang hoa co ma %s \n ", mahangX);
	    print_HH(hhX);
	 }
	 else 
	 {
		printf("Khong tim thay hang hoa co ma %s \n", mahangX);

	 }
	 return 0;

	 
		
}	







