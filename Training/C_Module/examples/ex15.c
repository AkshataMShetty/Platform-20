#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *reverse(char *str)
{
	char ch;
	int len;
	int i = 0;
	len = strlen(str) - 1;
	while(i < len)
	{
	//	ch = *(str + i);
	//	*(str + i) = *(str +len);
	//	*(str + len) = ch;
		*(str + len) = *(str + len) ^ *(str + i);
		*(str + i) = *(str + len) ^ *(str + i);
		*(str + len) = *(str + len) ^ *(str + i);
//		*(str +len) = *(str + len -1);
//		*(str + i) = *(str + len);
//		*(str + len -1) = *(str +i);
		len--;
		i++;
	}
	return str;
}

int main(void)
{
	char *str = NULL;
	char *ptr = NULL;
	if(NULL == (str = (char *)malloc(sizeof(char)*256)))
	{
		perror("failure malloc");
		exit(EXIT_FAILURE);
	}
	 if(NULL == (ptr = (char *)malloc(sizeof(char)*256)))
    {
        perror("failure malloc");
        exit(EXIT_FAILURE);
    }

	printf("enter the string\n");
	if(NULL == (fgets(str,255,stdin)))
	{
		perror("failure of fgets");
		exit(EXIT_FAILURE);
	}
	
	ptr = reverse(str);
	printf("string =  %s\n",ptr );
	return 0;
}
