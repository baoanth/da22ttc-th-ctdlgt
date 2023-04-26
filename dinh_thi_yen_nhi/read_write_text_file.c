#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
void input_text_file(FILE *fileyou)
 
{
	FILE *outfile 
	char input_str[ MAX_LINE_LENGTH];
	outfile = fopen(fileyou, "w");
	printf ("nhap van ban vao ben duoi, an EXIT de dung nhap: \n");

	while (1)
	{
		fgets(input_str, MAX_LINE_LENGTH, stdin);
		if (strncmp(input_str, "EXIT", 4)==0)
		break;
		
	
	}
	fclose (outfile)
}


