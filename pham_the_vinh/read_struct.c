#include <stdio.h>
#include <stdlib.h>

struct person
{
    int id;
    char fname[20];
    char lname[20];
};

int main(){
	FILE *infile = fopen("person.dat", "rb");
	struct person perA;
	
	printf("%5s%15s%15s\n", "ID", "First name", "Last name");
	
	fread(&perA, sizeof(struct person), 1, infile);
	
	while(!feof(infile))
	{
		printf("%5d%15s%15s\n", perA.id, perA.fname, perA.lname);
		
		fread(&perA, sizeof(struct person), 1, infile);
	}
	
	fclose(infile);
}
