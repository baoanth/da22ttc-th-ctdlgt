#include <stdio.h>
#include <stdlib.h>

// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};
// ham main
int main()
{
	FILE *infile = fopen("person.dat", "rb");
	struct person perA;
	printf("%3s%12s%13s\n", "ID", "First Name", "Last Name");
	fread(&perA, sizeof(struct person), 1, infile );
	while(!feof(infile))
	{
		printf("%3d%12s%13s\n", perA.id, perA.fname, perA.lname);
		fread(&perA, sizeof(struct person), 1, infile);
		
	}
  // dong   file
    fclose(infile);
}


