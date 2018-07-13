#include <stdio.h>
#include <stdlib.h>
#define MAX 256

char* readinput(char *input)
{
	if(NULL == (fgets(input,MAX,stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}
	
	return input;
}
