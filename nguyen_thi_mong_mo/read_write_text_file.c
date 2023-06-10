#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_LENGTH 10000


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[MAX_LINE_LENGTH];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban vao ben duoi, an EXIT de dung nhap:\n");   
   
   while (1)
   {
   		fgets(input_str, MAX_LINE_LENGTH, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0){
   			break;
   		}
   			
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   
   fclose(outfile);   
   
}

char* read_text_file(char* filename)
{
	FILE *infile = fopen(filename, "r");	

	if(!infile){
		printf("\n Unable to open : %s ", filename);
		return -1;
	}
	
	char line[MAX_LINE_LENGTH];	// Bien tam luu tru noi dung mot dong van ban
	char* output_str  ;          // Bien Ket qua
	
	output_str = (char*) malloc(MAX_FILE_LENGTH); // Cap phat vung nho cho bien ket qua
	
		
	fgets(line, sizeof(line), infile); //Doc dong dau tien trong file
	strcpy(output_str, line);        //Dua vao bien output_str
	
	
	while (fgets(line, sizeof(line), infile)) 	// Khi con doc duoc
		strcat(output_str, line);               // Noi dong moi vao bien ket qua	
	
	fclose(infile);
	
	return output_str;	
}

int main()
{
	//input_text_file("mydocument1.txt");
	
	char* file_content = read_text_file("mydocument1.txt");
	printf("%s", file_content);
	
	
	return 0;
}
