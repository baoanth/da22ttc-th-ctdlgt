
#include <stdio.h>
#include <stdlib.h>
#defile AMOUNT 200
   char [20] tenhang;
   int soluong;
   float gia;
   float thanhtien;
} HangHoa;

HangHoa[] read_DMHH(char*filename, int &n)
{
	HangHoa hh_array[MAX_AMOUNT]
	FILE *infile = fopen(filename, "rb");
	HangHoa hhA;
	
	printf("%5s%20s%8s%12s%12s\n", "Ma Hang", "Ten Hang", "So Luong", "Don Gia", "So Tien");
	//thu doc 1 person
	fread(&hhA, sizeof(HangHoa)), 1, infile );
	
	//Duyet file cho den khi gap EOF
	while(!feof(infile))
	{
		//In perA ra man hinh 
		printf("%5s%20s%8d%12f%12f\n", hhA.mahang, hhA.tenhang, hhA.soluong, hhA.gia, hhA.thanhtien);
		
		//Doc mot cau truc person dua vao perA
		fread(&hhA, sizeof(HangHoa), 1, infile);
		hh_array[count]=hhA;
		
	}
	fclose(infile);
	return hh_array;	
	
}

