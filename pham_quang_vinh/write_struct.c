// C program for reading
// struct from a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct person with 3 fields
struct person
{
    int id;
    char fname[20];
    char lname[20];
};
//Ham main
int main()
{
    struct person per1 ={1,"Vinh", "Pham"};
    struct person per2 ={2,"Quang", "Duy"};
     struct person per3 ={3,"Nguyen", "Huy"};
    FILE *outfile = fopen("person.dat","w");
    fwrite(&per1, sizeof(struct person),1,outfile);
    fwrite(&per2, sizeof(struct person),1,outfile);
    fwrite(&per3, sizeof(struct person),1,outfile);
    if (fwrite!=0)
    printf("Ghi file thanh cong roi do nha!");
    else printf("LOI!! Ghi file khong thanh cong");
    fclose(outfile);
     return 0;
    
    
}
