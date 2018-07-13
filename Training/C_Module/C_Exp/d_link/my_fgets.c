#include"header.h"

char* readinput(char *input)
{
	if(NULL == (fgets(input,MAX,stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}
	
	return input;
}
