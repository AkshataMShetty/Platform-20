#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid_t pid1;

	pid = fork();
	if(pid == -1)
	{
		perror("fork error");
	}
	else if(pid == 0)
	{
		printf("child1 %d\n",getpid());

	}
	else if(pid > 0)
	{
		printf("parent1 %d\n",getpid());
		wait(NULL);
		
	}

	pid1 = fork();
	if(pid1 == -1)
		perror("fork error");
	else if(pid1 == 0){
		printf("child2 %d\n",getpid());
		}
	else if(pid1 > 0){
		printf("parent2 %d\n",getpid());
		wait(NULL);
	}
}
