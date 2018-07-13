//Sender
#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>
#include <signal.h>
#include <limits.h>

void userhandler(int signum, siginfo_t *p, void *q)
{
	printf("message received from sender process\n");
	return;

}
int main(int argc,char *argv[])
{
	mqd_t mqd;
		
	//create message queue
	mqd = mq_open("/mqd",O_CREAT | O_RDWR,0777,NULL);

	if(mqd == (mqd_t) -1) {
	perror(" ");
	exit(EXIT_FAILURE);
	}
		
	struct mq_attr attr;
	if(mq_getattr(mqd, &attr) == -1)
	{
	perror(" ");
	}

	struct sigevent sevp;
	struct sigaction sigact;

	sigact.sa_sigaction = userhandler;
	sigact.sa_flags = SA_SIGINFO;
	sevp.sigev_notify = SIGEV_SIGNAL;
	sevp.sigev_signo = SIGUSR1;

	char *buf = NULL;

	sigaction(SIGUSR2, &sigact, NULL);

	mq_notify(mqd, &sevp);
	if(NULL == (buf = (char *)malloc(sizeof(INT_MAX)))) {
	perror(" ");
	exit(EXIT_FAILURE);
	}


	buf = "hello............";
	mq_send(mqd ,buf ,attr.mq_msgsize,0);	

	printf("sent messgae....\n");

	return 0;
}

