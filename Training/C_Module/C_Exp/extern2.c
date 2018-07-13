#include<stdio.h>

#if 0
#define f(x,y) x##y
#define g(x) h(x)
#define h(x) #x
int main(void)
{
	printf("%s\n",h(f(1,2)));
	printf("%s\n",g(f(1,2)));

	return 0;
}
#endif


int b ;
int main( void )
{
	printf("in function\n");
	printf("%p\n",&b);

	return 0;
}
