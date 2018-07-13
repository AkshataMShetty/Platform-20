#include <stdio.h>
//typedef int* ap;
//#define int int*
#if 0
int main(void)
{
	int p,q;
	int *ptr = malloc(-1);
	printf("%d",*ptr);
//	printf("%p\n",p);
	return 0;
}
#endif

#if 1
int main(void)
{
	int a = 10;
	int b = 20;
	int  *p = &a;
	int *q = &b;
	printf("p - q = %x\n",p-q);
	printf("p+q = %x\n",p+q);
//	printf("p/q = %x\n",p/q);
	return 0;

}
#endif
