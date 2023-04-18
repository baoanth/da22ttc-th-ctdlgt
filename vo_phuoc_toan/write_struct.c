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
// ham main
int main()
{
	struct person per1 = {1, "Toan", "Vo"};
	struct person per2 = {2, "Trung", "Vuong"};
	
	FILE *outfile = fopen("person.that", "w");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	
	if(fwrite!=0)
	   printf("Ghi file thanh cong");
	else
	   printf("Ghi file khong thanh cong!");
	
	fclose(outfile);
}
