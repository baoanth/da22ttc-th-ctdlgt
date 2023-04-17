// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>

// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};


int main()
{
	struct person per1 = {1, "To", "Thuy"};
	struct person per2 = {1, "Doan", "Nguyet"};
	
	
	FILE *outfile;
	outfile= fopen("person.dat","w");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	
	if(outfile!=0)
	   printf("Write file successfully");
	else 
	   printf("ERROR! Write file successfully");
	   
	   fclose(outfile);
	
	   
    

};
