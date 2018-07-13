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

	
				printf("enter the string\n");
				str = readinput(str);
				printf("enter the index\n");
				num = fgetc(stdin);

				sub_str = my_index(str,num);
				printf("string is = %s\n",sub_str);
				
	return 0;
}
