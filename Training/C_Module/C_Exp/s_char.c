#include <stdio.h>

int main(void)
{
	char e[1] = {1};
	char a[5] = "hello";
	char b[3]= "hai";
	char c[1]= {'a'};
	char d = 'b';

	printf("%p\n",e);
	printf("%p\n",a);
	printf("%p\n",b);
	printf("%p\n",c);
	printf("%p\n",&d);

	return 0;
}
