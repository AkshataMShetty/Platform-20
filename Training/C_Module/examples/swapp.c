
#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	printf("value befor swap %d %d \n",*a,*b);
	temp = *a;
	*a = *b;
	*b = temp;
	printf("swapped values are %d %d \n",*a,*b);
	return;
}

void fun(int *ptr)
{
	++ptr;
	printf("%d\n",*ptr);
}
