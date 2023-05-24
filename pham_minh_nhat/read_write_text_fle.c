#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGHT 1000

        void input_text_file(char* filename){
     	char input_str[MAX_LINE_LENGHT]; 
	
    	FILE* outfile = fopen(filename,"w") ;
		
		printf("Nhap van ban vao ben duoi, nhap EXIT de dung nhap:\n");
	while(1){
		fgets(input_str,MAX_LINE_LENGHT,stdin);
		if (strncmp(input_str,"EXIT",4)==0);
			break;
		fputs(input_str,outfile);	
	}	
	fclose(outfile);
}
/*char* read_text_file(FILE* infile){
	char* output_str;
	char* line;
	infile = fopen("infile.txt","r");
	while(!feof(infile)){
	
		  line = getline(&line, sizeof(char*line),1, infile);

	}
	return output_str;
}*/
int main(){
	input_text_file("outfile.txt");
	return 0;
}
