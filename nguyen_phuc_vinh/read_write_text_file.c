#include <stdio.h>
#include <string.h>

void input_text_file(char *text)
{
	printf("Moi ban nhap van ban:\n");
	FILE *outfile = fopen(text, "w");
	while(1)
		{
			char input_str[1000];
			
			fgets(input_str, 1000, stdin);
			
			if(strncmp(input_str, "EXIT", 4)==0){
				break;
			}
			
			fputs(input_str, outfile);
		}
		
		fclose(outfile);
}

char *read_text_file(FILE *infile)
{
	char *output_str;
	char *line;
	infile = fopen("tailieunhap.txt", "rb");
	
	while(!feof(infile))
	{	
		fgets(&line, )
	}
} 


int main()
{
	input_text_file("tailieunhap.txt");
	
	return 0;	
}
