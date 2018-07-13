//Receiver
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
	sevp.sigev_signo = SIGUSR2;

	char *buf = NULL;

	sigaction(SIGUSR1, &sigact, NULL);

	mq_notify(mqd, &sevp);
	if(NULL == (buf = (char *)malloc(sizeof(INT_MAX)))) {
	perror(" ");
	exit(EXIT_FAILURE);
	}
	
	if((mq_receive(mqd, buf, attr.mq_msgsize, 0))== -1) 	
	{
		printf("message queue empty..\n");
		exit(EXIT_FAILURE);
	}

	printf("contents are :%s\n",buf);
	printf("received message...\n");

	mq_unlink("/mqd");
	return 0;
}

