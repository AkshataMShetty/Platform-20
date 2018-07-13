#include "header.h"

int main(void)
{
	char *ptr = NULL;
	int result = 0;
	int num;

	if(NULL == (ptr = (char*)malloc(sizeof(char)*256)))
	{
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}

	printf("enter the input\n");
	if(NULL == fgets(ptr,256,stdin)){
		perror("fgets failure");
		exit(EXIT_FAILURE);
	}

	num = my_atoi(ptr);
	
	result = multiply(num);

	printf("%d multiply by 9 =%d\n",num,result);

	return 0;
}	
