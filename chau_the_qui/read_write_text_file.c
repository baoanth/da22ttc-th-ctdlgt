#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_LENGTH 10000


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[MAX_LINE_LENGTH];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban vao ben duoi, an EXIT de dung nhap:\n");   
   
   while (1)
   {
   		fgets(input_str, MAX_LINE_LENGTH, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0){
   			break;
   		}
   			
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   
   fclose(outfile);   
   
}

char* read_text_file(char* filename)
{
	FILE *infile = fopen(filename, "r");	

	if(!infile){
		printf("\n Khong the mo file : %s ", filename);
		return -1;
	}
	
	char line[MAX_LINE_LENGTH];	
	char* output_str  ;          
	
	output_str = (char*) malloc(MAX_FILE_LENGTH); 
	
		
	fgets(line, sizeof(line), infile); 
	strcpy(output_str, line);       
	
	
	while (fgets(line, sizeof(line), infile)) 	
		strcat(output_str, line);               
	
	fclose(infile);
	
	return output_str;	
}

int main()
{
	input_text_file("outfile.txt");
	
	char* file_content = read_text_file("outfile.txt");
	printf("%s", file_content);
	
	
	return 0;
}
