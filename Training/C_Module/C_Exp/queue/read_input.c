/* To read input from user */
#include <stdio.h>
#include <stdlib.h>
#define MAX 255
char* readinput(char *input)
{
	if(NULL == (fgets(input,MAX,stdin))){
		perror("fgets failed");
		exit(EXIT_FAILURE);
	}
	
	return input;
}
