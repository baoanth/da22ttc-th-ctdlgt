#include<stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_LENGTH 10000

void input_text_file(char *name)
{
	printf("Nhap noi dung van ban, nhan EXIT de thoat:\n");
	while(1)
	{
		FILE *outfile = fopen(name, "w");
		char input_str[1301];
		
		fgets(input_str, 1301, stdin);
		if(strncmp(input_str, "EXIT", 4)==0)
		{
			break;
		}
		fputs(input_str, outfile);
	}
}

int main()
{
	input_text_file("tran.txt");
	
	return 0;

}


char *read_text_file(char *filename)
{
	FILE *infile = fopen(filename, "r");
	if(!infile)
	{
		printf("\n unable to open : %s ", filename );
		return -1;
	
	}
	char line[MAX_LINE_LENGTH];
	char *output_str ;
	output_str = (char*) malloc(MAX_FILE_LENGTH);
	
	fgets(line, sizeof(line), infile);
	strcpy(output_str, line);
	
	while (fgets(line, sizeof(line), infile))
	strcat(output_str, line);
	
	fclose(infile);
	return output_str;
	
	
int main()
{
	
	char* file_content = read_text_file("mydocument1.txt");
	printf("%s", file_content);
	
	
	return 0;
}	
	
	
}
	

    
 
