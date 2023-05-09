#include<stdio.h>
#include<stdlib.h>

int main()
{
	 input_text_file("mydocument1.txt");
	 return 0;
}
void input_text_file(char *fileoutfilee)
{   char input_str[100];
	FILE*outfilee=fopen(fileoutfilee,"w");
	printf("\nnhap thong tin neu muon dung nhan  EXIT");
    while(1)
	{
		fgets(input_str,100,stdin);
		if(strncmp(input_str,"EXIT",4)==0)
		break;
		fputs(input_str,outfilee);
    }
    fclose(outfilee);
}
