#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
<<<<<<< HEAD
void input_text_file(char* filename)
{
	FILE* outfile;
	char input_str[MAX_LINE_LENGTH];
	
	outfile= fopen(filename, "w");

	printf("Nhap van ban ben duoi. Nhan EXIT de dung nhap:\n");
	
	while(1)
	{
	   fgets(input_str, MAX_LINE_LENGTH, stdin);
	   
	if(strncmp(input_str,"EXIT",4)==0)
	   break;
	   fputs(input_str,outfile);	
    }
    fclose(outfile);
}
int main()
{
	input_text_file("mydoccument.txt");
	return 0;
}
=======
#define MAX_FILE_LENGTH 10000
void input_text_file(char *filename)
{
	printf("nhap vao van ban, nhan EXIT de thoat\n");
	FILE *outfile = fopen(filename,"w");
	char input_str[MAX_LINE_LENGTH];
	while(1)
	{
		char input_str[1000];
		fgets(input_str, 1000, stdin);
		if(strncmp(input_str,"EXIT",4)==0)
		{
			break;
		}
		fputs (input_str, outfile);
		
	}
		fclose(outfile);
}
int main(){
	input_text_file("tailieu.txt");
		
	return 0;
}

char* read_text_file(char* filename)
{
	FILE *infile = fopen(filename, "r");
	if(!infile){
		printf("\n Unable to open : %s ", filename);
		return -1;
	}
	
	char line[MAX_LINE_LENGTH];
	char* output_str;
	
	output_str = (char*) malloc(MAX_FILE_LENGTH);
	
	fgets(line, sizeof(line), infile);
	strcpy(output_str, line);
	
	while (fgets(line, sizeof(line), infile))
	strcat(output_str, line);
	
	fclose(infile);
	
	return output_str;

int main()
{	
	char* file_content = read_text_file("tailieu.txt");
	printf("%s", file_content);
	
	return 0;
}
	
}	
	
	
	
>>>>>>> 3928e3c477f1e7cffa233b3a881a6243403533a1
