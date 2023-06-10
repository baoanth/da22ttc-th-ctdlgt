#include <stdio.h>
#include <stdlib.h>
#define l 1000

void input_text_file(char *o)
{
	char input_str[l];
	FILE *outfile = fopen(o, "w");
	
	printf("Nhap van ban. Nhap EXIT de thoat\n");
	
	while(1)
	{
		fgets(input_str, l, stdin);
		
		if(strncmp(input_str, "EXIT", 4)==0) break;
		
		fputs(input_str, outfile);	
	}
	
	fclose(outfile);
}

int main()
{
	input_text_file("text_file.txt");	
}
