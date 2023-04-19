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
    	
    	//Duyet file cho den khi gap EOF
    	fread(&perA, sizeof (struct person), 1, infile );
    	//In perA ra man hinh
    	
    	while(!feof(infile))
    	{
    		printf("%5d", perA.id );
			printf("%12s", perA.fname );
			printf("%13s\n", perA.lname );
			//Doc mot cau truc person dua vao perA
			fread(&perA, sizeof(struct person), 1, infile );
		}
		
		fclose(infile);
	}
