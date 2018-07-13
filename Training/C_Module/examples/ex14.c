#include<stdio.h>
#include<string.h>
int main(void)
{
	char str_arr[40] = "global edge";
	char str_arr2[40] = "learning & development ";
	char *str_ptr = "Techical training";
	strcat(str_arr ,str_ptr);
	strcat(str_arr, str_arr2);
	printf("%s\n",str_arr2);
	return 0;
}
