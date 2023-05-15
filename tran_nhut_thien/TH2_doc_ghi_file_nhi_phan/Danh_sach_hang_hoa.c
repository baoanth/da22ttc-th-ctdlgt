#include <stdio.h>
#include <stdlib.h>

  #define MAX_AMOUNT 200


  typedef struct {

    char mahang[5];
    char tenhang[20] ;
    int soluong ;
    float dongia ;
    float stien ;
  } Hanghoa ;
   
    int read_DMHH ( char* filename , Hanghoa * ds_Hanghoa )
     {
        FILE *file = fopen (filename , "rb");
        if (file == NULL){
            printf("failed to open file.\n");
            return -1 ;
        }
         int count = 0;
    HangHoa hh;
    while (fread(&hh, sizeof(HangHoa), 1, file) == 1 && count < MAX_AMOUNT)
	{
        ds_hanghoa[count++] = hh;
       
    }

    fclose(file);
    return count;
}


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


int  find_HH_by_ma(char* mhX, HangHoa * hh_array, int count, HangHoa* hh_kq)
{
	int i=0;
    
    while (i<count)
    {
		/
    	
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
	
	char mahang_input[5];      
	HangHoa hh_temp; 
	
	
	HangHoa my_dmhh[MAX_AMOUNT] ;
	
	int count = read_DMHH(filename, my_dmhh ); 
	print_DMHH(my_dmhh, count);          
	
	printf("Moi nhap hang hoa moi (Nhap EXIT cho ma hang de thoat):\n\n") ;	

	
	while(1) 
	{
		printf("\nMa hang: ");
		fflush(stdin);
		gets(mahang_input);
		
		if(strncmp(mahang_input,"EXIT",4)==0){
			break;
		}
		
		int fod = find_HH_by_ma(mahang_input,array,count,&hang_tam);
		
		if(fod == -1){
			
			
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
			my_dmhh[found] = hh_temp ;
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


	input_DMHH("DMHH.DAT");
	
	return 0;

}
     

   


