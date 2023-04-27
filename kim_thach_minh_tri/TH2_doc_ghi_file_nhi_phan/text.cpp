#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 1000

// struct person with 3 fields
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
    int i =0; // dem so hang hoa doc duoc
	HangHoa* res_dmhh; //danh muc hang 
    
    res_dmhh = malloc(*MAX_AMOUNT sizeof(HangHoa)); //Cap phat vung nho cho danh sach hang hoa

    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	
	//printf("%5s%12s%13s\n", "ID" ,"First Name", "Last Name");	
	
	//thu doc 1 person 
	fread(&hhA, sizeof(HangHoa), 1, infile );
	res_dmhh[i] =hhA;

	//Duyet file cho den khi gap EOF
	while(!feof(infile))
	{	//In hhA ra man hinh
		printf("%5s  %15s %d %f %f \n", hhA.mahang, hhA.tenhang, hhA.soluong,hhA.gia, hhA.thanhtien );	
		
		//Doc mot cau truc person dua vao perA		
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
/*	HangHoa h1 = {"A001", "Iphone 12", 5, 500, 2500};
    HangHoa h2 = {"A002", "Iphone 13", 5, 700, 5500};
    HangHoa h3 = {"A003", "Iphone 14", 5, 1000, 5000};
    HangHoa h4 = {"A004", "Iphone 14", 5, 1000, 5000};
    
    FILE* outfile = fopen("DSHH.dat", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fwrite(&h4, sizeof(HangHoa), 1, outfile);
    fclose(outfile);
*/
    int count;
    
    HangHoa* my_dshh = read_DMHH("DSHH.dat", &count);

    printf("Da doc duoc %d hang hoa\n", count);
    print_DMHH(my_dshh, count);

    char* mahang = "A003";
    HangHoa hang_kq;
    int found  = find_HH_by_ma(mahang, my_dshh,count, &hang_kq);
    
    if (found)
    
        print_HH(hang_kq);
    else
        printf("Tim khong thay hang hoa co ma %s\n", mahang);

    return 0;
}

