#include <stdio.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    mqd_t qd;
	struct mq_attr attr;
    char *buf = NULL;
//	char *buf1 = NULL;
//	struct sigevent se;
	int a = 1;
	unsigned int *p = &a;
		
	
	
    if (NULL == (buf = (char *) malloc(sizeof(char)))) {
	perror("buffer is full");
	exit(EXIT_FAILURE);
    }
    int st;
    //open a message queue
    qd = mq_open("/queue",O_CREAT | O_RDWR, 0777, NULL);

    if ((mq_getattr(qd, &attr)) != 0) {
	perror("mq_getattr fails\n");
    }
	
	while (1) {
		if (NULL == (fgets(buf, 255, stdin))) {
	    	perror("fgets failed\n");
	    	exit(EXIT_FAILURE);
		}


		//sending a message to msg queue
		st = mq_send(qd, buf, attr.mq_msgsize, 0);
		if (st == -1)
	    	perror("failed");
		wait();

		st = mq_receive(qd, buf, attr.mq_msgsize, p);
		if (st == -1)
	   		printf("failed");
		else {
		    printf("string is %s\n", buf);
		}

	}

	
	mq_close(qd);

	return 0;
}
