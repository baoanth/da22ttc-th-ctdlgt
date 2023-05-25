<<<<<<< HEAD
=======
// C program for reading
// struct from a file
>>>>>>> 2ee17036c6e249051f957e7ed7214990e020feaf
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
<<<<<<< HEAD
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



=======
	struct person per1 = {1,"Chau","Qui"};
	struct person per2 = {2,"Tran","Tho"};	
	struct person per3 = {3,"Dang","Phuoc"};
	FILE* outfile = fopen("person.dat","w");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	fwrite(&per3, sizeof(struct person), 1, outfile);	
	
	if (fwrite!=0)
	  printf("Write file successfully");
	else
	  printf("ERROR! Write file unsuccessfully");
	fclose(outfile);    
}
>>>>>>> 2ee17036c6e249051f957e7ed7214990e020feaf
