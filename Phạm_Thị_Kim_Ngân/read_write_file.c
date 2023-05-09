#include<stdio.h>
#include<stdlib.h>
#define MAX_LINE_LONG 50
#define MAX 500
int main()
{input_text_file("mydocument1.txt");
return 0;
}
void input_text_file(char*fileoutfile)
{
	char input_se[MAX_LINE_LONG];
   FILE* outfile=fopen("fileoutfile","W");
   printf("nhap van ban ,thoat nhan phim exit");
   while()
   {fgets(input_se,MAX_LINE_LONG,stdin);
   if(strncmp(input_se,"EXIT",4)==0)
   {break;}
   fputs(input_se,outfile);
   }
   fclose(outfile);
   	}


