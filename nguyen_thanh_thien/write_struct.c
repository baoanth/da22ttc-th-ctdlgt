// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};

int main(){
    struct person per1 = {1, "Thien", "Nguyen"};
    struct person per2 = {2, "Thanh", "Nguyen"};
    
    FILE *outfile = fopen("person.dat", "w");
    
    fwrite(&per1, sizeof(struct person), 1, outfile);
    fwrite(&per2, sizeof(struct person), 1, outfile);
    
    if(fwrite != 0)   
    	printf("Da ghi file thanh cong!");
    else
    	printf("LOI!! Khong the ghi file!");
     
     fclose(outfile);

    return 0;
}
