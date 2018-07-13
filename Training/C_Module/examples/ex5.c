#include<stdio.h>
int main()
{
	char c_arr[5] = { 'A' , 'B' , 'Z' , '\0','\n'};
	printf("%s\n",c_arr);

	char *str = "hello world";
	char *ptr = NULL;
	ptr = str;
	printf("%s\n",ptr);

	char a_str[20] = "world";
	char *str1 = "hello world";
	char *ptr1 = NULL;
	ptr1 = str1;
	printf("%s",ptr1);


	return 0;
}
