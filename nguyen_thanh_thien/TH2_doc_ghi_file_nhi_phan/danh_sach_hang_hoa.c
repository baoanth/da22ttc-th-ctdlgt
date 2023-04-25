#include<stdio.h>
#include<stdlib.h>
#define max_amount 100 

typedef struct HangHoa{
	int stt;
	char mahang [5];
	char tenhang [20];
	int soluong;
	float dongia;
	float sotien;
	}HangHoa;
	
HangHoa* read_dmhh(char* filename,int* count)
{
	
	 FILE *infile= fopen(filename, "rb");
	 HangHoa hhA;
	 HangHoa* dmhh;
     dmhh = malloc(sizeof(HangHoa)*max_amount);
	 int i = 0;
	 
	 printf("%5s%10s%15s%15s%20s%20s \n","STT","Ma hang" ,"Ten hang","So luong","Don gia","So tien");
	 fread(&hhA, sizeof(HangHoa),1 ,infile);
	 dmhh[i]=hhA;
	 
	 while(!feof(infile))
	 {
	    printf("%5d%10s%15s%15d%20f%20f \n",hhA.stt, hhA.mahang,hhA.tenhang,hhA.soluong,hhA.dongia,hhA.sotien);
    	fread(&hhA, sizeof(HangHoa),1 ,infile);
    	i++;
	 }
	 fclose(infile);
     *count=i;
}
int main()
{
	HangHoa hh1 = {1, "A1010","DT" ,100, 300, 30000};
	HangHoa hh2 = {2, "A1011","DT", 100, 200, 20000};
	HangHoa hh3 = {3,"A1012","DT", 100 ,350, 35000};   
	HangHoa hh4 = {4,"A1013","DT", 100 ,350, 35000};
	
	FILE *outfile;
	outfile= fopen("DMHH.DAT","w");
	
	fwrite(&hh1, sizeof(HangHoa),1,outfile);
	fwrite(&hh2, sizeof(HangHoa),1,outfile);
	fwrite(&hh3, sizeof(HangHoa),1,outfile);
	fwrite(&hh4, sizeof(HangHoa),1,outfile);
	
 
	fclose(outfile); 
	int count;
	HangHoa* myhh = read_dmhh("DMHH.dat" ,&count);
	printf("\n da nhap thanh cong %d hang hoa" , count);   
	return 0;
}		

	

	
	

	
	
	

