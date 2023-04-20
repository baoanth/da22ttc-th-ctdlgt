#include <stdio.h>
#include <stdlib.h>

void input_text_fle(FILE *outfile)
{
	char in_str[100];
	
	printf("Nhap noi dung van ban: ");
	
	while(1)
	{
		fgets(in_str, 100, stdin);
		if(strncmp(in_str, "EXIT", 4)==0)
		break;
		fputs(in_str,outfile);
	}
	
	fclose(outfile);
}

int main()

{
	FILE *outfile = fopen ("mydocoment.txt","w");
	input_text_fle(outfile);
	
	return 0;
}
