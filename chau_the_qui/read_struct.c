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
	FILE *infile = fopen("person.dat","rb");
	struct person perA;
	fread(&perA, sizeof(struct person), 1, infile);
	while(!feof(infile))
	{
		printf("%5d",perA.id);
		printf("%10s",perA.fname);
		printf("%10s\n",perA.lname);
		fread(&perA, sizeof(struct person), 1, infile );
	}
	fclose(infile);
}



