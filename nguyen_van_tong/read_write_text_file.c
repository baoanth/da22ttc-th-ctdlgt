#include <stdio.h>
#include<string.h>
void input_text_file(char *name){
	printf("nhap vao van ban, nhan EXIT de thoat\n");
	FILE *outfile = fopen(name,"w");
	while(1){
		//FILE *outfile = fopen(name,"w"); 
		char input_str[1000];
	
		fgets(input_str, 1000, stdin);
		if(strncmp(input_str,"EXIT",4)==0){
			break;
		}
		fputs (input_str, outfile);
		
	}
		fclose(outfile);

}
char *text(FILE *infile){
	char out_str[1000],line[1000];
	infile = fopen ("tailieu.txt", "r");
	while (!feof(infile)){
		fgets(&line,1000,infile);
		strcat(out_str,line);
			
	}
	return out_str;
}


int main(){
	FILE *out_file;
	input_text_file("tailieu.txt");
	printf("%s", text(out_file));	
	return 0;
}
