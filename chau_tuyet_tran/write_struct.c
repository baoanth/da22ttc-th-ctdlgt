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

int main ()
{
    struct person per1 = (1, "Tran", "Chau");
    struct person per2 = (2, "Tuan", "Chau");
    
    FILE *outfile = fopen ("person.dat", "w");
    
    fwrite (&per1, sizeof (struct person), 1, outfile);
    fwrite (&per2, sizeof (struct person), 1, outfile);
    
    if (fwrite != 0)
        printf ("Ghi du lieu thanh cong.");
    else
        printf ("LOI! Ghi du lieu khong thanh cong.");

    return 0;
}
