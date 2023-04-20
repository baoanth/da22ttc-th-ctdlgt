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

int main()
{
	FILE *outfile = fopen("mydocument.txt", "w");
	input_text_file(outfile);
	printf("Da ghi file thanh cong");
	return 0;
}
