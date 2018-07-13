#if 0
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void catch_ctlc(int signum)
{

    printf("segfault occured\n");
    fflush(stdout);
    exit(0);
}

int main()
{

    signal(SIGALRM, catch_ctlc);
    while (1) {
	printf("main program1\n");
	sleep(1);
    }

    //pause();
    return 0;
}
#endif


#if 1
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void catch_ctlc(int signum)
{

    while (1) {

	printf("in prog1\n");
	sleep(2);
    }
//  fflush(stdout);
    //exit(0);
}

int main (int argc, char **argv)
{
	pid_t pid = atoi(argv[1]);
                                                                                                                                                                                   

	printf("pid is %d\n",atoi(argv[1]));

    signal(SIGUSR1, catch_ctlc);
    kill( pid ,SIGUSR1);

    pause();
    return 0;
}
#endif

	printf("%d\n",(*p).a);

