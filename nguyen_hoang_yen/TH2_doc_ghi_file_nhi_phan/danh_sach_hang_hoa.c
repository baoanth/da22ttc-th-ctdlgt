#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200

typedef struct 
{
    char mahang[5];
    char tenhang[20];
    int soluong;
    float gia;
    float giatien;

}HangHoa;

HangHoa* read_DMHH(char * filename, int* count)
{
    int i =0; 
	HangHoa* res_dmhh; 
    
    res_dmhh = malloc(sizeof(HangHoa)*MAX_AMOUNT); 

    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	
	fread(&hhA, sizeof(HangHoa), 1, infile );
	res_dmhh[i] =hhA;

	while(!feof(infile))
	{	
	   	printf("%5s  %15s %d %f %f \n", hhA.mahang, hhA.tenhang, hhA.soluong,hhA.gia, hhA.giatien );	
	    		
		fread(&hhA, sizeof(HangHoa), 1, infile );
        i++;
        res_dmhh[i] =hhA;
	}
	
	fclose(infile);
    *count = i;
    return res_dmhh;
}

void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		print_HH(hh[i]);
	}
}
void print_HH(HangHoa h)
{
    printf("%10s%25s%10d%12f%12f\n", h.mahang, h.tenhang, h.soluong, h.gia, h.giatien);	
}

int find_HH_by_ma(char* mahang, HangHoa* hh_array, int count, HangHoa* kq)
{
    
    int i=0;
    
    while (i<count)
    {
		printf("Ma hang: %s \n ", hh_array[i])   ;
    	
        if( strcmp(hh_array[i].mahang, mahang )==0)        
        {
        	*kq= hh_array[i];
        	return i;
        }             
        i++;
	}
	return  -1;
}

void input_DMHH(char* filename) 
{
   //Mo file doc noi dung dua vao mot mang my_dmhh

   //Lap cho den khi nhap ma = EXIT
   // Nhap mahang_tam 
   // Neu mahang_tam == EXIT thi break
   // Tim trong my_dmhh xem mahang_tam co chua, neu chua thif nhap binh thuong, neu da co thi in ra ten hang.
   // Nhap gia, soluong, tinh giatien = soluong*dongia
   // Dua mon hang vua nhap vao my_dmhh

   // Luu toan bo my_dmhh vao outfile, dong outfile

}


int main()
{	
	HangHoa h1 = {"A01", "Iphone x", 1, 500, 200};
    HangHoa h2 = {"A02", "Iphone 13", 4, 700, 3000};
    HangHoa h3 = {"A03", "Iphone 15", 5, 1000, 15000};
 
    
    FILE* outfile = fopen("DSHH.dat", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fclose(outfile);

    int count;
    
    HangHoa* my_dshh = read_DMHH("DSHH.dat", &count);

    printf("Da doc duoc %d hang hoa\n", count);
    print_DMHH(my_dshh, count);

   	if (fwrite!=0)
		printf("Ghi tep thanh cong\n");
	else
		printf("Loi! Ghi tep khong thanh cong\n");
	fclose(outfile);   

    int n=0;
    HangHoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );

	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;


}

