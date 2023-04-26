#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200
typedef struct {
	char mahang [5];
	char tenhang [20];
	int soluong;
	float dongia;
	float sotien;
}Hanghoa;

Hanghoa* read_DMHH(char* filename,int *n)
{
    Hanghoa* hh_array;
	hh_array= malloc(MAX_AMOUNT* sizeof(Hanghoa));
    FILE *infile= fopen(filename, "rb");
    Hanghoa hhA;
    int count=0; 
    
    printf("%5s%15s%15s%12s%12s\n","Ma hang","Ten hang","So luong","Don gia","So tien");
    fread(&hhA, sizeof(Hanghoa),1 ,infile);
    hh_array[count]=hhA;

    while(!feof(infile))
    {
	    count++;
    	printf("%5s%15s%15d%12f%12f\n",hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);
    	fread(&hhA, sizeof(Hanghoa),1 ,infile);
    	hh_array[count]=hhA;
    	
    }
    fclose(infile);
    *n = count;
    return hh_array;
} 

void print_DMHH(Hanghoa* hh, int n)
{

	printf("%5s%15s%15s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%15s%15d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].sotien);	
	}
}
   
void input_DMHH(char* filename)
{
	int count;
}

int main()
{
	Hanghoa h1 = {"A001","ma 1",2,10,20};
	Hanghoa h2 = {"A002","ma 2",2,30,40};
	Hanghoa h3 = {"A003","ma 3",2,50,60};
	
	FILE* outfile= fopen("DMHH.DAT","w");

	fwrite(&h1, sizeof(Hanghoa),1,outfile);
	fwrite(&h2, sizeof(Hanghoa),1,outfile);
	fwrite(&h3, sizeof(Hanghoa),1,outfile);
	
    if (fwrite!=0)
	  printf("Write file successfully\n");
	else
	  printf("ERROR! Write file unsuccessfully\n");
	  
	fclose(outfile);    
	
	int n=0;
    Hanghoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;

}		







