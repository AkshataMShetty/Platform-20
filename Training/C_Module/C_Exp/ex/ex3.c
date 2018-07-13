#include<stdio.h>

int main()
{
	char str1[] = "hello";
	char *str = "hello";

	printf(" str1 = %d\n",sizeof(str1));
	printf("str2 = %d\n", sizeof(str));

	char a[10] = "hello";
	printf("a = %s\n",a);
	return 0;
}
