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
int main(){
	struct person per1;
	FILE *infile = fopen ("person.dat","rb");
	
	fread(&per1,sizeof(struct person),1,infile);
	
	printf("%5s%12s%15s\n","id", "fname", "lastname");
	
	while(!feof(infile)){
		printf("%5d%12s%15s\n",per1.id,per1.fname,per1.lname);
		fread(&per1,sizeof(struct person),1,infile);
	}

	fclose(infile);	

	return 0;
}
