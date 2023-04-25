#include<stdio.h>
#include<stdlib.h>
#define MAX_LINE_LONG 10
#define MAX 100
int main()
{input_text_file("mydocument1.txt");
return 0;
}
void input_text_file(char*fileoutfile)
{
	char input_se[MAX_LINE_LONG];
   FILE* outfile=fopen("fileoutfile","W");
   printf("nhap van ban vao be trong ,muon dung nhan phim EXIT");
   while(1)
   {fgets(input_se,MAX_LINE_LONG,stdin);
   if(strncmp(input_se,"EXIT",4)==0)
   {break;}
   fputs(input_se,outfile);
   }
   fclose(outfile);
   	}


