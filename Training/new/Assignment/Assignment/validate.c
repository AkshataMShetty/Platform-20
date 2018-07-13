//FUNCTION TO VALIDATE THE BUFFER
#include "header.h"

int validate(char *line1)
{
	
	int c;
	int flag = -1;
	int index = 0;
	char *tok = NULL;
	const char *delim = "=";
	int res = 0;
	char *line = line1;

	//VALIDATE '=' OPERATOR
	while (*(line + index) != '=' && *(line + index) != '\0') 
		index++;

	
	if (*(line + index) == '\0') {
		return 0;
	}
	else if (*(line + index + 1) == '=' && *(line + index + 1) != '\0') {
		return 0;
	}
	else {	
		index = 0;
	
		if(NULL == (tok = (char *)malloc (sizeof(char) * MAX))) {
			perror (" ");
			return 0;
		}
		tok = strtok(line, delim);			
		

		if((res = alpha_numeric(tok)) != 1) {
			return 0;
		}			
			
		if(tok != NULL) {
			tok = strtok (NULL, delim);
			
			if((numeric(tok)) != 1) {
				return 0;
			}

		}
	}
	return 1;
}
