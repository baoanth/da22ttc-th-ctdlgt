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
    printf"hewllo";
    printf"xin chao";
}int main()
 {struct person per1 = {1,"pham","thi"};
 struct person per2 = {2,"kim","nan"};
 FILE* outfile = fopen("preson.dat","w");
 fwrite(&per1, sizeof(struct person),1,outfile);
 fwrite(&per2, sizeof(struct person),1,outfile);
 if (fwrite!=0) 
 printf(" ghi thanh cong");
 else
 printf("loi!");
 fclose(outfile);
 }
