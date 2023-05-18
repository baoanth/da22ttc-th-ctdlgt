#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void input_text_file(FILE *outfile)
{
	char input_str[100];
	printf("Nhap van ban , EXIT de thoat\n");
	while(1)
	{
	fgets(input_str, 100, stdin);
	if(strncmp(input_str, "EXIT",4)==0)break;
	fputs(input_str,  outfile);
		
	}
	fclose(outfile);
}
int main()
{
	FILE *outfile=fopen("mydocument.txt","w");
	input_text_file(outfile);
	printf("Da ghi thanh cong");
	return 0;
	
}
char *read_text_file(FILE *in_file) {
    char *output_str = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    in_file = fopen(in_file, "r");
    if (in_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, in_file)) != -1) {
        if (output_str == NULL) {
            output_str = line;
        } else {
            output_str = strcat(output_str, line);
        }
    }

    fclose(in_file);
    return output_str;
}

