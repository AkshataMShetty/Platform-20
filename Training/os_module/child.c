#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
//	pid_t pid1;
	//pid = fork();
	
//	printf("main parent ppid = %d\n", getppid());
	printf("main pid = %d\n", getpid());

	pid = fork();
//	pid = fork();
	if(pid < 0)
	{
		perror("error in child process creation");
		return 0;
	}

	else {
		printf("child pid = %d\n", getpid());
		printf(" child parent pid = %d\n", getppid());
	//	printf(" child parent pid = %d\n", getppid());
	}

	/*else{
	printf("Parent pid: %d",getpid());
	}*/
//	printf("in parent -> after child,parent pid = %d\n", getppid());

	return 0;
}
