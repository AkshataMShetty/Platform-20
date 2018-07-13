/* to remove substring from sting */

#include"header.h"

char *remsstr(char *str ,const char *rstr)
{
	int flag = 0;
	int index1;
	int index2;
	int len;
	int slen;

	len = string_length(str);
	slen = string_length(rstr);
	for(index1 = 0 ; index1 <= (len - slen) ; index1++)
	{
		flag = 1;
		for(index2 = 0 ; index2 < slen ;index2++)
		{
			if(*(str+(index2+index1)) != *(rstr+index2))
			{	
				flag = 0;
				break;
			}
		}
	
		if(flag == 1)
		{
			for(index2 = index1 ; index2 <= (len) ;index2++){
				*(str+index2) = *(str+(index2+slen)) ;
			}
			len = len - slen;
		}
	}
	return str;
}
