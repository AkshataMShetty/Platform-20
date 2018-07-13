/* To append n character from string1 to string2 */

#include"header.h"

char *snappend(char *str1,char *str2,int num)
{
	int index;
    int len = 0;
    char *buf;

    if(NULL == (buf = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }
    
	for(index = 0 ; *(str2 + index) != '\0' ; index++){
        *(buf + index) = *(str2 + index);
	}
    *(buf + index) = '\0';

    len = string_length(buf);

	for(index = 0 ; (*(str1 + index) != '\0') && (num != 0) ; index++)
	{
		*(buf + len) = *(str1 +index);
		len++;
		num--;
	}

	return buf;
	free(buf);
}


