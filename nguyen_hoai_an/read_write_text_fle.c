#include<stdio.h>
#include<stdlib.h>

void input_text_file (char *filename)
{
	    FILE *outfile;
   char input_str[1000];  

   outfile = fopen(filename, "w");
   printf("Yeu cau nhap van ban, nhan EXIT de ket thuc\n");
   
   while(1)
     {
     	 fgets(input_str, 1000 , stdin);
     	
     	if(strncmp(input_str, "EXIT", 4)==0)
     	 break;
     	 
     	 fputs(input_str, outfile);
     }
	
	fclose(outfile);
}

int main()
{
	input_text_file("Mydocument29");
	return 0;
}
