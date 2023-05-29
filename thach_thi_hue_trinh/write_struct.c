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
	struct person per1 = { 1, "Meomeo" , "Uzumaki" };
	struct person per2 = { 2, "Hinata" , "Uzumaki" };
	struct person per3 = { 3, "Boruto" , "Uzumaki" };
	struct person per4 = { 4, "Sasuke" , "Uchiha " };
	struct person per5 = { 5, "Sakura" , "Uchiha " };
	struct person per6 = { 6, "Sarada" , "Uchiha " };
	
	
	FILE *outfile = fopen("person.dat", "w");
    
    
	fwrite(&per1, sizeof (struct person), 1, outfile);
	fwrite(&per2, sizeof (struct person), 1, outfile);
	fwrite(&per3, sizeof (struct person), 1, outfile);
	fwrite(&per4, sizeof (struct person), 1, outfile);
	fwrite(&per5, sizeof (struct person), 1, outfile);
	fwrite(&per6, sizeof (struct person), 1, outfile);
	
	if (fwrite!=0)
	   printf("Ghi file thanh cong!");
	else
	   printf("Ghi file that bai");
	   
	fclose(outfile);      
	
}
