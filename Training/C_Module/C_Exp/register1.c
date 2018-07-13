#include<stdio.h>
register int  a asm("eax");
a = 100;
int main(void)
{
	// register int  a asm("eax")= 100;
	// a=10;
	int register b=20;
	int register c=30;
	int register d=40;
	int register e=50;

	return 0;
}
