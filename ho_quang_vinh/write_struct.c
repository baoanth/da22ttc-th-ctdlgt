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
struct person pre1 ={1, "quang", "vinh"};
struct person pre1 ={2, "tra", "vinh"};

FILE* outfile = fopen ("person.dat", "w");

fwiter(&per1, sizeof(struct person), 1, outfile);
fwiter(&per2, sizeof(struct person), 2, outfile);

if (fwrite !=0)
printf("write file successfully");
else
printf("EROR! write file successfully");
fclose(outfile);




}

