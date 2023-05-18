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
	struct person per1;
	
    FILE *f = fopen("person.dat", "rb");
    
    printf("  ID|	    Ho		Ten\n");
    fread(&per1, sizeof(struct person), 1, f);
    
    while(!feof(f))
	{
    	printf("%5d%10s%13s\n", per1.id, per1.fname, per1.lname);
    	fread(&per1, sizeof(struct person), 1, f);
    }
    
    fclose(f);

    return 0;
}
