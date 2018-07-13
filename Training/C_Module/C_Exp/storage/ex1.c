#include <stdio.h>

int a = 5;
int main(void)
{
	int a = 6;
	{
		int a = 8;
		int *ptr = &a;
		while(*ptr == 6)
		{
			ptr++;
		}
		printf("%d\n",*ptr);
	}
	return 0;
}
