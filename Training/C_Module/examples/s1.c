#include <stdio.h>
#if 0
int main(void)
{
	int a;
	printf("%d",100);
	printf("%s","hello");
	printf("%d,%d",'c');
//	printf("%n",(int *)"hello");
	return 0;
}

#endif

int main()
{
  	int c;
    printf("geeks for %ngeeks ", &c);
	printf("%d", c);
	getchar();
	return 0;
}
