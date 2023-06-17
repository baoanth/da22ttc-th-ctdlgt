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

//Ham  main
int main()
{
	struct person per1 = {1, "Thinh", "Kieu"};
	struct person per2 = {2, "My", "Nguyen"};
<<<<<<< HEAD
=======
	struct person per3 = {3, "Tran", "Thanh"};
>>>>>>> 2ccda85e250682fc684a97beba05a896435c7109
	
	FILE *outfile = fopen("person.dat", "w");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	fwrite(&per3, sizeof(struct person), 1, outfile);
	
	if(fwrite!=0) printf("Ghi file thanh cong roi!");
	else printf("LOI! Gi file KHONG thanh cong!");
	
	fclose(outfile);
}
