#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int pfd[2];
	if (pipe(pfd) == -1)
		perror("pipe");
	
	switch (fork()) {
		case -1:
				perror("fork");
				break;
		case 0:
				if (close(pfd[0]) == -1)
					perror("close 1");
				if (pfd[1] != STDOUT_FILENO) {
					if (dup2(pfd[1], STDOUT_FILENO) == -1)
						perror("dup2 1");
					if (close(pfd[1]) == -1)
						perror("close 2");
				} 		
				execlp("ls", "ls", (char *) NULL);
		default:
			break;
	}
	switch (fork()) {
		case -1:
				perror("fork");
		case 0:
				if (close(pfd[1]) == -1)
					perror("close 3");
				if (pfd[0] != STDIN_FILENO) {
					if (dup2(pfd[0], STDIN_FILENO) == -1)
						perror("dup2 2");
					if (close(pfd[0]) == -1)
						perror("close 4");
				} 
				execlp("wc", "wc", "-l", (char *) NULL);
			//	errExit("execlp wc"); /* Reads from pipe */
		default:
				break;
	}
		if (close(pfd[0]) == -1)
			perror("close 5");
		if (close(pfd[1]) == -1)
			perror("close 6");
		if (wait(NULL) == -1)
			perror("wait 1");
		if (wait(NULL) == -1)
			perror("wait 2");
		exit(EXIT_SUCCESS);
	
}
