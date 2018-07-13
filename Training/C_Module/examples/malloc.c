#include <stdio.h>

void fun (int *);

int main (void)
{
	int *p = malloc (sizeof(int));
	
	*p = 10;
	p++;
	*p = 20;

	fun(p);

	printf("%d",*p);
	printf("done.....\n");
	return 0;
}

void fun (int *ptr)
{
	free(ptr);
}
