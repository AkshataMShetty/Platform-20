#include<stdio.h>
#define A B
#define B 10
#define C A
enum day {sun,mon};
void func(enum day e1)
{
	printf("%d\n",e1);
}

int main(void)
{
	enum day e1 = 8;

	func(e1);

	printf("%d\n",<F10>e1);
/*	printf("%d\n",C);
	printf("%d\n",A);
	printf("%d\n",B);*/

	return 0;

}
