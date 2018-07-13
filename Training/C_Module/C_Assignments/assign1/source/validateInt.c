// function to validate integer

#include "header.h"

void validateInt(unsigned int num)
{
	if(num > INT_MAX) //if given num is out of integer range
	{
		perror("invalid range of input");
		exit(EXIT_FAILURE);
	} 
}
