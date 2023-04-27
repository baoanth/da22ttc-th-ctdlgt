#include<stdio.h>
#include<stdio.h>

 void input_text_file 
 (FILE * outfile)
{
	char input_str[100];
	printf("Hay nhap khuc van ban ben duoi:\n");
	while (1)
	{
		fgets(input_str,100,stdin);
		if (strncmp(input_str , "EXIT", 4) == 0) break;
		fputs (input_str,outfile);
		
	}
	fclose(outfile);
	
}
int main()
{
	FILE * outfile = fopen("mydoccument.txt","W");
	input_ text_ file(outfile);
	printf("da ghi file thang cong");
	return 0;
}
