#include <stdio.h>
#include <stdlib.h>
#define A 100


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[A];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban o ben duoi!\nNhap EXIT + nhan phim Enter de thoat!\n");   
   
   while (1)
   {
   		fgets(input_str, A, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0) break;
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   
   fclose(outfile);   
   
}
int main()
{
	input_text_file("README.txt");
	return 0;
}
