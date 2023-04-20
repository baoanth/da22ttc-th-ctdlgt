#include <stdio.h>
#include <stdlib.h>
void input_text_file(char *t)
{
	char input_str[100];
	FILE *outfile = fopen(t, "w");
	
	printf("Nhap van ban. Nhap EXIT de thoat\n");
	
	while(1)
	{
		fgets(input_str, 100, stdin);
		
		if(strncmp(input_str, "EXIT", 4)==0) break;
		
		fputs(input_str, outfile);	
	}
	
	fclose(outfile);
	
}

int main()
{
	input_text_file("text_file.txt");	
}
