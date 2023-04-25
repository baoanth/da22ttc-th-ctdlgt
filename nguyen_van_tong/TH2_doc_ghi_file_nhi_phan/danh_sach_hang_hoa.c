#include<stdio.h>

typedef struct HangHoa{
    char mahang[5];
    char tenhang[25];
    int soluong;
    float gia, thanhtien;
}HangHoa;
HangHoa * read_DMHH(char * filename, int *n){

    HangHoa* hh_array; 
    hh_array =(HangHoa*) malloc (200*sizeof(HangHoa));

    FILE *infile = fopen(filename,"rb");
    struct HangHoa hh;
    int cnt = 0;
    //printf("%15s%20s%10s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
    fread(&hh, sizeof(HangHoa), 1, infile );
    hh_array[cnt]=hh;

	while(!feof(infile))
	{
	//	printf("%15s%20s%10d%12f%12f\n", hh.mahang, hh.tenhang, hh.soluong, hh.gia, hh.thanhtien);		
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

void find_HH_by_ma(char * mahang,HangHoa* hh_array,int n ){
	int i,c = 0;
	for(i = 0;i<n;i++){
		if(strcmp(mahang,hh_array[i].mahang)==0){
			in_DMHH(&hh_array[i],1);
		} 
		if(c == 0) printf("khong tim thay");	
			
	}

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
	//in_DMHH(find_HH_by_ma(ma,mydmhh,n),n);
	find_HH_by_ma(ma,mydmhh,n);
    return 0;
}
