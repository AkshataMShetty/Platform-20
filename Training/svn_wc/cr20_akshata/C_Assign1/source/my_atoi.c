#include"header.h"

int my_atoi(char *str)
{
	int index;
	int num;
	
	num = 0;

	for(index = 0 ; *(str + index) >= '0' && *(str+index) <= '9' ; index++){
		num = 10 * num + (*(str+index) - '0');
	}

	return num;
} 
