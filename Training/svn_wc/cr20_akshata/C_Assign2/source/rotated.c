/*To check whether rstr is a rotated string of str.*/
#include"header.h"

int strrot(const char *str,const char *rstr)
{
	int len1 = string_length(rstr);
	int len2 = string_length(str);
	int index1 = 0;
	int index2 = 0;
	int match = 0;
	char *buf;
	if(len1 != len2){
		return 0;
	}
	
	if(0 == (str_cmp(str , rstr))){
		return 0;
	}

	buf = sappend((char *)str,(char *)str);
	int len = string_length(buf);
	while((match <= len1) && (index1 < len)){
		if((*(rstr + index1)) && (*(buf + index1) == *(rstr + index2))){
			index2 = ((index2 + 1) % len1 );
			match++;
		}
		index1++;
	}

	if(match == len1){
		return 1;
	}
	return 0;
}



