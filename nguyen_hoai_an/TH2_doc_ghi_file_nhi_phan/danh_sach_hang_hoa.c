#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct HangHoa{
    char mahang[15];
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
	printf("%10s %25s %15s %12s %20s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien"); 
	int i;
    for( i = 0; i< n; i++){
        printf("%10s %25s %10d %16.0f %18.0f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].gia, hh[i].thanhtien);
    }
		
}

int find_HH_by_ma(char * mahang,HangHoa* hh_array,int n,HangHoa*kq ){
	int i;
	for(i = 0;i<n;i++){
		if(strcmp(mahang,hh_array[i].mahang)==0){
			*kq = hh_array[i];
            return i;
		} 		
	}
	return -1;
}
void input_DMHH(char* filename,HangHoa * array,int count){
	FILE *outfile = fopen(filename,"rb");

	while(1){
		char mahang_input[10];
		HangHoa hang_tam;
	
		printf("Nhap ma hang: ");
		fflush(stdin);
		gets(mahang_input);
		
		if(strncmp(mahang_input,"EXIT",4)==0){
			break;
		}
		
		int fod = find_HH_by_ma(mahang_input,array,count,&hang_tam);
		
		if(fod == -1){
			
			//strcpy(mahang_input,tmp);
			strcpy(hang_tam.mahang,mahang_input);
			printf("Nhap ten hang: ");
			fflush(stdin);
			gets(hang_tam.tenhang);
			
			printf("Nhap so luong: ");
			scanf("%d",&hang_tam.soluong);
			
			printf("Nhap don gia: " );
			scanf("%f",&hang_tam.gia);
			
			hang_tam.thanhtien = hang_tam.gia*hang_tam.soluong;
			
			array[count] = hang_tam;
			count++;
			
			printf("Da them mon hang vao vi tri thu %d\n",count);
			
			in_DMHH(array,count);
		}	
		else{
		
			printf("Da tim thay ma hang o vi tri thu %d\n",fod);
			
			printf("\nTen hang: ");
			printf("%s",hang_tam.tenhang);
			
			printf("\nSo luong moi: ");
			scanf("%d",&hang_tam.soluong);
			
			printf("\nDon gia: ");
			scanf("%f",&hang_tam.gia);
		
			
			hang_tam.thanhtien = hang_tam.soluong*hang_tam.gia;
			
			printf("Da nhap duoc 1 mon hang moi. \n");
			in_DMHH(&hang_tam,1);
			
			array[fod] = hang_tam;
		}
		int i = 0;
		FILE * outfile = fopen(filename, "w");
		for (i=0; i<count; i++)
		{ 
			fwrite(&array[i], sizeof(HangHoa), 1, outfile);
		}
		fclose(outfile);	
	}
		
}

<<<<<<< HEAD
void find_HH_by_ma(char * mahang, *HangHoa hh_array,int n)
      {
	     int i;
	     for(i=0;i<n;i++){
		    if(strcmp(mahang,hh_array[i].mahang)==0)
		    in_DMHH(&hh_array[i],1)
		 }
      }

void input_DMHH(char* filename)
{
	int count;

}

int main()
{
	Hanghoa h1 = {"A0101","Sua Co gai Ha Lan", 10, 20000, 200000};
    Hanghoa h2 = {"B0101", "Sua Ong Tho", 15, 10000, 150000};

	FILE* outfile = fopen("DMHH.DAT", "wb");
=======
int main(){
    HangHoa h1 = {"A001", "Kem chuoi", 5, 5000, 25000};
    HangHoa h2 = {"A002", "Kem dau", 5, 7000, 35000};
    HangHoa h3 = {"A003", "Kem bac ha", 5, 10000, 50000};
	FILE * outfile = fopen("DSHH.DAT", "wt");
>>>>>>> f1753be805e9556774760784a8f41b2ccab284a9
	
	fwrite(&h1, sizeof(HangHoa), 1, outfile);
	fwrite(&h2, sizeof(HangHoa), 1, outfile);
    fwrite(&h3, sizeof(HangHoa), 1, outfile);
    if(fwrite !=0)
        printf("---Mo file thanh cong--- \n");
    else 
        printf("Loi mo file.");
  fclose(outfile);
    int n;
    HangHoa* mydmhh=  read_DMHH( "DSHH.DAT", &n );

   printf("Da doc duoc %d hang hoa.\n", n);
   in_DMHH (mydmhh,n);
	
<<<<<<< HEAD
	printf("\nDanh sach tren co %d mon hang\n", n);	
	print_DMHH(mydmhh, n);
	return 0;
	
}
=======
//	printf("nhap ma hang can tim \n");
//	char ma[20];
//	gets(ma);
	//int n = find_HH_by_ma(ma,mydmhh,n);
	input_DMHH("DSHH.DAT",mydmhh,n);
    return 0;
}
>>>>>>> f1753be805e9556774760784a8f41b2ccab284a9
