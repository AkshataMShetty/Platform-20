#include <stdio.h>
#include<string.h>

int main(void)
{
	char *ptr = malloc(10);
	//printf("%d\n",getpid());
	int *str = malloc(10);
	strcpy(ptr,"abcdefghijklmnopqrstuvwxyz");
	printf("%s\n",ptr);
	//getchar();
	return 0;
}
