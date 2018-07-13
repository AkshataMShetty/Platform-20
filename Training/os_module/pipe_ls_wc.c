#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int pfd[2];
	if(pipe(pfd) == -1)
		perror("pipe");
	pid_t pid;
	pid_t pid1;
	pid = fork();
	if(pid == -1)
		perror("fork error");
	else if(pid == 0)
	{
		if(close(pfd[1]) == -1)
			perror("close3");
		if(pfd[0] != STDIN_FILENO){
			if(dup2(pfd[0],STDIN_FILENO) == -1)
				perror("dup2 2");
			if(close(pfd[0]) == -1)
				perror("close4");

		}
		execlp("wc","wc",(char *)NULL);
	//	wait(NULL);
	}
	else if(pid > 0)
	{
		if(close(pfd[0]) == -1)
		perror("close1");
		if(pfd[1] != STDOUT_FILENO){
			if(dup2(pfd[1],STDOUT_FILENO) == -1)
				perror("dup2 2");
			if(close(pfd[1]) == -1)
				perror("close2");
			}
		execlp("ls","ls",(char *)NULL);
	
		wait(NULL);
		
	}

/*	pid1 = fork();
	if(pid1 = -1)
		perror("fork error");
	else if(pid == 0){
		if(close(pfd[1]) == -1)
			perror("close");
		execlp("wc","wc","-l",(char *)NULL);
		close(pfd[0]);
	}
	else if(pid > 0)
		wait(NULL);
*/
	return 0;
}
