//VALIDATION FOR ALPHANUMERIC 
#include "header.h"

int alpha_numeric (const char *tok)
{
	int index = 0;
	int len = strlen(tok);

	while (*(tok + index) != '\0') {
		
		if(((*(tok + index) >= 48 && *(tok + index) <= 57 )) || (*(tok + index) >= 97 && *(tok + index) <= 122) || (*(tok + index) >= 65 && *(tok + index) <= 90) || *(tok + index) == 32) {
			if(index != (len - 1) && *(tok + index) == 32) { 
				return 0;
			}
			index++;
		}
		else
			return 0;
	}

	return 1;
}
