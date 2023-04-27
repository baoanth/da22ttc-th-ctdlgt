#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define READ 1000


void input_text_file(char * filename)
{
   
   char *read_text_file( FILE infile);
   char* output_str
   char* line
   infile = fopen(filename, "rt");
   
   while (1)
   {
   		fgets(input_str, READ, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0)
   			break;
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   
   fclose(outfile);   
   
}
int main()
{
	input_text_file("read_infomation.txt");
	return 0;
}

