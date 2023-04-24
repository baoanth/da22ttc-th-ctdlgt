#include <stdio.h>
#include <string.h>
void input_text_file(char *name)
{
	printf("nhap vao van ban, nhan EXIT de thoat\n");
	FILE *outfile = fopen(name,"w");
	while(1)
	{
		char input_str[1000];
		fgets(input_str, 1000, stdin);
		if(strncmp(input_str,"EXIT",4)==0)
		{
			break;
		}
		fputs (input_str, outfile);
		
	}
		fclose(outfile);
}
int main(){
	input_text_file("tailieu.txt");
		
	return 0;
}
