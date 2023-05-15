void input_DMHH(char* filename)
{
	char mahang_input[5];
	HangHoa hh_temp;

	HangHoa my_dmhh[MAX_AMOUNT];
	
	int count= read_DMHH(filename, my_dmhh);
	print_DMHH(my_dmhh, count);

	printf("Nhap hang moi: Nhap EXIT de thoat\n\n");


	while(1)
	{
		printf("Ma hang : \n");
		fflush(stdin);
		gets(mahang_input);

		if(strncmp(mahang_input, "EXIT", 4)==0)
		{
			break;
		}
		int found = find_HH_by_ma(mahang_input, my_dmhh, count, &hh_temp);

		if(found != -1)
		{
			printf("Ten hang : %s\n", hh_temp.tenhang);

			printf("So luong : ");
			scanf("%d", &hh_temp.soluong);

			printf("Don gia : ");
			scanf("%f", &hh_temp.dongia);

			hh_temp.thanhtien = hh_temp.soluong * hh_temp.dongia ;
			printf("\nThanh tien : %f", hh_temp.thanhtien);

			my_dmhh[found] = hh_temp	;	
			
		}
		else
		{
			strcpy(hh_temp.tenhang, mahang_input);
			printf("Ten hang: ");
			gets(hh_temp.tenhang);
		
			printf("So luong : ");
			scanf("%d", &hh_temp.soluong);
		
			printf("Don gia : ");
			scanf("%f", &hh_temp.dongia);
		
			hh_temp.thanhtien = hh_temp.soluong * hh_temp.dongia ;
			printf("\nThanh tien : %f", hh_temp.thanhtien);
		
			count ++;
			my_dmhh[found] = hh_temp ;	
					

		}
	}
