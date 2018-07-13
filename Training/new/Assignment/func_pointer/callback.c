#include <stdio.h>

void func(char, void (*fp)(float));
void fun1(float);

int main(void)
{
	void (*p)(float);
	p = fun1;
	printf("main function\n");
	func('a',p);
	return 0;
}

void func(char a, void (*fp)(float))
{
	printf("func function\n");
	(*fp)(8.5);
}

void fun1(float a)
{
	printf("fun1 function\n");
}

