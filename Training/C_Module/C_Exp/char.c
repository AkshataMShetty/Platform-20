#include <stdio.h>
void func(int);
int main(void)
{
	int a = 10;
	func(a);
	return 0;
}

void func(int a)
{
	printf("%d\n",a);
	return 0;
}



