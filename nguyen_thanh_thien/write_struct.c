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
    FILE *infile = fopen("person.dat","rb");
    struct person per A;
    printf ("%5s%12s%13s \n","ID" ,"First name", "Last name");
    fread 
    
