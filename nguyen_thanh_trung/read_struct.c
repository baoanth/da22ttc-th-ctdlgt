// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
	
=======

>>>>>>> a532bdc9afa6488b3413e6fbed3ccd72dc887c9c
// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};
int main()
{
<<<<<<< HEAD
	struct person perA;
	FILE *infile = fopen("person.dat", "rb");
	
	fread(&perA, sizeof(struct person),1, infile);
	
	printf("%5s%12s%13s\n", "ID", "First Name", "Last Name");
	
	// thu doc 1 person 

	//duyet file cho den khi gap ECF
	while(!feof(infile))
	{
		printf("%5d%12s%13s\n", perA.id ,perA.fname,perA.lname);
		
		fread(&perA, sizeof(struct person),1, infile);
	}
	
	fclose(infile);
=======
	FILE *infile=fopen("person.dat","rb");
	struct person perA;
	
	
	printf("%5s%12s%13s\n","ID","First Name","Last Name");
	
	fread(&perA, sizeof(struct person), 1, infile);
	
	while(!feof(infile))
	{
		printf("%5d%12s%13s\n",perA.id,perA.fname,perA.lname);
		
		fread(&perA,sizeof(struct person),1 ,infile);
		
	}
	
	fclose(infile);
	
>>>>>>> a532bdc9afa6488b3413e6fbed3ccd72dc887c9c
}
