#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200
typedef struct {
	char mahang [5];
	char tenhang [20];
	int soluong;
	float dongia;
	float sotien;
}Hanghoa;

Hanghoa* read_DMHH(char* filename,int *n)
{
    Hanghoa* hh_array;
	hh_array= malloc(MAX_AMOUNT* sizeof(Hanghoa));
    FILE *infile= fopen(filename, "rb");
    Hanghoa hhA;
    int count=0;
    
    printf("%5s%15s%15s%12s%12s\n","Ma hang","Ten hang","So luong","Don gia","So tien");
    fread(&hhA, sizeof(Hanghoa),1 ,infile);
    hh_array[count]=hhA;
 
    while(!feof(infile))
    {
	    count++;
    	printf("%5s%15s%15d%12f%12f\n",hhA.mahang, hhA.tenhang, hhA.soluong, hhA.dongia, hhA.sotien);
    	fread(&hhA, sizeof(Hanghoa),1 ,infile);
    	hh_array[count]=hhA;
    	
    }
    fclose(infile);
    *n = count;
    return hh_array;
} 

void print_DMHH(Hanghoa* hh, int n)
{

	printf("%5s%15s%15s%12s%12s\n", "Ma Hang" ,"Ten hang", "So luong", "Don gia", "So tien");	
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%15s%15d%12f%12f\n", hh[i].mahang, hh[i].tenhang, hh[i].soluong, hh[i].dongia, hh[i].sotien);	
	}
}

void print_HH(Hanghoa hh)
{
	printf("%5s%15s%15d%12f%12f\n", hh.mahang, hh.tenhang, hh.soluong, hh.dongia, hh.sotien);	
}
int find_HH_by_ma(char* mahang, Hanghoa* hh_array, int count, Hanghoa* hh_kq)
{
	int i=0;
	while (i<count)
	{
		if (strcmp(hh_array[i].mahang, mahang)==0)
		{
			*hh_kq= hh_array[i];
			return i;
		}
		i++;
	}
	return -1;
}
			   
void input_DMHH(char* filename,Hanghoa * array,int count)
{
	
	while(1)
	{
		char mahang_input[5];
	    Hanghoa hh_temp;
	    
		printf("Nhap ma hang: ");
		fflush(stdin);
		gets(mahang_input);
		
		if (strncmp(mahang_input,"EXIT",4)==0)
		{
			break;
		}
		int found = find_HH_by_ma(mahang_input,array, count, &hh_temp);
		
		if (found!=-1)
		{
			printf("\nTen hang: %s\n",hh_temp.tenhang);
			
			printf("So luong: ");
			scanf("%d",&hh_temp.soluong);
			
			printf("Don gia: ");
			scanf("%f", &hh_temp.dongia);
			
			hh_temp.sotien = hh_temp.soluong*hh_temp.dongia;
			array[count] = hh_temp;
			count++;
			
			printf("Da them mon hang vao vi tri thu %d\n",count);
			
			in_DMHH(array,count);
		}	
		else
		{
			printf("da tim thay ma hang o vi tri thu %d\n",found);
			
			printf("Ten hang: ");
			gets(hh_temp.tenhang);
			
			printf("So luong: ");
			scanf("%d",&hh_temp.soluong);
			
			printf("Don gia: ");
			scanf("%f",&hh_temp.dongia);
			
			hh_temp.sotien = hh_temp.soluong*hh_temp.dongia;
			
			printf("Da nhap duoc 1 thang moi\n",hh_temp.sotien);
			
		    in_DMHH(&hh_temp,1);
			
			array[found] = hh_temp;
		}
	}		
	
	int i=0;
	FILE* outfile=fopen(filename, "w");
	for(i=0; i<count; i++)
	{
		fwrite(&array[i], sizeof(Hanghoa),1, outfile);
	}
	fclose(outfile);
}		
		
int main()
{
	//Hanghoa h1 = {"A001","ma 1",2,10,20};
	//Hanghoa h2 = {"A002","ma 2",2,30,40};
	//Hanghoa h3 = {"A003","ma 3",2,50,60};
	//Hanghoa h4 = {"A004","ma 4",2,70,80};

	
	//FILE* outfile= fopen("DMHH.DAT","w");

	//fwrite(&h1, sizeof(Hanghoa),1,outfile);
	//fwrite(&h2, sizeof(Hanghoa),1,outfile);
	//fwrite(&h3, sizeof(Hanghoa),1,outfile);
	//fwrite(&h4, sizeof(Hanghoa),1,outfile);

	
    //if (fwrite!=0)
	//  printf("Write file successfully\n");
	//else
	//  printf("ERROR! Write file unsuccessfully\n");
	  
	//fclose(outfile);    
	
    int n;
    Hanghoa* mydmhh=  read_DMHH( "DMHH.DAT", &n );
    printf("Da doc duoc %d hang hoa\n", n);
	in_DMHH (mydmhh,n);
	
	//printf("\nDanh sach tren co %d mon hang\n", n);	
//	print_DMHH(mydmhh, n);
	
	//Hanghoa hhX;
	//char* mahangX = "A004";
	//int found=find_HH_by_ma(mahangX, mydmhh, n, &hhX);
	
//	printf("Found = %d\n",found);
	//if (found)
	//{
	//	printf("Da tim thay hang hoa co ma %s\n", mahangX);
//		print_HH(hhX);
//	}
	//else
//	{
//	printf("Khong tim thay hang hoa co ma %s\n",mahangX);
	//}	
	input_DMHH("DMHH.DAT",mydmhh,n);
 return 0;
}
		







