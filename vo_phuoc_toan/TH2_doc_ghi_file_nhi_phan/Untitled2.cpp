// C program for reading
// struct from a file
#include<stdio.h>
#include<stdlib.h>
#define MAX_AMOUNT 1103

typedef struct{
    char mahang[5] ;
    char tenhang[20];
    int soluong;
    float gia;
    float thanhtien;
}HangHoa;

//Ham doc danh sach hang hoa tu filename
//So luong mau tin doc duoc  duoc luu tru trong bien n
HangHoa * read_DMHH(char* filename, int *n)
{
    HangHoa*  hh_array;
    
    hh_array =  malloc(MAX_AMOUNT* sizeof(HangHoa));
    
    FILE *infile = fopen(filename, "rb");
 HangHoa hhA;
 int count =0;
 
 printf("%15s%20s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien"); 
 //thu doc 1 person 
 fread(&hhA, sizeof(HangHoa), 1, infile );
 hh_array[count]=hhA;

 //Duyet file cho den khi gap EOF
 while(!feof(infile))
 { //In perA ra man hinh
  printf("%15s%20s%10d%12f%12f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hhA.thanhtien); 
  
  //Doc mot cau truc person dua vao perA  
  count++;
  fread(&hhA, sizeof(HangHoa), 1, infile );        
        hh_array[count]=hhA;
 }
 
 fclose(infile);
 *n = count;
    return hh_array;
}

// Ham in n mau tin trong danh sach hang hoa ra man hinh
void print_DMHH(HangHoa* hh, int n)
{
 printf("%10s%25s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien"); 
 int i;
 for (i=0; i<n; i++)
 {
  printf("%10s%25s%10d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].gia, hh[i].thanhtien); 
 }
}

void input_DMHH(char* filename)
{
 int count;
 //my_dmhh = read_DMHH("DMHH", &count);
}

int main()
{

 HangHoa h1 = {"A001", "Iphone 12", 5, 500, 2500};
    HangHoa h2 = {"A002", "Iphone 13", 5, 700, 5500};
    HangHoa h3 = {"A003", "Iphone 14", 5, 1000, 5000};
 FILE* outfile = fopen("DMHH.DAT", "w");
 
 fwrite(&h1, sizeof(HangHoa), 1, outfile);
 fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
 
 if (fwrite!=0)
  printf("Viet tap tin thanh cong\n");
 else
  printf("LOI! Viet tap tin khong thanh cong\n");
 fclose(outfile);   

    int n=0;
    HangHoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );
 
 printf("\nDanh sach tren co %d mon hang\n", n); 
 print_DMHH(mydmhh, n);
    
 return 0;
}

