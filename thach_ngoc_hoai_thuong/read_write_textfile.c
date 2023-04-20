#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[MAX_LINE_LENGTH];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban vao ben duoi, an EXIT de dung nhap:\n");   
   
   while (1)
   {
   		fgets(input_str, MAX_LINE_LENGTH, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0)
   			break;
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   
   fclose(outfile);   
   
}
int main()
{
	input_text_file("mydocument1.txt");
	return 0;
}
