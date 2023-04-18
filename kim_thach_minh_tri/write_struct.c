// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>

// struct person with 3 fields
typedef struct 
{
    int id;
    char fname[20];
    char lname[20];
} person;


int main()
{
    FILE *outline;
    person per1, per2;
    per1.id=1;
    per2.id=2;
    strcpy(per1.fname, "Kim");
    strcpy(per1.lname, "Tri");
    strcpy(per2.fname, "Thach");
    strcpy(per2.lname, "Minh");
    outline = fopen ("person.dat","w");
    fprintf(outline, "%d %s %s\n", per1.id, per1.fname, per1.lname);
    fprintf(outline, "%d %s %s\n", per2.id, per2.fname, per2.lname);
   return 0; 
}
 

	
