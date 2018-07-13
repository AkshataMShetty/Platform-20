/*to check the consecutive occurrences of 3 ones.*/

#include"header.h"

int check_ones(char *arr)
{
	int count = 0;
	while(*arr != '\n')
	{
		if(*arr == '1'){
			count++;
			if(count == 3)
				return 1;
			arr++;
		}
		else{
			count = 0;
			arr++;
		}
	}
	return 0;
}
