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
	struct person per1 = {1, "nguyen ", "thien" };
	struct person per2 = {2, "thanh", "thien" };
	struct person per3 = {3, "bao", "tran" };
	FILE* outfile = fopen("person.dat", "w");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	fwrite(&per3, sizeof(struct person), 1, outfile);
	if (fwrite!=0)
		printf("da ghi thanh cong");
	else
		printf("khong thanh cong");
	fclose(outfile);   
   

}
