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
    FILE *infile = fopen("person.dat", "rb");
    struct person perA;
    
    printf("%2s |%5s|%5s |\n", "ID", "First Name", "Last name");
    printf("---|----------|----------|\n");

    //doc 1 person
    
    fread(&perA, sizeof(struct person), 1, infile );
    
    while(!feof(infile))
    {
    	printf("%2d | %8s | %8s |\n", perA.id, perA.fname, perA.lname);
    	
    	//Doc 1 cau truc person
    	 
    	fread(&perA, sizeof(struct person), 1, infile);
    	
    }
    fclose(infile);
}
