#include"header.h"

int my_atoi(char *str)
{
	int index;
	int num;
	
	num = 0;

	for(index = 0 ; *(str + index) != '\0'; index++){
		if (*(str + index) >= '0' && *(str+index) <= '9') {
			num = 10 * num + (*(str+index) - '0');
		} else {
			continue;
		}
	}

	if ('-' == str[0]) {
		return (0 - num);
	}
	return num;
} 
