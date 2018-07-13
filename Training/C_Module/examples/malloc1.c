#include <stdio.h>
#include <stdlib.h>

void fun (int *p);

int main (void)
{
	int *ptr;

	ptr = malloc(sizeof(int));
	
	printf("%p\n",ptr);
	fun (ptr);
	free(ptr);

	return 0;
}

void fun (int *p)
{
	free (p);
}
