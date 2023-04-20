#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 100

void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[MAX_LINE_LENGTH];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban ben duoi, nhap THOAT de dung nhap:\n");   
   
   while (1)
   {
   		fgets(input_str, MAX_LINE_LENGTH, stdin);
   
   		if (strncmp(input_str, "THOAT", 5)==0)
   			break;
			      			
   	    fputs(input_str, outfile);   	      	    
   }
   
   fclose(outfile);   
   
}
int main()
{
	input_text_file("bai1.txt");
	return 0;
}

