/*parses buf until it encounters any of the delimiter in delim */

#include"header.h"

char *strrtok(const char *buf,const char *delim)
{
	char *str = NULL;
	if(NULL == (str = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }

	int index;
	int index1;
	const char *initial = delim;
	for(index = 0 ; *(buf + index) != '\0' ; index++){
		for(index1 = 0; *(delim + index1) != '\0' ;index1++){
			if(*(buf + index) ==  *(delim + index1)){
				*(str + index) = '\n';
				break;
			}
			else
				*(str+index) = *(buf + index);
		}
		delim = initial;
	}
	return str;
	free(str);
}
