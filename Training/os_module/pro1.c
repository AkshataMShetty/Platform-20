#include <stdio.h>
#include < signal.h>

int main(int argc,char **argc)
{
	if(argc != 2)
	{
		printf("invalid arguments\n");
		exit( 0 );
	}

	kill(
