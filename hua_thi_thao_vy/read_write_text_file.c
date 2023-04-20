#include<stdio.h>
#include<string.h>
void input_text_file(char *name)
{
	printf("nhap van ban, nhan EXIT de thoat\n");
	while(1)
	{
		FILE *outfile = fopen(name, "w");
		char input_str[1000];
		
		fgets(input_str, 1000, stdin);
		if(strncmp(input_str, "EXIT", 4)==0)
		{
			break;
		}
		fputs (input_str, outfile);
	}
}

int main()
{
	input_text_file("tailieu.txt");
	
	return 0;
}
