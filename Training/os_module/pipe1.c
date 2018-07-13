#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int signum)
{
	printf("sigpipe generated");
}

int main(int argc, char **argv)
{
	int pipefd[2];
	int st;
	char buf[100];
	pid_t pid;

	st = pipe(pipefd);
	if (st == -1) {
		perror("pipe not created");
		exit(0);
	}
	signal(SIGPIPE, handler);
	pid = fork();
	if (pid == -1)
		perror("fork error");

	else if (pid == 0) {
		close(pipefd[1]);

		while(read(pipefd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);

		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	//	write(pipefd[1],"hello",6);
	//	close(pipefd[1]);		
	
	} else if (pid > 0) {
		close(pipefd[0]);
		write(pipefd[1], argv[1],strlen(argv[1]));
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);

	}
	return 0;
}
