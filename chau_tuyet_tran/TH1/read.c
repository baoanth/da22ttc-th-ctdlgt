#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
	int id;
	char fname[20];
	char lname[20];
};

int main()
{
	FILE *infile = fopen ("person.dat","rb");
	struct person perA;
	
	printf ("| %5s | %12s | %12s |\n", "ID","First Name","Last Name");
	
	fread (&perA, sizeof(struct person), 1, infile);
	
	while (!feof(infile))
	{
		printf ("| %5d | %12s | %12s |\n", perA.id, perA.fname, perA.lname);
		
		fread (&perA, sizeof(struct person), 1, infile);
	}
	
	fclose (infile);
}

