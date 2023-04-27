/*
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

typedef struct HangHoa{
	int stt;
    char mahang[6];
    char tenhang[20];
    int soluong;
    float dongia;
    float sotien;
}HangHoa;

HangHoa* read_DMHH(char* filename, int* count){
    FILE *infile = fopen(filename, "rb");
    HangHoa hhA;
    HangHoa *dmhh;
    int i = 0;

    dmhh = malloc(sizeof(HangHoa)*MAX_SIZE);
    dmhh[i] = hhA;

	fread(&hhA, sizeof(HangHoa), 1, infile );
	
	printf("%5s %10s %15s %10s %20s %20s\n", "STT", "MA HANG", "TEN HANG", "SO LG", "DON GIA", "SO TIEN");
	while(!feof(infile))
	{	
		printf("%5d %10s %15s %10d %20.2f %20.2f\n", hhA.stt, hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);	
		fread(&hhA, sizeof(HangHoa), 1, infile );
        i++;
        dmhh[i] = hhA;
	}

	fclose(infile);

    *count = i;
    return dmhh;
}

void print_HH(HangHoa h)
{
    printf("\n%10s%15s%10d%20.2f%20.2f", h.mahang, h.tenhang, h.soluong, h.dongia, h.sotien);	
}

int find_HH_by_ma(char* mahang, HangHoa* hh_array, int count, HangHoa* kq)
{
    
    int i=0;
    
    while (i<count)
    {
		printf("\nMa hang: %s ", hh_array[i].mahang);
    	
        if( strcmp(hh_array[i].mahang, mahang )==0)        
        {
        	*kq= hh_array[i];
        	return i;
        }             
        i++;
	}
	return  -1;
}

int main()
{
	HangHoa hh1 = {1, "A1010", "PsP", 167, 2500, hh1.soluong*hh1.dongia};
    HangHoa hh2 = {2, "A1011", "Ps2", 286, 5000, hh2.soluong*hh2.dongia};
    HangHoa hh3 = {3, "A1012", "Ps3", 965, 8500, hh3.soluong*hh3.dongia};
    HangHoa hh4 = {4, "A1013", "Ps4", 5790, 15000, hh4.soluong*hh4.dongia};
    HangHoa hh5 = {5, "A1014", "Ps5", 10790, 50000, hh5.soluong*hh5.dongia};
	FILE* outfile = fopen("dmhh.dat", "wb");
	
	fwrite(&hh1, sizeof(HangHoa), 1, outfile);
    fwrite(&hh2, sizeof(HangHoa), 1, outfile);
    fwrite(&hh3, sizeof(HangHoa), 1, outfile);
    fwrite(&hh4, sizeof(HangHoa), 1, outfile);
    fwrite(&hh5, sizeof(HangHoa), 1, outfile);
	
	fclose(outfile);
    
    int count;

    HangHoa* myhh = read_DMHH("dmhh.dat", &count);

    printf("\nDa nhap thanh cong %d hang hoa", count);

    char* mahang = "A1010";
    HangHoa hang_kq;
    int found  = find_HH_by_ma(mahang, myhh, count, &hang_kq);
    
    if (found)
    
        print_HH(hang_kq);
    else
        printf("Tim khong thay hang hoa co ma %s\n", mahang);

	return 0;
}
*/
// C program for reading
// struct from a file
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

//Ham doc danh sach hang hoa tu filename
//So luong mau tin doc duoc  duoc luu tru trong bien n
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
        //print_HH(hh);
    }

    fclose(file);
    return count;
}

// Ham in n mau tin trong danh sach hang hoa ra man hinh
void print_DMHH(HangHoa* hh, int n)
{
	printf("%10s%25s%10s%22s%22s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10s%25s%10d%22.2f%22.2f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].gia, hh[i].thanhtien);	
	}
}
void print_HH(HangHoa hh)
{
	printf("%10s%25s%10d%12f%12f\n", hh.mahang, hh.tenhang, hh.soluong, hh.gia, hh.thanhtien);	
	
}

/*
Ham tim hang hoa theo ma mhX trong danh sach hh_array 
Input: 
	mhX: ma hang can tim
	hh_array: danh sach hang hoa
	count: so phan tu cua hh_array
	hh_kq: mon hang tim duoc
Output:
	-1: neu khong tim thay ma hang
	i>= 0: chi so cua phan tu tim duoc trong mang hh_array	
*/
int  find_HH_by_ma(char* mhX, HangHoa * hh_array, int count, HangHoa* hh_kq)
{
	int i=0;
    
    while (i<count)
    {
		//printf("Ma hang: %s \n ", hh_array[i])   ;
    	
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
	
	char mahang_input[5];      // Bien tam luu ma hang duoc nhap tu ban phim
	HangHoa hh_temp; // Bien tam de luu hang hoa moi duoc nhap tu ban phim hoac duoc tim ra tu danh sach;
	
	
	HangHoa my_dmhh[MAX_AMOUNT] ;
	
	int count = read_DMHH(filename, my_dmhh ); // Doc danh muc hang hoa vao danh sach
	print_DMHH(my_dmhh, count);          // In danh muc hang hoa ra de quan sat
	
	printf("Moi nhap hang hoa moi (Nhap EXIT cho ma hang de thoat):\n\n") ;	

	
	while(1) // Cho nhap den khi nhap mahang bang EXIT thi dung
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
			
			my_dmhh[found] = hh_temp ;// Gan thong tin moi vao phan tu tuong ung trong danh muc hang hoa	
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
			
			
			my_dmhh[count] = hh_temp; // Noi mon hang moi vao cuoi danh muc hang hoa		
			count++;
			printf("Them mon hang moi vao vi tri thu %d\n\n", count);
			print_DMHH(my_dmhh,count);
		}
	}
	// Ghi danh muc hang hoa vao file
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

	HangHoa h1 = {"A001", "PS5", 4512, 6000, h1.soluong*h1.gia};
    HangHoa h2 = {"A002", "XBOX ONE", 6326, 7000, h2.soluong*h2.gia};
    HangHoa h3 = {"A003", "NINTENDO SWITCH", 8526, 10000, h3.soluong*h3.gia};
    HangHoa h4 = {"A004", "XBOX 360", 8527, 50000, h4.soluong*h4.gia};
    HangHoa h5 = {"A005", "IPHONE XV", 9626, 150000, h5.soluong*h5.gia};
	FILE* outfile = fopen("DMHH.DAT", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fwrite(&h4, sizeof(HangHoa), 1, outfile);
    fwrite(&h5, sizeof(HangHoa), 1, outfile);

	fclose(outfile);   
/*
    int n=0;
    HangHoa* mydmhh;
	n =  read_DMHH( "DMHH.DAT", mydmhh );
	
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	
	HangHoa hhX;
	char* mahangX = "A005";
	int found = find_HH_by_ma(mahangX, mydmhh, n, &hhX);
	
	printf("Found = %d\n ", found);
	if (found)
	{
		printf("Da tim thay hang hoa co ma %s\n", mahangX );
		print_HH(hhX);
	}
	else
	{
		printf("KHONG tim thay hang hoa co ma %s\n", mahangX );
	}
*/
	input_DMHH("DMHH.DAT");
	
	return 0;

}



