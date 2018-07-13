#include <stdio.h>
int main(void)
{
	int buf[10];
	gets(buf);
	printf("%s",buf);
	return 0;
}

