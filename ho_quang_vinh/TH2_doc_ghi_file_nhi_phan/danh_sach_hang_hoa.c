<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#defile AMOUNT 200
type struct {
    char mahang[5];
    char tenhang[20];
    int soluong;
    float gia;
    float thanhtien;
}
   HangHoa * read_DMHH(char* filename, int *n)
int main()  
{
	FILE * infile = fopen("DMHH.dat", "rb");
	struct hanghoa hhA;
	
	
	
	printf("%5d%20d%8s%20s%10s\n", "Ma hang", "Ten hang", "So luong","Don gia","So Tien");
	
	fread(&hhA, sizeof(struct Hanghoa), 1, infile);
	

	while(!feof(infile))
	{
		printf("%5d%20d%8s%20f%10s\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hhA sotien);
		
		fread(&hhA, sizeof(struct Hanghoa), 1, infile);
	}
	
	fclose(infile);	
	return 0;
	
}
int main()
{
    struct mahang hha1 ={1, iphone, 12, 300, 2500 };
    struct mahang hhA2 ={1, iphone, 13, 500, 3500};
	struct mahang hhA3 ={1, iphone, 14, 700, 5500};
	FILE* outfile = fopen("DMHH.dat", "w");

    fwrite(&hhA1, sizeof(struct Hanghoa ), 1, outfile);
	fwrite(&hhA2, sizeof(struct Hanghoa ), 1, outfile);
	fwrite(&hhA3, sizeof(struct Hanghoa), 1, outfile);
	
	
	if (fwrite !=0)
	printf("write file successfully");
	else
	printf("EROR! write file successfully");
	fclose(outfile);

}

=======
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
	
	printf("%5s%12s%10s%20f%20s\n", "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
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
	return 0;



	
}

	
void input_DMHH(char* filename)
{
	char mahang_input[3];
	HangHoa hh_temp;
	HangHoa my_dmhh[MAX_AMOUNT];
	int count = &fread_DMHH(filename, my_dmhh);
	print_DMHH(my_dmhh, count);
	
	printf("moi nhap hang hoa moi(Nhap EXIT cho ma hang de thoat):\n\n");
	
	while(1)
	{
		printf("\nMa hang:");
		fflush(stdin);
		gets(mahang_input);
		if ( strncmp(mahang_input,"EXIT", 4)==0)
		{
			break;
		}
		int found = find_HH_by_ma(mahang_input, my_dmhh, count, &hh_temp);
		if( found!=-1)
		{
		    printf("Ten hang: %s", hh_temp.tenhang);
			printf("So luong:");
			scanf("%d", &hh_temp.soluong);
			printf("Don gia:");
			scanf("%f", &hh_temp.dongia);
			hh_temp.thanhtien = hh_temp.soluong * hh_temp.dongia;
			printf("Thanh tien: %f", hh_temp.thanhtien);
			my_dmhh[found]=hh_temp;
		}
		else
		{
		    printf("Ten hang:");
			gets(hh_temp.tenhang);
			printf("So luong:");
			scanf("%d", &hh_temp.soluong);
			printf("Don gia:");
			scanf("%f", &hh_temp.dongia);
			hh_temp.thanhtien = hh_temp.soluong * hh_temp.dongia;
			printf("Thanh tien: %f", hh_temp.thanhtien);
			count++;
			my_dmhh[count]= hh_temp;
		}
    }					
	
	int i =0;
	FILE* outfile =fopen(filename, "w");
	for(i=0; i<count; i++)
	{ 
	fwrite(&my_dmhh[i], sizeof(HangHoa), 1, outfile);
	}
	fclose(outfile);
	//my_dmhh = read_DMHH("DMHH", &count);
	
}



int main()
{
	HangHoa h1 = {"A001", "con rong", 5, 20000, 100000};
	HangHoa h2 = {"A002", "con phung", 3, 30000, 90000};
	HangHoa h3 = {"A003", "con ho", 8, 10000, 80000};
  		
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
		print_HH(hhX);

	 }
	 return -1;		
}

	
>>>>>>> 699be49ea6e9d3c0aab3541cb4d46f0831846eb1
