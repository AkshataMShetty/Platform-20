#include<stdio.h>
int main(void)
{
	char *str1 = "hello";
	char str2[6] = "world";
	printf("%p\n",str1);
	printf("%p\n",str2);
	printf("%p\n","hello");

	str1 = "hi";
	printf("%p\n",str1);
	printf("%p\n","hello");
	printf("%p\n","hi");


	return 0;
}

