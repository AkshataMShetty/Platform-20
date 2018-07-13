#include <stdio.h>
#if 0
#pragma pack(1)
struct abc{
	char a;
	int b;
}x;

int main()
{
/*	
struct abc{
	int a;
	int b;
}a;*/
	x.a = '1';
	x.b = 10;
	printf("%p\n%p\n%p\n", &x, &x.a, &x.b );
	printf("%d\n",getpid());
	getchar();
	return 0;
}
#endif

#if 0
int a = 5;
enum gender{male="a", female};

int main(void)
{
	//gender e1;

	printf("%d\n", male);
	printf("%d\n", female);
}

#endif

//#if 1
#include <stdio.h>
struct a
{
	int a;
}*s ;
int main(void)
{
	struct a *p;
	(*p).a = 10;
	(*p).b = 20;
	printf("%d\n",(*p).a);
	printf("%d\n",(*p).b);
	return 0;
}
