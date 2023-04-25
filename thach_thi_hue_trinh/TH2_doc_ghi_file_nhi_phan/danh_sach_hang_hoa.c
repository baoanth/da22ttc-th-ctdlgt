#include<stdio.h>
#include <stdlib.h>
#define MAX 200


typedef struct HangHoa
{	
    char mahang[5];
    char tenhang[20];
	int soluong;
	float dongia;
	float sotien;
	float thanhtien;
};
HangHoa *read_DMHH(char* filename, int *n)
{
	HangHoa* hh_array;
	hh_array = malloc(MAX* sizeof(HangHoa));
	
	FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	int dem=0;
	
	printf("%15s|%20s|%10s|%12s|%12s \n","Ma Hang", "Ten Hang", "So Luong", "Don Gia", "Thanh Tien");
	
	
} 
    
    
	 
	 




























































































































































