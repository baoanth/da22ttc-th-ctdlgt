#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct HangHoa{
    char mahang[10];
    char tenhang[25];
    int soluong;
    float gia, thanhtien;
}HangHoa;
HangHoa* read_DMHH(char * filename, int *n){

    HangHoa* hh_array; 
    hh_array = (HangHoa*) malloc(1000*sizeof(HangHoa));

    FILE *infile = fopen(filename,"rb");
    struct HangHoa hh;
    int cnt = 0;
    
    fread(&hh, sizeof(HangHoa), 1, infile );
    hh_array[cnt]=hh;

	while(!feof(infile)){
		cnt++;
		fread(&hh, sizeof(HangHoa), 1, infile );        
        hh_array[cnt]=hh;
	}
	
	fclose(infile);
	*n = cnt;
    return hh_array;

}
void in_DMHH(HangHoa *hh,int n)
{
	printf("%10s%25s%15s%12s%20s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien"); 
	int i;
    for( i = 0; i< n; i++){
        printf("%10s%25s%10d%16.0f%18.0f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].gia, hh[i].thanhtien);
    }
		
}

int find_HH_by_ma(char * mahang,HangHoa* hh_array,int n,HangHoa*kq ){
	int i;
	for(i = 0;i<n;i++){
		if(strcmp(mahang,hh_array[i].mahang)==0){
			kq = hh_array[i];
            return 1;
		} 		
	}
	return -1;
}


int main(){
    HangHoa h1 = {"A001", "Iphone 12", 5, 500, 2500};
    HangHoa h2 = {"A002", "Iphone 13", 5, 700, 5500};
    HangHoa h3 = {"A003", "Iphone 14", 5, 1000, 5000};
	FILE * outfile = fopen("DSHH.DAT", "w");
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    if(fwrite !=0)
        printf("mo file thanh cong \n");
    else 
        printf("loi mo file");
    fclose(outfile);
    int n;
    HangHoa* mydmhh=  read_DMHH( "DSHH.DAT", &n );

    printf("Da doc duoc %d hang hoa\n", n);
    in_DMHH (mydmhh,n);
	
	printf("nhap ma hang can tim \n");
	char ma[20];
	gets(ma);
	find_HH_by_ma(ma,mydmhh,n);
    return 0;
}
