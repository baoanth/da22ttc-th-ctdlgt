#include <stdio.h>
#include <stdlib.h>
#define READ 1000


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[READ];  

   outfile = fopen(filename, "w");
   printf(" Nhap van ban vao ben duoi\n"); 
   printf(" Cach thoat: go EXIT + nhan phim Enter \n ");  
   
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

