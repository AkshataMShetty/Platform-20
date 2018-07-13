#include<stdio.h>
/*struct tag{
	int a;
}*t1;
*/
int main(void)
{
	struct tag1{
		//float a:1;
		struct tag1 *ptr;
		int b;

	}t2;
	t2.ptr = &t2;
	
	//printf("%p\n",&t2.b);
	//printf("%p\n",ptr -> b);
	printf("%p\n",&t2);
	printf("%p\n",t2.ptr);
	return 0;
}
