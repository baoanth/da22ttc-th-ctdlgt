#include <stdio.h>
#include <stdlib.h>
#define Freefire 1000


void input_text_file(char * filename)
{
	FILE *outfile;
	char input_str[Freefire];
	outfile =  fopen(filename, "w");
	printf("Nhap noi dung ban thich, an EXIT de khong nhap:\n");
	
	while (1)
	{
		fgets(input_str, Freefire, stdin);
		if (strncmp(input_str,"EXIT",4)==0)
		break;
		
		
		
	}
fclose(outfile);

}
int main()
{

	input_text_file("mydocument1.txt");
	return 0;
}
