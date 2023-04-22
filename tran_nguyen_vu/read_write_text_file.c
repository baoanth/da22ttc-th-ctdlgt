#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 100


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[MAX_LINE_LENGTH];  

   outfile = fopen(filename, "t");
   printf("Nhap van ban vao ben duoi: \n");   
   
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
	printf( "Da ghi FILE thanh cong");
	return 0;
}


