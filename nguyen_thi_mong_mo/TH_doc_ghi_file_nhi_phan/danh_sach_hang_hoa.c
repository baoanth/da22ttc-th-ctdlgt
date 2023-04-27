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
    
    res_dmhh = malloc(sizeof(HangHoa)*MAX_AMOUNT); //Cap phat vung nho cho danh sach hang hoa

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

/*
Ham tim kiem mot mahang trong danh sach hh_array
Tim thay thi tra chi so cua mon hang trong hh_array
Khong tim thay tra ve -1
Mon hang duoc tim thay luu trong *kq
*/
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
   // Nhap gia, soluong, tinh thanhtien = soluong*dongia
   // Dua mon hang vua nhap vao my_dmhh

   // Luu toan bo my_dmhh vao outfile, dong outfile

<<<<<<< HEAD
=======
	
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
			
			*my_dmhh[found] = hh_temp ;// Gan thong tin moi vao phan tu tuong ung trong danh muc hang hoa	
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
>>>>>>> 893882678ca3d9ebd0c2458946bbc6a081f257c1
}


int main()
{	
	HangHoa h1 = {"A001", "Macbook Pro", 5, 500, 5500};
    HangHoa h2 = {"A002", "Macbook Air", 5, 700, 5000};
    HangHoa h3 = {"A003", "Iphone 14 Pro Max", 5, 5000, 5000};
    HangHoa h4 = {"A004", "Iphone 14 plus", 5, 2000, 5000};
    
    FILE* outfile = fopen("DSHH.dat", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    fwrite(&h4, sizeof(HangHoa), 1, outfile);
    fclose(outfile);

    int count;
    
    HangHoa* my_dshh = read_DMHH("DSHH.dat", &count);

    printf("Da doc duoc %d hang hoa\n", count);
    print_DMHH(my_dshh, count);

    char* mahang = "A003";
    HangHoa hang_kq;
    int found  = find_HH_by_ma(mahang, my_dshh, count, &hang_kq);
    
    if (found)
    
        print_HH(hang_kq);
    else
        printf("Tim khong thay hang hoa co ma %s\n", mahang);

    return 0;
}
