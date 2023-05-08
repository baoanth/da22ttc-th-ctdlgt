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
	printf("%10s%25s%15s%12s%20s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien"); 
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
		
		if(strncmp(mahang_input,"EXIT",4)==0){
			break;
		}
		
		int fod = find_HH_by_ma(mahang_input,array,count,&hang_tam);
		
		if(fod == -1){
			
			//strcpy(mahang_input,tmp);
			strcpy(hang_tam.mahang,mahang_input);
			printf("nhap ten hang ");
			fflush(stdin);
			gets(hang_tam.tenhang);
			
			printf("nhap so luong ");
			scanf("%d",&hang_tam.soluong);
			
			printf("nhap don gia " );
			scanf("%f",&hang_tam.gia);
			
			hang_tam.thanhtien = hang_tam.gia*hang_tam.soluong;
			
<<<<<<< HEAD
=======
			array[count] = hang_tam;
			count++;
			
			printf("da them mon hang vao vi tri thu %d\n",count);
			
>>>>>>> e83868d7239dcb3298d896b87e3a8165c1cb0ec9
			my_dmhh[found] = hh_temp ;// Gan thong tin moi vao phan tu tuong ung trong danh muc hang hoa	
		}
		else
		{
			strcpy(hh_temp.mahang, mahang_input);
			
			printf("ten hang \n");
			printf("%s",hang_tam.tenhang);
			
			printf("\nso luong moi ");
			scanf("%d",&hang_tam.soluong);
			
			printf("don gia ");
			scanf("%f",&hang_tam.gia);
		
			
			hang_tam.thanhtien = hang_tam.soluong*hang_tam.gia;
			
			printf("da nhap duoc 1 thang moi\n");
			in_DMHH(&hang_tam,1);
			
			array[fod] = hang_tam;
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

/*	HangHoa h1 = {"A001", "Iphone 12", 5, 500, 2500};
    HangHoa h2 = {"A002", "Iphone 13", 5, 700, 5500};
    HangHoa h3 = {"A003", "Iphone 14", 5, 1000, 5000};
    HangHoa h4 = {"A004", "Iphone 14 pro", 5, 1300, 6500};
    HangHoa h5 = {"A005", "Iphone 14 pro max", 5, 1500, 7500};
	FILE* outfile = fopen("DMHH.DAT", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fwrite(&h4, sizeof(HangHoa), 1, outfile);
    fwrite(&h5, sizeof(HangHoa), 1, outfile);
	
	if (fwrite!=0)
		printf("Write file successfully\n");
	else
		printf("ERROR! Write file unsuccessfully\n");
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