#include<stdio.h>
int main(void)
{
	int a[4] = {1,2,3,4};
	int *ptr = a;
	int *ptr1 = &a;
	//ptr++;
	//ptr1++;
	printf("%p\n",&a);
	printf("%p\n",(a + 1));
	printf("%d\n",*(a + 1));
	
	printf("%p\n",(&a + 1));
//	printf("%p\n",);
//	printf("%p\n",a);
		
	ptr++;
	ptr1++;

	printf("%p\n",ptr);
	printf("%p\n",ptr1);

	return 0;
	}
