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
    struct person per1 ={1, "Nguyen", "An"};
    struct person per2 = {2,"Le","Binh" };
    FILE* outfile = fopen("person.dat", "w");
    fwrite(&per1, sizeof(struct person), 1,outfile);
    fwrite(&per2, sizeof(struct person), 1,outfile);
    
    if (fwrite!=0)
     printf("ghi file thanh cong");
    else
     printf("ghi file that bai");
    fclose (outfile);

}
