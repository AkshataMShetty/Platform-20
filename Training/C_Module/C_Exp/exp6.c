#include <stdio.h>
int main()
{
	char a = 'a';
	int *p = &a;
	printf("%s\n", p);

	p++;

	printf("%s\n",p);
	return 0;
}
