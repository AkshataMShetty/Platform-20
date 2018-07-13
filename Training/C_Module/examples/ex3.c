#include<stdio.h>
int main()
{
	char x = 'A';
	int *ptr = NULL;
	ptr = &x;
	printf("%c",*ptr);
	printf("%p,%p\n",&x,&ptr);
	return 0;
}
