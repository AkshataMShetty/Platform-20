#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int num = 0;
	pid_t pid = fork();

	if(pid ==0)
	{
		num = 1;
		printf("child\n");
		printf("%d\n",num);
	}
	else if(pid > 0)
	{
		num = 2;
		printf("parent\n");
		printf("%d\n",num);
	}
	else
	{
		printf("%d\n",num);
	}
	return 0;
}
