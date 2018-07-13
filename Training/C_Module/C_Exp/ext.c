#include<stdio.h>
int main(void)
{
	extern int a;
	{
		printf("%d\n",a);
	}

	return 0;
}
