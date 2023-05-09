 #include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200

typedef struct{
	char mahang[5];
	char tenhang[20];
	int  soluong;
	float dongia;
	float thanhtien;	
}HangHoa;

HangHoa* read_DMHH(char* filename, int *n)
{
	HangHoa* hh_array;
	hh_array = malloc(MAX_AMOUNT* sizeof(HangHoa));
	
	FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int count= 0;
	
	printf("%5s%12s%10s%15s%20s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
    fread(&hhA, sizeof(HangHoa), 1, infile);
    hh_array[count]=hhA;
    
	while(!feof(infile))
	{
		printf("%5s%12s%10d%20f%20f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.thanhtien);
		
		count++;
		fread(&hhA, sizeof(HangHoa), 1, infile);
	    hh_array[count]=hhA;
		
	}
	
	fclose(infile);	
	*n = count;
	return hh_array;
}
void printf_DMHH(HangHoa* hh, int n)
{
	printf("%5s%12s%10s%15s%20s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%12s%10d%20f%20f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].thanhtien);
	}	
}

void print_HH(HangHoa hh)
{
	printf("%5s%12s%10d%20f%20f\n", hh.mahang, hh.tenhang, hh.soluong, hh.dongia, hh.thanhtien);

}

int  find_HH_by_ma(char*mahang, HangHoa*hh_array, int count, HangHoa*hh_kq)
{
	int i = 0;
	while( i< count )
	{
		if( strcmp(hh_array[i].mahang, mahang)==0)
		{
			*hh_kq = hh_array[i];
			return 1;
		}
		i++;
	}
	return -1;
     


}	

	void input_DMHH(char* filename)
{
    char mahang_input[5];
    HangHoa hh_temp;

    HangHoa my_dmhh[MAX_AMOUNT];

    int count = read_DMHH(filename, my_dmhh);
    printf_DMHH(my_dmhh, count);

    printf("Nhap hang moi: Nhap EXIT de thoat\n\n");

    while (1)
    {
        printf("Ma hang : \n");
        fflush(stdin);
        gets(mahang_input);

        if (strncmp(mahang_input, "EXIT", 4) == 0)
        {
            break;
        }

        int found = find_HH_by_ma(mahang_input, my_dmhh, count, &hh_temp);

        if (found != 0)
        {
            printf("Ten hang : %s\n", hh_temp.tenhang);

            printf("So luong : ");
            scanf("%d", &hh_temp.soluong);

            printf("Don gia : ");
            scanf("%f", &hh_temp.dongia);

            hh_temp.thanhtien = hh_temp.soluong * hh_temp.dongia;
            printf("\nThanh tien : %f", hh_temp.thanhtien);

            my_dmhh[found - 1] = hh_temp;
        }
        else
        {
            strcpy(hh_temp.mahang, mahang_input);
            printf("Ten hang: ");
            fflush(stdin);
            gets(hh_temp.tenhang);

            printf("So luong : ");
            scanf("%d", &hh_temp.soluong);

            printf("Don gia : ");
            scanf("%f", &hh_temp.dongia);

            hh_temp.thanhtien = hh_temp.soluong * hh_temp.dongia;
            printf("\nThanh tien : %f", hh_temp.thanhtien);

            count++;
            my_dmhh[count - 1] = hh_temp;
        }
    }

    

	int i =0;
	FILE *outfile = fopen(filename, "w");
	for( i=0; i< count; i++)
	{
		fwrite(&my_dmhh[i], sizeof(HangHoa), 1, outfile);
		
	}
	fclose(outfile);

}



int main()
{
    HangHoa h1 = {"A001", "man", 3, 10000, 30000};
	HangHoa h2 = {"A002", "xoai", 4, 20000, 80000};
	HangHoa h3 = {"A003", "mang cut", 5, 50000, 250000};
  		
    FILE* outfile = fopen("DMHH.DAT", "w");
    
    fwrite(&h1, sizeof(HangHoa), 1, outfile);
    fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    
    if (fwrite!=0)
        printf("\nwrite file successfully\n");
    else
	    printf("\nERROR! write file unsuccessfully\n");
       
     fclose(outfile); 
	 
	 int n=0;
	 HangHoa* mydmhh= read_DMHH("DMHH.DAT", &n);
	 
	 printf("\nDanh sach tren co %d mon hang\n ", n);
	 printf_DMHH(mydmhh, n);


    
     HangHoa hhX;
	 char* mahangX = "A002";
	 int found = find_HH_by_ma(mahangX, mydmhh, n, &hhX);
	 printf("found = %d \n", found);

     if(found)
	 {

		printf("Da tim thay hang hoa co ma %s \n ", mahangX);
	    print_HH(hhX);
	 }
	 else 
	 {
		printf("Khong tim thay hang hoa co ma %s \n", mahangX);

	 }
	 return 0;

	 
		
}
