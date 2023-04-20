#include<stdio.h>
#include<stdlib.h>
#define GIA_THINH 1301


void input_text_file(char *filename)
{
	FILE *outfile;
	char input_str[GIA_THINH];  

	outfile = fopen(filename, "w");
	printf("Nhap vao van ban ma ban muon nhap, an EXIT de dung nhap:\n");   
   
	while(1)
	{
   		fgets(input_str, GIA_THINH, stdin);
   
   		if(strncmp(input_str, "EXIT", 4)==0)
   			break;
   			
   	    fputs(input_str, outfile);   	      	    
  
	}
   
	fclose(outfile);   
   
}
int main()
{
	input_text_file("giathinh.txt");
	return 0;
}
