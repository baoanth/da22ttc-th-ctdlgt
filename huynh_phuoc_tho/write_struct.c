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
<<<<<<< HEAD
<<<<<<<< HEAD:huynh_phuoc_tho/write_struct.c
int main()
{
 printf("day la mot bai mau ");
 printf("day chi la ao");


};
========

int main(){
	struct person perA;
    FILE* infile = fopen ("person.dat","rb");
    
   
    fread(&perA , sizeof(struct person), 1 , infile);
    printf("%d %13s %10s\n", "ID", "FNAME", "LNAME");
    
    while (!feof(infile))
    {
    	printf("%d %13s %10s\n", perA.id, perA.fname, perA.lname);
		fread(&perA, sizeof(struct person),1, infile);
		
			
    	
    	
    	
    }
    fclose(infile);
   	
}
>>>>>>>> c7306080c141a68bbdf308ec6014b070f997f62c:huynh_phuoc_tho/read_struct.c
=======

int main(){
    struct person per1 ={1, "Phuoc", "Tho"};
    struct person per2 ={2, "Tra", "Vinh"};

    FILE* outfile;
	outfile = fopen ("person.dat", "w");

    fwrite(&per1, sizeof(struct person), 1, outfile);
    fwrite(&per2, sizeof(struct person), 1, outfile);

    if (outfile!=0)
    	printf("write file successfully");
    else
    	printf("EROR! write file unsuccessfully");
    	
    	fclose(outfile);

}
>>>>>>> c7306080c141a68bbdf308ec6014b070f997f62c
