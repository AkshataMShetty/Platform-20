#include <stdio.h>

typedef int (*operation)(int a, int b);

typedef struct str{
	int result;
	operation opt[];
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
    //int	ch = 0;
	STR str_obj;
	str_obj.opt[0] = add;
	str_obj.opt[2] = product;
	
	str_obj.result = str_obj.opt[0](5,3);
	printf(" result is %d\n",str_obj.result);
	return 0;
}
