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
    	printf("%5s%20s%20d%12f%12f\n",hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);
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
		printf("%5s%20s%20d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].sotien);	
	}
}

void print_HH(Hanghoa hh)
{
	printf("%5s%20s%20d%12f%12f\n", hh.mahang, hh.tenhang, hh.soluong, hh.dongia, hh.sotien);	
}
int find_HH_by_ma(char* mahang, Hanghoa* hh_array, int count, Hanghoa* hh_kq)
{
	int i=0;
	while (i<count)
	{
		if (strcmp(hh_array[i].mahang, mahang)==0)
		{
			*hh_kq= hh_array[i];
			return 1;
		}
		i++;
	}
	return 0;
}
			   
void input_DMHH(char* filename)
{
	int count;
}

int main()
{
	Hanghoa h1 = {"A001","con meo trang",2,10,20};
	Hanghoa h2 = {"A002","con meo vang",2,30,60};
	Hanghoa h3 = {"A003","con meo do",2,50,100};
	Hanghoa h4 = {"A004","con meo den",2,70,140};

	
	FILE* outfile= fopen("DMHH.DAT","w");

	fwrite(&h1, sizeof(Hanghoa),1,outfile);
	fwrite(&h2, sizeof(Hanghoa),1,outfile);
	fwrite(&h3, sizeof(Hanghoa),1,outfile);
	fwrite(&h4, sizeof(Hanghoa),1,outfile);

	
    if (fwrite!=0)
	  printf("Ghi file thanh cong\n");
	else
	  printf("Ghi file that bai\n");
	  
	fclose(outfile);    
	
	int n=0;
    Hanghoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	
	Hanghoa hhX;
	char* mahangX = "A004";
	int found=find_HH_by_ma(mahangX, mydmhh, n, &hhX);
	
	printf("Found = %d\n",found);
	if (found)
	{
		printf("Da tim thay hang hoa co ma %s\n", mahangX);
		print_HH(hhX);
	}
	else
	{
	printf("Khong tim thay hang hoa co ma %s\n",mahangX);
	}	
	
	return 0;

}		
