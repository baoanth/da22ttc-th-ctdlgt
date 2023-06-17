#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_text_file(FILE *outfile)
{
	char in_str[100];
	
	printf("Nhap noi dung van ban: \n");
	
	while(1)
	{
		fgets(in_str, 100, stdin);
		if(strncmp(in_str, "EXIT", 4)==0)
		break;
		fputs(in_str,outfile);
	}
	
	fclose(outfile);
}
/*
char *read_text_file(FILE *infile)
{
	char *out_str[100];
	char *line[100];
	
	infile = fopen ("mydocoment.txt","r");
	
	while(!foef(infile))
	{
		getline(infile,line);
		strcat(out_str,line);
	}
	
	return out_str;
}*/

int main()

{
	FILE *infile;
	FILE *outfile = fopen ("mydocoment.txt","w");
	input_text_file(outfile);
	
	
	
	return 0;
}
