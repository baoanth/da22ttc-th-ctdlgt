#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 1000


typedef struct 
{
    char mahang[5];
    char tenhang[25];
    int soluong;
    float gia;
    float thanhtien;

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
		printf("%5s  %15s %d %f %f \n", hhA.mahang, hhA.tenhang, hhA.soluong,hhA.gia, hhA.thanhtien );	
		
				
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
    printf("%10s%25s%10d%12f%12f\n", h.mahang, h.tenhang, h.soluong, h.gia, h.thanhtien);	
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
        	return 1;
        }             
        i++;
	}
	return  0;
}



int main()
{	
	HangHoa h1 = {"A001", "Ao so mi Duvaba", 5, 50, 250};
    HangHoa h2 = {"A002", "may tinh casio 580 fx", 5, 70, 550};
    HangHoa h3 = {"A003", "tai nghe gaming", 5, 100, 500};
    HangHoa h4 = {"A004", "tui deo cheo", 5, 100, 500};
    HangHoa h5 = {"A005", "Quan jean baggy",1,100,1000};
    HangHoa h6 = {"A006", "Dong ho bigben",2,200,2000};
    
    FILE* outfile = fopen("DSHH.dat", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fwrite(&h4, sizeof(HangHoa), 1, outfile);
    fwrite(&h5, sizeof(HangHoa), 1, outfile);
    fwrite(&h6, sizeof(HangHoa), 1, outfile);
    fclose(outfile);

    int count;
    
    HangHoa* my_dshh = read_DMHH("DSHH.dat", &count);

    printf("Da doc duoc %d hang hoa\n", count);
    print_DMHH(my_dshh, count);

    char* mahang = "A005  ";
    HangHoa hang_kq;
    int found  = find_HH_by_ma(mahang, my_dshh,count, &hang_kq);
    
    if (found)
    
        print_HH(hang_kq);
    else
        printf("Tim khong thay hang hoa co ma %s\n", mahang);

    return 0;
}
