#include <stdio.h>
#include <stdlib.h>

void fun(void);

int main(void)
{
	int a = 10;

	fun();
	printf("1. a = %d\n", a);
	printf("2. a = %d\n", a);
	
	return 0;
}


void fun( void)
{
	int  b = 20;
	int *ptr = &b;
	
	ptr++;
	ptr++;
	ptr++;
	(*ptr) += 20;
	return;
}
