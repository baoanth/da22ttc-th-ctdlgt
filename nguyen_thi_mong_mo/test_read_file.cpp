
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 10000
int main(int argc, char* argv[])
{
	//read any text file from currect directory
	char const* const fileName = "mydocument1.txt";

	FILE* file = fopen(fileName, "r"); 

	if(!file){
		printf("\n Unable to open : %s ", fileName);
		return -1;
	}

	char* output_str;
	output_str = (char*)malloc(MAX_LENGTH); // Cap phat vung nho cho bien ket qua
	char line[500];
	fgets(line, sizeof(line), file);
	strcpy(output_str, line);
	while (fgets(line, sizeof(line), file)) 
	{
		strcat(output_str, line);
	}
fclose(file);
printf("%s", output_str);
return 0;
}
