#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 1000

typedef struct
{
    char mahang[10] ;
    char tenhang[20];
    int soluong;
    float dongia;
    float thanhtien;
}HangHoa;

HangHoa* read_DMHH(char *filename, int *count)
{
    int i =0; 
    
	HangHoa *res_dmhh = malloc(sizeof(HangHoa)*MAX_AMOUNT);
	
    FILE *infile = fopen(filename, "rb");
    
	HangHoa hhA;	
	
	fread(&hhA, sizeof(HangHoa), 1, infile );
	
	res_dmhh[i] =hhA;

	while(!feof(infile))
	{	
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
	printf("%10s%20s%20s%20s%20s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "Thanh tien");	
	
	int i;
	
	for (i=0; i<n; i++)
	{
		print_HH(hh[i]);
	}
}

void print_HH(HangHoa h)
{
    printf("%10s%20s%20d%20.0f%20.0f\n", h.mahang, h.tenhang, h.soluong, h.dongia, h.thanhtien);	
}

int find_HH_by_ma(char* mahang, HangHoa* hh_array, int count, HangHoa* kq)
{
    int i=0;
    
    while (i<count)
	{
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
    int count;
    
    char mahang_tam[5];
    
    HangHoa hh_tam;
    
    HangHoa*  my_dmhh =  read_DMHH( filename,  &count);
    
    printf("Danh sach hang hoa\n");
	 
    print_DMHH(my_dmhh, count);
    
    while (1)
    {
    	printf("\nNhap ma hang: ");
    	
    	scanf("%s", &mahang_tam);
    	
    	if( strncmp(mahang_tam, "EXIT", 4)==0)   
    	{
    		break;    		
    	}
    	int found_i = find_HH_by_ma(mahang_tam, my_dmhh, count, &hh_tam);
    	
    	if (found_i !=-1)
    	{
    		printf("Da tim thay ma hang %s\n", mahang_tam);
    		
    		printf("Ten hang: %s\n", my_dmhh[found_i].tenhang);
    		
			fflush(stdin);
			
			printf("Nhap so luong: ");	
					
    		scanf("%d", &my_dmhh[found_i].soluong);
    		
    		fflush(stdin);
    		
			printf("Nhap don gia: "); 	
					
    		scanf("%f", &my_dmhh[found_i].dongia);
    		
    		my_dmhh[found_i].thanhtien = my_dmhh[found_i].soluong * my_dmhh[found_i].dongia;
    		
    		printf("Thanh tien: %.0f\n", my_dmhh[found_i].thanhtien);
			
			printf("\nDanh sach hang hoa da duoc cap nhat\n");			    		
    	}
		else
		{			
			printf("Khong tim thay ma hang %s\n", mahang_tam);
			
			fflush(stdin);
			
			printf("Nhap ten hang: "); 
			
			gets(hh_tam.tenhang);
            
            fflush(stdin);
            
			printf("Nhap so luong: ");
			
    		scanf("%d", &hh_tam.soluong);
    		
    		fflush(stdin);
    		
			printf("Nhap don gia: ");
			
    		scanf("%f", &hh_tam.dongia);

            hh_tam.thanhtien = hh_tam.soluong * hh_tam.dongia;
            
    		printf("Thanh tien: %.0f\n", hh_tam.thanhtien);	
    		
    		printf("\nDanh sach hang hoa da duoc cap nhat\n");
    		
    	  	strcpy( hh_tam.mahang , mahang_tam) ;
			
//         	print_HH(hh_tam);
            
            my_dmhh[count] = hh_tam;
            
            count++;	
		}
		print_DMHH(my_dmhh, count);
    }
	FILE* outfile = fopen(filename, "w");
	
	int i;
	
	for (i = 0; i<count; i++)	
	{	
		fwrite(&my_dmhh[i], sizeof(HangHoa), 1, outfile);  
	}
	fclose(outfile);
}

int main()
{	
	char* filename ="DSHH.dat";
	
  	HangHoa hh1 = {"H001", "But chi", 1, 2000, 2000};
    HangHoa hh2 = {"H002", "But bi", 1, 5000, 5000};
    HangHoa hh3 = {"H003", "But long", 1, 8000, 8000};
    HangHoa hh4 = {"H004", "But xoa", 1, 10000, 10000};
    
    FILE* outfile = fopen(filename, "w");
	
	fwrite(&hh1, sizeof(HangHoa), 1, outfile);
	fwrite(&hh2, sizeof(HangHoa), 1, outfile);
    fwrite(&hh3, sizeof(HangHoa), 1, outfile);
    fwrite(&hh4, sizeof(HangHoa), 1, outfile);
    
    fclose(outfile);

/*  int count;
    
    HangHoa* my_dshh = read_DMHH("DSHH.dat", &count);

    printf("Da doc duoc %d hang hoa\n", count);
    
    print_DMHH(my_dshh, count);
    
	char* mahang = "A003";
    
    HangHoa hang_kq;
    
    int found  = find_HH_by_ma(mahang, my_dshh, count, &hang_kq);
    
    if (found)
    {
    	 print_HH(hang_kq);
	}   
    else
    {
    	printf("Tim khong thay hang hoa co ma %s\n", mahang);
	} 
*/
	input_DMHH(filename);
	
    return 0;
}
