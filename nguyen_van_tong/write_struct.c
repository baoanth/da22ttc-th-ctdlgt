//C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};
int main(){
person per1 , per2;

strcpy("Nguyen", per1.fname);
strcpy("A",per1.lname);
strcpy("LE",per2.fname );
strcpy("B",per2.lname);
FILE *f;
f= fopen("person.dat","w");
if(f!=NULL){
printf("da mo duoc file");
fprintf(f," ho per1 \n", per1.fname);
fprintf(f," ten per1 \n", per1.lname);
fprintf(f," ho per2 \n", per2.fname);
fprintf(f," ten per2 \n", per2.lname);
}
close(f);

    return 0;
}
