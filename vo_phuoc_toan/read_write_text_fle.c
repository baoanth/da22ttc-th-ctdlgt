#include <stdio.h>
#include <stdlib.h>
#define IAMTOAN 1000


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[IAMTOAN];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban vao ben duoi, an EXIT de dung nhap:\n");   
   
   while (1)
   {
   		fgets(input_str, IAMTOAN, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0)
   			break;
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   printf("Chuong trinh ket thuc, da luu vao vo_phuoc_toan");
   
   fclose(outfile);   
   
}
int main()
{
	input_text_file("vo_phuoc_toan.txt");
	return 0;
}














