#include"header.h"

int main(void)
{
	char *ptr = NULL;
	unsigned int num;
	unsigned int result;

	if(NULL == (ptr = (char *)malloc(sizeof(char) * MAX)))
	{
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}
	
	printf("enter the input");
	if(NULL == (fgets(ptr,MAX,stdin)))
	{
		perror("fgets failure");
		exit(EXIT_FAILURE);
	}

	num = my_atoi(ptr);

	printf("little endian = %d(%x)\n",num,num);

	result = little_to_big_endian(num);
	
	printf("big endian = %d(%x)\n",result,result);

	return 0;
}
