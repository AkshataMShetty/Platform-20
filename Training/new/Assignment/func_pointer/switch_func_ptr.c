#include <stdio.h>

typedef int (*operation)(int a, int b);

typedef struct str{
	int result;
	operation opt;
}STR;

int add(int a, int b)
{
	return a+b;
}

int product(int a, int b)
{
	return a*b;
}

int main(void)
{
	STR str_obj;
	str_obj.opt = add;
	str_obj.result = str_obj.opt(5,3);
	printf("addition result is %d\n",str_obj.result);
	
	str_obj.opt = product;
	str_obj.result = str_obj.opt(5,3);
	printf("product result is %d\n",str_obj.result);

	return 0;
}
