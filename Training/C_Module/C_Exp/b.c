#include<stdio.h>
#if 0
int main(void)
{

	char c[] = {1,2,3,4};
	int *p = (int *) c;
	int i;

	for (i = 0; i < 4; i++) {
		printf ("%d\n",*((char *)p+ i));
//		p = (char *) p + 1;
	}
	//printf("%c %x",*p,*p);

	return 0;
}
#endif
#if 0
main()
{
	int a = 5;
	int b = &a;
//	int *c = b;
	printf("%d\n",* ((int *)b));

}
#endif

main()
{
	int i = 10;

	switch(i){

		int i = 5;
		case 10: printf("%d", i);break;
		default: printf("hello");
	}
}
