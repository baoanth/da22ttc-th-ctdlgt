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
HangHoa * read_DMHH(char* filename, int *n)
{
    HangHoa*  hh_array;
    
    hh_array =  malloc(MAX_AMOUNT* sizeof(HangHoa));
    
    FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int count =0;
		
	
	 
	
	
