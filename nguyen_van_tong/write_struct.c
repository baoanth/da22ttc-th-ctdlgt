//C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// struct person with 3 fields
typedef struct 
{
    int id;
    char fname[20];
    char lname[20];
}person;
int main(){
	person per1 = {1,"nguyen", "An"};
	person per2 = {2,"Le", "Vinh"};
	
	FILE *outfile = fopen("person.dat","w");
	
	fwrite(&per1,sizeof(person),1,outfile);
	fwrite(&per2,sizeof(person),1,outfile);
	
	if(fwrite != 0)
		printf("ghi file thanh cong");
	else 
		printf("ghi file KHONG thanh cong");
		
	fclose (outfile);
    return 0;
}
