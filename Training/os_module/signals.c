#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void catch_ctlc(int signum, siginfo_t *si,void *p)
{
	
	printf("segfault occured\n");
	//if (si)
	printf("pid of sending signal is %ld\n", (long)(si -> si_pid) );
		
	printf("address is 0x%lx\n",(long)(si -> si_addr) );
//	sleep( 2 );

	fflush(stdout);
	exit(0);
}

int main()
{
	struct sigaction sa;
	sa.sa_sigaction = catch_ctlc;
	sa.sa_flags = SA_SIGINFO;
	printf(" pid is %d\n",getpid() );

//	signal(SIGSEGV, catch_ctlc);
	sigaction(SIGSEGV,&sa,NULL);

	char *ptr = "hello";
	*ptr = "hi";
	kill(getpid(),SIGSEGV);		
	printf("main program\n");
	pause();
	return 0;
}
