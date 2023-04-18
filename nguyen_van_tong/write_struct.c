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
per1.id =1;
strcpy("Nguyen", per1.fname);
strcpy("A",per1.lname);
per2.id = 2;
strcpy("LE",per2.fname );
strcpy("B",per2.lname);
FILE *f;
f= fopen("person.dat","w");
if(f!=NULL){
printf("da mo duoc file");
fprintf(f,"ma so per1 %d\n", per1.id);
fprintf(f," ho per1 %s\n", per1.fname);
fprintf(f," ten per1 %s\n", per1.lname);
fprintf(f,"ma so per2 %d\n",per2.id);
fprintf(f," ho per2 %s\n", per2.fname);
fprintf(f," ten per2 %s\n", per2.lname);
}
close(f);

    return 0;
}
