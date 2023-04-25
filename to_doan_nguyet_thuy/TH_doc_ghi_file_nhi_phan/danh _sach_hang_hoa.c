#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200;

typedef struct
{
    
    char mahang[5];
    char tenhang[20];
    int soluong;
    float gia;
    float sotien;
}Hanghoa;

HangHoa* read_DMHH(char* filename, int *n)
{
	HangHoa* hh_array;
	
	hh_array = malloc(MAX_AMOUNT* sizeof(HangHoa));
	
	FILE *infile = fopen(filename, "rb");
	HangHoa  hhA;
	int count =0;
	
	
	printf("%5s%20s%13s%12s%12\n","Ma Hang","Ten Hang","So Luong", "Don Gia", "So Tien");
    fread(&hhA,sizeof(HangHoa),1,infile);
    hh_array[count] = hhA;
    
    
    while(!feof(infile))
    {
    	
    	printf("5s%20s%13d%12f%12f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hha.sotien);
    	count ++;
    	
    	fread(&hhA,sizeof(HangHoa),1,infile);
    	hh_array[count]=hhA
        
	}
     fclose(infile);
     *n = count ;
     return hh_array;
     



}


int main()
{
	HangHoa h1 = ("00001", "ca moi 1", "2", "12", "24" );
	HangHoa h1 = ("00002", "ca moi 2", "2", "13", "26" );
	HangHoa h1 = ("00003", "ca moi 3", "2", "14", "28" );
	
	
	FILE *outfile;
	outfile= fopen("DMHH.DAT","w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
	fwrite(&h3, sizeof(HangHoa), 1, outfile);
	
	if(fwrite!=0)
	   printf("Write file successfully");
	else 
	   printf("ERROR! Write file successfully");
	   
	   fclose(outfile);
	   int n=0;
	   HangHoa* mydmhh = read_DMHH("DMHH.DAT", &n);
	   
	   printf("\nDanh sach tren co %d mon hang\n", n);
	   print_DMHH(mydmhh, n);
	   return 0;
	   
	
	   
    

}






