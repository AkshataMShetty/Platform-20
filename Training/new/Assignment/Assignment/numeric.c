//VALIDATION FOR NUMERIC 
#include "header.h"

int numeric (const char *tok)
{
	int index = 0;

	
	while (*(tok + index) != '\0') {
		if((*(tok + index) >= 48 && *(tok + index) <= 57) || (*(tok + index) == 32) || *(tok + index) == 10)
			index++;
		else
			return 0;
	}

	return 1;
}
