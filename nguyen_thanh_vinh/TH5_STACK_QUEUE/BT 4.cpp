#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 200
typedef struct {
	char hoten [5];
	char tuoi [20];
	int diachi;
	float tinhtrangbenh;
	float sothutu;
}Thongtinbenhnhan;

Thongtinbenhnhan* read_DMNN(char* filename,int *n)
{
    Thongtinbenhnhan* hh_array;
	hh_array= malloc(MAX_AMOUNT* sizeof(Thongtinbenhnhan));
    FILE *infile= fopen(filename, "rb");
    Thongtinbenhnhan hhA;
    int count=0; 
    
    printf("%5s%15s%15s%12s%12s\n","ho ten","tuoi","dia chi","tinhtrangbenh","sothutu");
    fread(&hhA, sizeof(Thongtinbenhnhan),1 ,infile);
    hh_array[count]=hhA;

    while(!feof(infile))
    {
	    count++;
    	printf("%5s%15s%15d%12f%12f\n",hhA.hoten, hhA.tuoi, hhA.diachi, hhA.tinhtrangbenh, hhA.sothutu);
    	fread(&hhA, sizeof(Thongtinbenhnhan),1 ,infile);
    	hh_array[count]=hhA;
    	
    }
    fclose(infile);
    *n = count;
    return hh_array;
} 

void print_DMNN(Thongtinbenhnhan* hh, int n)
{

	printf("%5s%15s%15s%12s%12s\n", "ho ten","tuoi","dia chi","tinhtrangbenh","sothutu");
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5s%15s%15d%12f%12f\n", hh[i].hoten, hh[i].tuoi, hh[i].diachi, hh[i].tinhtrangbenh, hh[i].sothutu);	
	}
}

void print_HH(Thongtinbenhnhan hh)
{
	printf("%5s%15s%15d%12f%12f\n", hh.hoten, hh.tuoi, hh.diachi, hh.tinhtrangbenh, hh.sothutu);	
}
int find_HH_by_ma(char* hoten, Thongtinbenhnhan* hh_array, int count, Thongtinbenhnhan* hh_kq)
{
	int i=0;
	while (i<count)
	{
		if (strcmp(hh_array[i].hoten, hoten)==0)
		{
			*hh_kq= hh_array[i];
			return 1;
		}
		i++;
	}
	return 0;
}
			   
void input_DMNN(char* filename)
{
	char hoten_input[5];
	Thongtinbenhnhan hh_temp;
	
	Thongtinbenhnhan my_dmnn[MAX_AMOUNT];
	int count = read_DMNN(filename, my_dmnn);
	
	print_DMNN(my_dmnn, count);
	printf("Moi nhap ho ten moi. Nhap EXIT cho ho ten  de thoat :\n\n");
	
	while(1)
	{
		printf("Ho ten: ");
		fflush(stdin);
		gets(ho ten_input);
		
		if (strncmp(hoten_input,"EXIT",4)==0)
		{
			break;
		}
		int found = find_HH_by_ma(hoten_input,my_dmnn, count, &hh_temp);
		
		if (found!=-1)
		{
			printf("\nTuoi: %s\n",hh_temp.tuoi);
			
			printf("Dia chi: ");
			scanf("%d",&hh_temp.diachi);
			
			printf("Tinh trang benh: ");
			scanf("%f", &hh_temp.tinhtrangbenh);
			
			hh_temp.sothutu = hh_temp.diachi*hh_temp.tinhtrangbenh;
			printf("\nSo thu tu: %f\n", hh_temp.sothutu);
			
			my_dmnn[found]=hh_temp;
		}	
		else
		{
			strcpy(hh_temp.hoten,hoten_input);
			printf("Tuoi: ");
			gets(hh_temp.tuoi);
			
			printf("Dia chi: ");
			scanf("%d",&hh_temp.diachi);
			
			printf("Tinh trang benh: ");
			scanf("%f",&hh_temp.tinhtrangbenh);
			
			hh_temp.sothutu = hh_temp.dia chi*hh_temp.tinhtrangbenh;
			printf("So tien: %f",hh_temp.sotien);
			
			count++;
			my_dmhh[count]= hh_temp;
		}
	}		
	
	int i=0;
	FILE* outfile=fopen(filename, "w");
	for(i=0; i<count; i++)
	{
		fwrite(&my_dmhh[i], sizeof(Hanghoa),1, outfile);
	}
	fclose(outfile);
}		
