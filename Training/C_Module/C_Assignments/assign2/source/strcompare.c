/* To compare two strings */
#include"header.h"

char str_cmp(const char *str1,const char *str2)
{
	while(*str1++ == *str2++)
	{
		if((*str1 == '\0') && (*str2 == '\0'))
			return 0;
	}
	if(*str1 > *str2)
		return 1;
	else
		return -1;
}
