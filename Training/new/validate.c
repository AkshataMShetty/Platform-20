#include "header.h"

int validate(char *buf)
{
	char *tok = NULL;
	int flag = 0;
	char *delim = "=";
	int value;

	if(NULL == (tok = malloc(sizeof(char *)))){
		printf("malloc failed\n");
		return 0;
	}

	while(*buf++ != NULL){
		if( (*buf == '=') && (*(buf + 1) == ' ')){
			flag = 1;
		}
	}

	if(flag == 1){
		tok = strtok(buf, delim);
		value = isalphanum(tok);
		if(value == 1)
		{
			tok = strtok(NULL,delim);
			if(isdigits(tok) == 1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	return 0;
}
