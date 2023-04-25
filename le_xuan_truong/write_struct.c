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
	struct person per1 = {1, "Le Xuan", "Truong"};
	struct person per2 = {2, "Thach Thi Hue", "Trinh"};
	
	FILE *outfile;
	outfile= fopen("person.dat","w");
	
	fwrite(&per1, sizeof(struct person), 1, outfile);
	fwrite(&per2, sizeof(struct person), 1, outfile);
	
	if(outfile!=0)
	   printf("Ghi file thanh cong!");
	else 
	   printf("Loi! Ghi file khong thanh cong");
	   
	   fclose(outfile);
}
