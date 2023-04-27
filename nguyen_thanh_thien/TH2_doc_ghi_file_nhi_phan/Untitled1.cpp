
#include <stdio.h>
#include <stdlib.h>


#define MAX_AMOUNT 200


typedef struct{
    char mahang[5] ;
    char tenhang[20];
    int soluong;
    float gia;
    float thanhtien;
}HangHoa;


int read_DMHH(char* filename, HangHoa * ds_hanghoa)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return -1;
    }

    int count = 0;
    HangHoa hh;
    while (fread(&hh, sizeof(HangHoa), 1, file) == 1 && count < MAX_AMOUNT)
	{
        ds_hanghoa[count++] = hh;
        
    }

    fclose(file);
    return count;
}


void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s%25s%10d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].gia, hh[i].thanhtien);	
	}
}
void print_HH(HangHoa hh)
{
	printf("%10s%25s%10d%12f%12f\n", hh.mahang, hh.tenhang, hh.soluong, hh.gia, hh.thanhtien);	
	
}


int  find_HH_by_ma(char* mhX, HangHoa * hh_array, int count, HangHoa* hh_kq)
{
	int i=0;
    
    while (i<count)
    {
		 ;
    	
        if( strcmp(hh_array[i].mahang, mhX )==0)        
        {
        	*hh_kq= hh_array[i];
        	return i;
        }             
        i++;
	}
	return  -1;

}

void input_DMHH(char* filename)
{
	
	char mahang_input[5];    
	HangHoa hh_temp; 
	
	
	HangHoa my_dmhh[MAX_AMOUNT] ;
	
	int count = read_DMHH(filename, my_dmhh ); 
	print_DMHH(my_dmhh, count);         
	
	printf(" nhap hang hoa moi (Nhap EXIT de thoat):\n\n") ;	

	
	while(1) 
	{
		printf("\nMa hang: ");
		fflush(stdin);
		gets(mahang_input);
		
		if (strncmp(mahang_input, "EXIT", 4)==0){
   			break;
   		}
		
		int found = find_HH_by_ma(mahang_input, my_dmhh, count, &hh_temp);
		
		if (found != -1)
		{
			printf("Tim thay ma hang vua nhap tai phan tu thu %d\n", found);
			
			printf("\nTen hang: %s\n", hh_temp.tenhang);
			
			printf("So luong: "); 
			scanf("%d", &hh_temp.soluong);
			
			printf("Don gia: "); 
			scanf("%f", &hh_temp.gia);
			
			hh_temp.thanhtien = hh_temp.soluong * hh_temp.gia ;
			printf("\nThanh tien: %f\n", hh_temp.thanhtien); 
			
			my_dmhh[found] = hh_temp ;
		}
		else
		{
			strcpy(hh_temp.mahang, mahang_input);
			
			printf("Ten hang: "); 
			gets(hh_temp.tenhang);
			
			printf("So luong: "); 
			scanf("%d", &hh_temp.soluong);
			
			printf("Don gia: "); 
			scanf("%f", &hh_temp.gia);
			
			hh_temp.thanhtien = hh_temp.soluong * hh_temp.gia ;
			printf("Thanh tien: %f", hh_temp.thanhtien); 
			
			
			my_dmhh[count] = hh_temp; // 		
			count++;
			printf("Them mon hang moi vao vi tri thu %d\n\n", count);
			print_DMHH(my_dmhh,count);
		}
	}

	int i = 0;
	FILE * outfile = fopen(filename, "w");
	for (i=0; i<count; i++)
	{ 
		fwrite(&my_dmhh[i], sizeof(HangHoa), 1, outfile);
	}
	fclose(outfile);	
}




int main()
{

	HangHoa h1 = {"A0101", "trung", 5, 300, 1500};
    HangHoa h2 = {"A0102", "banh", 5, 200, 1000};
    HangHoa h3 = {"A0103", "sua", 5, 100, 500};
    HangHoa h4 = {"A0104", "tao", 5, 500, 2500};
    HangHoa h5 = {"A0105", "dua", 5, 400, 2000};
	FILE* outfile = fopen("DMHH.DAT", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fwrite(&h4, sizeof(HangHoa), 1, outfile);
    fwrite(&h5, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("da ghi thanh cong\n");
	else
		printf("khong thanh cong\n");
	fclose(outfile);   

	input_DMHH("DMHH.DAT");
	
	return 0;

}


