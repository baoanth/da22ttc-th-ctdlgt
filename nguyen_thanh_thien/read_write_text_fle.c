#include<stdio.h>
#include<string.h>
 void input_text_file(FILE *outfile )
 {
 	char input_str[100];
 	printf("Nhap doan van ban\n");
 	while (1) 
    {

 	   fgets(input_str,100,stdin);
 	   if(strncmp(input_str,"EXIT",4)== 0) break;
 	   fputs(input_str, outfile);
    }
    fclose(outfile);
}
int main()
{
	FILE *outfile = fopen("mydocumet.txt", "w");
	input_text_file(outfile);
	return 0;
	
}
