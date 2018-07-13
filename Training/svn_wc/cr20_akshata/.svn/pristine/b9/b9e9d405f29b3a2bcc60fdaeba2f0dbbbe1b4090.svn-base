/* To reverse a string */

#include"header.h"

char* reverse(char *str1)
{
	int index;
	int len = 0;
	char *buf = NULL;
	if(NULL == (buf = (char*)malloc(sizeof(char) * MAX))){
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}

	len = string_length(str1);

	for(index = 0 ; len != 0 ; index++)
	{
		*(buf + index) = *(str1 + (len-1));
		len--;
	}
		
	return buf;
	free(buf);
} 
