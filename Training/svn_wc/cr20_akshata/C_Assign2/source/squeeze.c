/*  to squeeze the consecutive similar characters in a given string */

#include "header.h"

char *squeeze(char *str)
{
	int index1 = 0;
	int index2 = 0;

	char *buf;

    if(NULL == (buf = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }


	while(*(str + index1) != '\0')
	{
		if(*(str + index1) != *(str + (index1 + 1))){
			*(buf + index2) = *(str + index1);
			index2++;
			index1++;
		}
		else
			index1++;
	}
	str = buf;
	return str;
	free(buf);
}

