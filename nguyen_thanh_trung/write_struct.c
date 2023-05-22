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
<<<<<<< HEAD

//ham main

int main()
{
	struct person per1 = {1,"Thu" , "Nguyen"};
	struct person per2 = {2,"Minh" , "Vo"};
	FILE *outfile = fopen("person.dat","wb");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	
	if (fwrite!=0)
		printf("Ghi file thanh cong roi!");
	else
		printf("LOI! Ghi file KHONG thanh cong!");
		
	fclose(outfile);
}

=======
 
 int main()
{
    struct person per1 = {1, "Nguyen", "trung"};
	struct person per2 = {2, "abc", "thanh"};


	FILE *outfile;
	outfile= fopen("person.dat","w");

	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);

	if(outfile!=0)
	   printf("ghi file thanh cong");
	else 
	   printf("Loi!!ghi file khong thanh cong");

	   fclose(outfile);
return 0;
}
 
>>>>>>> a532bdc9afa6488b3413e6fbed3ccd72dc887c9c
