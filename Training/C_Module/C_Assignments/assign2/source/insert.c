/*to insert a character*/
#include"header.h"
char *insertchar(char *str,const char ch,int pos)
{
	int index1 = 0;
	int index2 = 0;
	char *buf = NULL;

    if(NULL == (buf = ((char *)malloc(sizeof(char) * MAX)))){
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }

	for(index1 = 0 ; *(str + index1) != '\0' ; index1++){
		if(index1 != (pos-1)){
			*(buf + index2) = *(str + index1);
			index2++;
		}
		else if(index1 == (pos-1))
		{
			*(buf + (index2))  = ch;
			index2++;
			*(buf + index2) = *(str + index1);
			index2++;
		
		}
	}
	*(buf + index2) = '\0';
	return buf;
	free(buf);
}
		
