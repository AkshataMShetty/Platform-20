#include <stdio.h>

void fun();

int main(void)
{
	int a = 100;
	fun();
	printf("%d\n",a);
	return 0;
}
void fun()
{
	int *p;
	int i;
	p = &i;
	while(*p != 100)
	{
		p++;
	}
	*p = 200;
}
