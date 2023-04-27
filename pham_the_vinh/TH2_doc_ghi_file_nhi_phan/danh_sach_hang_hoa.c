#include <stdio.h>
#include <stdlib.h>
#define MaxAmount 1000

typedef struct
{
    char mahang[10] ;
    char tenhang[30];
    int soluong;
    float dongia;
    float sotien;
}HangHoa;

HangHoa *read_DMHH(char* filename, int *n)
{
    HangHoa *dmhh = malloc(MaxAmount* sizeof(HangHoa));
    
    FILE *infile = fopen(filename, "rb");

	HangHoa hhA;

	int count =0;	

	fread(&hhA, sizeof(HangHoa), 1, infile);

	dmhh[count]=hhA;

	while(!feof(infile))
	{
		count++;
		
		fread(&hhA, sizeof(HangHoa), 1, infile);   

        dmhh[count]=hhA;
	}
	
	fclose(infile);

	*n = count;

    return dmhh;
}

void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%15s%15s%15s\n","MA HANG", "TEN HANG", "SO LUONG", "DON GIA", "SO TIEN");	

	int i;

	for (i=0; i<n; i++)
	{
		printf("%10s%25s%15d%15f%15f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].sotien);	
	}
}

int find_HH_by_ma(char* mahang, HangHoa* hh_array, int count, HangHoa* kq)
{
    int i=0;
    while (i<count)
    {
        if(strcmp(hh_array[i].mahang, mahang)==0)        
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
	char mahang_input[10]; 

	HangHoa hh_temp; 
	
	HangHoa my_dmhh[MaxAmount] ;
	
	int count = read_DMHH(filename, my_dmhh); 

	print_DMHH(my_dmhh, count);          
	
	printf("Nhap hang hoa moi. Nhap EXIT de dung\n") ;	

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
			printf("Ma hang vua nhap duoc tim thay tai phan tu thu %d\n", found);
			
			printf("\nTen hang: %s\n", hh_temp.tenhang);
			
			printf("So luong: "); 
			scanf("%d", &hh_temp.soluong);
			
			printf("Don gia: "); 
			scanf("%f", &hh_temp.dongia);
			
			hh_temp.sotien = hh_temp.soluong * hh_temp.dongia ;
			printf("\nSo tien: %f\n", hh_temp.sotien); 
			
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
			scanf("%f", &hh_temp.dongia);
			
			hh_temp.sotien = hh_temp.soluong * hh_temp.dongia ;
			printf("So tien: %f", hh_temp.sotien); 
			
			
			my_dmhh[count] = hh_temp; 		
			count++;
			printf("Them hang hoa moi vao vi tri thu %d\n", count);
			print_DMHH(my_dmhh,count);
		}
	}

	FILE *outfile = fopen(filename, "wb");
	
	for (int i=0; i<count; i++)
	{ 
		fwrite(&my_dmhh[i], sizeof(HangHoa), 1, outfile);
	}
	fclose(outfile);
}

int main()
{
	HangHoa hh1 = {"H001", "But chi", 5, 2000, 10000};
	HangHoa hh2 = {"H002", "But muc", 10, 5000, 50000};
	HangHoa hh3 = {"H003", "But long", 20, 10000, 200000};
	
	FILE* outfile = fopen("DMHH.dat", "wb");
	
	fwrite(&hh1, sizeof(HangHoa), 1, outfile);
	fwrite(&hh2, sizeof(HangHoa), 1, outfile);
	fwrite(&hh3, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("--- Ghi file thanh cong ---\n");
	else
		printf("--- Loi. Ghi file khong thanh cong ---\n");
	fclose(outfile);   

    int n=0;

    HangHoa* mydmhh=  read_DMHH( "DMHH.dat", &n);
	
	printf("\nDanh sach co %d loai hang hoa\n", n);	

	print_DMHH(mydmhh, n);
	
	char* mahang="H002";
	
    HangHoa hang_kq;
    
    int found = find_HH_by_ma(mahang, mydmhh, n, &hang_kq);
    
    if (found){
    	printf("\nDa tim thay hang hoa co ma %s\n", mahang);
    	
        print_DMHH(&hang_kq, 1);
    }else	printf("Khong tim thay hang hoa co ma %s\n", mahang);
	
       
   // input_DMHH("DMHH.dat");
	
	return 0;
}
