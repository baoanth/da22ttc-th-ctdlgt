#include <stdio.h>
#include <string.h>

void input_text_file(FILE *outfile)
{
	char input_str[100];
	printf("Hay nhap doan van ban ben duoi: \n");
	while(1)
	{
		fgets(input_str, 100, stdin);
		if (strncmp(input_str, "EXIT", 4) == 0) break;
		fputs(input_str,outfile);
	}
	fclose(outfile);
}

//char *read_text_file(FILE *infile)
//{
//	char *output_str[100];
//	char *line[100];
//	infile = fopen("mydocument.txt", "r");
//	while(!feof(infile))
//	{
//		getline(infile, line);
//		strcat(output_str,line);
//	}
//	return output_str;
//} 
int main()
{
//	char document[100];
//	FILE *infile;
	FILE *outfile = fopen("mydocument.txt", "w");
	input_text_file(outfile);
	printf("Da ghi file thanh cong");
//	strcpy(document, read_text_file(infile));
//	puts(document);
	return 0;
}
