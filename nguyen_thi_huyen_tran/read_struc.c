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
	struct person perA;  
	FILE* infile= fopen ("person.dat", "rb");
	
    fread(&perA, sizeof(struct person),1, infile);
    printf("%5s%13s%13s\n","ID" ,"FNAME" ,"LNAME");
    
	while(!feof(infile))
	{
		 printf("%5d%13s%13s\n", perA.id, perA.fname, perA.lname);
		  fread(&perA, sizeof(struct person),1, infile);
	}
	
	 fclose (infile);
}
