#if 0
#include <stdio.h>
//extern char **environ;

int main(void)
{
	char *argv[] = {argv[0],NULL};
	char *envp[] = {"\\bin",NULL};
	execvpe("/bin/sh",argv,envp);
	return 0;
}
#endif


#if 1
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	pid_t pid;
	char *argv[] = {argv[0],NULL};
	char *envp[] = {"\\bin",NULL};

	pid = fork();

	if( pid == 0)
	{
		execvpe("/bin/sh",argv,envp);

	}

	else if(pid > 0)
	{
		printf("in parent \n");
		wait(NULL);
	}

	return 0;
}
#endif
