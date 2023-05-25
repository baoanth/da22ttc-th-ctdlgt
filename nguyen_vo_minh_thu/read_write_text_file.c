#include<stdio.h>
#include<stdio.h>
#define MINHTHU 1000


void input_text_file(char * filename)
{
	FILE *outfile;
	char input_str[MINHTHU];
	
	outfile = fopen(filename,"w");
	printf("Nhap van ban ben duoi, nhan EXIT de dung nhap:\n");
	
	while (1)
	{
		fgets(input_str,MINHTHU,stdin);
		
		if (strncmp(input_str, "EXIT",4)==0)
				break;
			
		fputs(input_str, outfile);
		
	}
	
	fclose(outfile);
	
}
int main()
{
	input_text_file("minhthuxd.txt");
	return 0;
}

