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

void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s%25s%10d%12f%12f\n", hh[i].mh, hh[i].th, hh[i].sl, hh[i].dg, hh[i].st);	
	}
}
void print_HH(HangHoa hhA)
{
	printf("%10s%25s%10d%12f%12f\n", hhA.mh, hhA.th, hhA.sl, hhA.dg, hhA.st);	
	
}

int main()
{
     HangHoa hh1 = {01,"A0101","Tao", 20, 5000, hh1.sl*hh1.dg};
     HangHoa hh2 = {02,"B0101","Le", 10, 4000, hh2.sl*hh2.dg};
     HangHoa hh3 = {03,"C0101","Nho", 50, 2000, hh3.sl*hh3.dg};
     HangHoa hh4 = {04,"D0101","Buoi", 5, 10000, hh4.sl*hh4.dg};
     HangHoa hh5 = {05,"E0101","Dua hau", 5, 20000, hh4.sl*hh4.dg};
     HangHoa hh6 = {06,"F0101","Cam", 20, 3000, hh4.sl*hh4.dg};
     
     
     FILE *outfile = fopen("DMHH.DAT","wb");
     
     fwrite(&hh1, sizeof(HangHoa), 1, outfile);
	 fwrite(&hh2, sizeof(HangHoa), 1, outfile);	
	 fwrite(&hh3, sizeof(HangHoa), 1, outfile);	
	 fwrite(&hh4, sizeof(HangHoa), 1, outfile);	
	 fwrite(&hh5, sizeof(HangHoa), 1, outfile);	
 	 fwrite(&hh6, sizeof(HangHoa), 1, outfile);	
	
	 if (fwrite!=0)
		 printf("Success!! Ghi file thanh cong!\n");
	 else
		 printf("Faile!! Ghi file khong thanh cong!\n");	
		
 	 fclose(outfile);
	  
	  int n=0; 
	
	 HangHoa* myhh = read_DMHH("DMHH.DAT", &n);
	 
	 printf("Da nhap thanh cong %d hang hoa",n);

    void print_DMHH(HangHoa* hh, int n);
    
    void print_HH(HangHoa hhA);

    
    return 0;
}
