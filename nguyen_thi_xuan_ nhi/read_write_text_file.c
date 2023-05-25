#include<stdio.h>
#include<stdlib.h>
#define LONG 10
int main()
{
	
	  input_text_file("xuannhi.txt");
	
	
	
	return 0;
}	
	
}	


void input_text_file(char*fileoutfile)
{
	char input_se[LONG];
   FILE* outfile=fopen("fileoutfile","W");
   printf("nhap van ban vao be trong ,muon dung nhan phim EXIT");
   while(1)
   {fgets(input_se,LONG,stdin);
   if(strncmp(input_se,"EXIT",4)==0)
   {break;}
   fputs(input_se,outfile);
   }
   fclose(outfile);
   	}
char *read_text_file(char *filename)
{
	FILE *infile = fopen(filename, "r");
	if(!infile)
	{
		printf("\n khong the mo duoc file nay ", filename );
		return -1;
	
	}
	char line[100];
	char *output_str ;
	output_str = (char*) malloc(100);
	
	fgets(line, sizeof(line), infile);
	strcpy(output_str, line);
	
	while (fgets(line, sizeof(line), infile))
	strcat(output_str, line);
	
	fclose(infile);
	return output_str;
	
	
int main()
{
	
	  read_text_file("xuannhi.txt");
	printf("%s", read_text_file);
	
	
	return 0;
}	
	
}	

	

    
 


