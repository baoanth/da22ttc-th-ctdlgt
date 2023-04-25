#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct
{
	int stt;
    char mh[10];
    char th[10];
    int sl;
    float dg;
    float st;
}HangHoa;

HangHoa* read_DMHH(char *filename, int *count)
{
	HangHoa*  hh_array;
    
    hh_array =  malloc(MAX* sizeof(HangHoa));
    
   	FILE *infile = fopen (filename,"rb");
	HangHoa hhA;
	int dem=0;
	
	printf("%5s %10s %15s %15s %20s %20s\n","STT", "Ma Hang", "Ten Hang", "So Luong", "Don Gia", "So Tien");
	
	fread(&hhA, sizeof(HangHoa),1, infile);
	hh_array[dem]=hhA;
	
	while(!feof(infile))
	{
		printf("%5d %10s %15s %15d %20.2f %20.2f\n", hhA.stt, hhA.mh, hhA.th, hhA.sl, hhA.dg, hhA.st);
		dem++;
		fread(&hhA, sizeof(HangHoa),1, infile);
		hh_array[dem]=hhA;
	}
	
	
	fclose(infile);	
	*count=dem;
	return hh_array;
}

int main()
{
     HangHoa hh1 = {01,"A0101","Keo", 20, 5000, 100000};
     HangHoa hh2 = {02,"B0101","Banh", 10, 4000, 40000};
     HangHoa hh3 = {03,"C0101","Muc", 10, 6000, 60000};
     FILE *outfile = fopen("DMHH.DAT","wb");
     
     fwrite(&hh1, sizeof(HangHoa), 1, outfile);
	 fwrite(&hh2, sizeof(HangHoa), 1, outfile);	
	 fwrite(&hh3, sizeof(HangHoa), 1, outfile);	
	 if (fwrite!=0)
		 printf(" Ghi file thanh cong!\n");
	 else
		 printf(" Ghi file khong thanh cong!\n");	
		
 	 fclose(outfile);
	  
	  int n=0; 
	
	 HangHoa* myhh = read_DMHH("DMHH.DAT", &n);

   

    
    return 0;
}
