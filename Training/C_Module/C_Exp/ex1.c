#include <stdio.h>
//const int g =10;
int main()
{
	const int g = 10;
	int *ptr = &g;
	printf("%d\n",g);
	*ptr = 100;
	printf("%d\n",g);
	
	return 0;
}
