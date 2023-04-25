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
{struct person per1;
FILE* outfile=fopen("preson.dat","rb");
printf("%5s%8s\n","fname","lname");
fread(&per1,sizeof(struct person),1,outfile);
while(!feof(outfile))
{
	printf("%5s%8s\n",per1.fname,per1.lname);
	fread(&per1,sizeof(struct person),1,outfile);
}
fclose(outfile);
}
