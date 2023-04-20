#include<stdio.h>
#include<string.h>

void input_text_file(char *name)
{
	printf("Nhap vao van ban, nhan EXIT de thoat:\n");
	while(1)
	{
		FILE *outfile = fopen(name, "w");
		char input_str[1301];
		
		fgets(input_str, 1301, stdin);
		if(strncmp(input_str, "EXIT", 4)==0)
		{
			break;
		}
		fputs(input_str, outfile);
	}
}

int main()
{
	input_text_file("giathinh.txt");
	
	return 0;
}
