#include <stdio.h>
<<<<<<< HEAD:kim_ngọc_thiện/read_write_text_file.c
#include <stdlib.h>
#define A 100


void input_text_file(char * filename)
{
    FILE *outfile;
   char input_str[A];  

   outfile = fopen(filename, "w");
   printf("Nhap van ban o ben duoi!\nNhap EXIT + nhan phim Enter de thoat!\n");   
   
   while (1)
   {
   		fgets(input_str, A, stdin);
   
   		if (strncmp(input_str, "EXIT", 4)==0) break;
   			
   	    fputs(input_str, outfile);   	      	    
  
   }
   
   fclose(outfile);   
   
}
int main()
{
	input_text_file("README.txt");
	return 0;
}



=======
#include <stdio.h>
#define MAX_LINE_LENGHT 1000
void input_test_file(char* filename)
{  
    char input_str[MAX_LINE_LENGHT];

    FILE* outfile = fopen(filename,"w");
      printf("nhap vao van ban ben duoi,nhap EXIT de dung nhap\n");
    while(1) { 
        fgets(input_str, MAX_LINE_LENGHT, stdin);
        if (strncmp(input_str,"EXIT",4)==0);
        break;
    fputs(input_str, outfile);
    }
    fclose(outfile);
}
char* read_text_file(FILE* infile){
    char* output_str;
    char* line;
    infile = fopen("infile.txt","r");
    while(!feof(infile)){
        line = getline(&line, sizeof(char*line),1,infile);
    }
    return output_str;
}*/
int main(){
    input_test_file("outfile.txt");
    return 0;
}
>>>>>>> 4edd9f2507f0ada0109bf830381bf34a1c258bcc:kim_ngoc_thien/read_write_text_file.c
