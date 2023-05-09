#include <stdio.h>
#include <stdlib.h>

void input_text_file(char *filename)
{
	FILE* outfile;
	char input_str[MAX_LINE_LENGHT];
	outfile = fopen(outfile, "w");
	printf("Moi nhap van ban, an EXIT de dung nhap: \n ");
	while(1)
	{
		fgets(input_str, MAX_LINE_LENGTH, stdin);
		if (strncmp(input_str, "EXIT", 4) ==0)
		 break;
		 fputs(intput_str, outfile); 
		
		
	}
		
}
