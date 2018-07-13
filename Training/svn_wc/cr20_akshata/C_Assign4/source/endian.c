#include "header.h"
int endian()
{
	int a = 0x01;
	char *ptr = NULL;
	
	ptr = (char *)&a;
	
	if(*ptr == 1)
		printf("machine is little endian\n");
	else
		printf("machine is big endian\n");
	
	return 0;
}

