#if 0
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void catch_ctlc(int signum, siginfo_t * si, void *p)
{

    printf("segfault occured\n");
    fflush(stdout);
    exit(0);
}

int main()
{

    signal(SIGALRM, catch_ctlc);
    sleep(1);
    while (1) {
	printf("main program2\n");
	sleep(1);
    }
    getchar();
//      pause();
    return 0;
}
#endif

#if 1
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void catch_ctlc(int signum, siginfo_t *si,void *p)
{
    while (1) {
	printf("in prog2\n");
	kill(si -> si_pid , SIGUSR1);
	sleep(2);
    }
    //fflush(stdout);
    //exit(0);
}

int main()
{
   //sleep(1);
   	
	struct sigaction sa;
	sa.sa_sigaction = catch_ctlc;
	sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&sa, NULL);
	printf("pid = %d",getpid());
	getchar();
   // kill(1, SIGUSR1);
	
     pause();
    return 0;
}
#endif
