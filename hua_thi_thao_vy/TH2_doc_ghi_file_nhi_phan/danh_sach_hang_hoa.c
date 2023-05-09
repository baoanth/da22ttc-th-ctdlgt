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
	
		printf("nhap ma hang ");
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
			
			array[count] = hang_tam;
			count++;
			
			printf("da them mon hang vao vi tri thu %d\n",count);
			
			in_DMHH(array,count);
		}	
		else{
		
			printf("da tim thay ma hang o vi tri thu %d\n",fod);
			
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
		int i = 0;
		FILE * outfile = fopen(filename, "w");
		for (i=0; i<count; i++)
		{ 
			fwrite(&array[i], sizeof(HangHoa), 1, outfile);
		}
		fclose(outfile);	
	}
		
}

int main(){
//    HangHoa h1 = {"A001", "carot", 5, 500, 2500};
//    HangHoa h2 = {"A002", "tomato", 5, 700, 5500};
//    HangHoa h3 = {"A003", "banana", 5, 1000, 5000};
//	FILE * outfile = fopen("DSHH.DAT", "wt");
//	
//	fwrite(&h1, sizeof(HangHoa), 1, outfile);
//	fwrite(&h2, sizeof(HangHoa), 1, outfile);
//    fwrite(&h3, sizeof(HangHoa), 1, outfile);
//    if(fwrite !=0)
//        printf("mo file thanh cong \n");
//    else 
//        printf("loi mo file");
//  fclose(outfile);
    int n;
    HangHoa* mydmhh=  read_DMHH( "DSHH.DAT", &n );

   printf("Da doc duoc %d hang hoa\n", n);
   in_DMHH (mydmhh,n);
	
//	printf("nhap ma hang can tim \n");
//	char ma[20];
//	gets(ma);
	//int n = find_HH_by_ma(ma,mydmhh,n);
	input_DMHH("DSHH.DAT",mydmhh,n);
    return 0;
}
<<<<<<< HEAD

int main()
{

    HangHoa h1 = {"A001", "nhattruong1", 5, 500, 2500};
    HangHoa h2 = {"A002", "nhattruong2", 5, 700, 5500};
    HangHoa h3 = {"A003", "nhattruong3", 5, 1000, 5000};
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
    HangHoa* mydmhh = read_DMHH( "DMHH.DAT", &n );
 
 printf("\nDanh sach tren co %d mon hang\n", n); 
 print_DMHH(mydmhh, n);
    
 return 0;
}
=======
>>>>>>> 1b6b937c7c8a0d1972e9a42bd2b4457776de332b
