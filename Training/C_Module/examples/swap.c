#include<stdio.h>
//void swap(int *,int *);
void fun(int *);
int main(void)
{
	#if 0
	int num_1 = 10;
	int *ptr = &num_1;
	int num_2 = 20;
	int *ptr2 = &num_2;
	printf("in main value befor swap %d %d \n",num_1 , num_2);
	swap(&num_1,ptr2);
	printf("in main value after swap %d %d \n",num_1,num_2);
	return 0;
	#endif

	int a[5] = {1,2,3,4,5};
	int *ptr = NULL;
	ptr = &a;
	fun(ptr);
	printf("%d\n",*ptr);
	return 0;
	
}
