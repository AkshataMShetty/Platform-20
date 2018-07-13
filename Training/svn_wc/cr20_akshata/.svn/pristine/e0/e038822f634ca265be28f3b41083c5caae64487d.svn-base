#include"header.h"

int main(void)
{
	
	char *str = NULL;
	char *sub_str = NULL;
	int num;
	if(NULL == (str = (char*)malloc(sizeof(char) * MAX)))
    {
        perror("malloc failure\n");
        exit(EXIT_FAILURE);
    }
	if(NULL == (sub_str = (char*)malloc(sizeof(char) * MAX)))
    {
        perror("malloc failure\n");
        exit(EXIT_FAILURE);
    }


	printf("enter a string\n");
	str = readinput(str);
	printf("enter a substring \n");
	sub_str = readinput(sub_str);

	num = freq_of_occurance(str,sub_str);

	printf("occurence of substring = %d\n",num);
				
	return 0;
}
