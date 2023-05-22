// #include <stdio.h>
#include <stdlib.h>

// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};
int main()
{struct person per2;
FILE* outfile=fopen("preson.dat","rb");
printf("%4s%10s%6s\n","ID","fname","lname");
fread(&per2,sizeof(struct person),1,outfile);
while(!feof(outfile))
{
	printf("%4s%10s%66s\n"per2.ID ,per2.fname,per2.lname);
	fread(&per2,sizeof(struct person),1,outfile);
}
fclose(outfile);
}
