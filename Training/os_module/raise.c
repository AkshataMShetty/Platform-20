#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void usr1_handler(int sig_num)
{
	printf("parent (%d) ret the SIGUSR\n",getpid());
}

int main()
{
	pid_t ret;
	int status;
	int rele = -1;

	ret = fork();

	if(ret > 0)
	{
		printf("parent:this is parent process(pid %d)\n",getpid());
		signal(SIGUSR1,usr1_handler);
		rele = 0;
		pause();
		printf("parent:Awaiting child exit\n");
		ret = wait(&status);
	}
	else if(ret == 0){
		printf("child:this is child process(pid %d)\n",getpid());
		rele = 1;
		sleep(1);
		printf("child:sending SIGUSR to pid %d\n",getpid());
		kill(getppid(), SIGUSR1);
		sleep(2);
	}
	else
	{
		printf("parent:Error trying to fork() %d\n",errno);
	}
	
	printf("%s: Exiting...\n",((rele == 0) ? "parent" : "child"));
	return 0;
}
