#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define 
int a = 0;
void *thread_function(void *p)
{
	a =a+10;
	printf("thread function:%d\n",a);
}

void *thread_function1(void *p)
{
	a =a+10;
	printf("thread function1:%d\n",a);
}

void *thread_function2(void *p)
{
	a =a+10;
	printf("thread function2:%d\n",a);
}

int main(void)
{
	pthread_t thid;
	pthread_t thid1;
	pthread_t thid2;

	pthread_attr_t attr;
	pthread_attr_t attr1;
	pthread_attr_t attr2;
	
	int status;
	int status1;
	int status2;
	
	struct sched_param pa;
	pa.sched_priority = 1;
	struct sched_param pa1;
	pa1.sched_priority = 2;
	struct sched_param pa2;
	pa2.sched_priority = 3;
	
	status = pthread_attr_setschedparam(&attr,&pa);
	status1 = pthread_attr_setschedparam(&attr,&pa1);
	status2 = pthread_attr_setschedparam(&attr,&pa2);

	int size = PTHREAD_STACK_MIN + 0x4000;
	void *stackbase = (void *) malloc( size);
	
	pthread_attr_setstack(&attr,stackbase,size);
	pthread_attr_setstack(&attr1,stackbase,size);
	pthread_attr_setstack(&attr2,stackbase,size);


	if( 0 != (pthread_create(&thid,&attr,thread_function,NULL)))
	{
		printf("thread creation failed\n");
	}
	
	if( 0 != pthread_create(&thid1,&attr1,thread_function1,NULL))
	{
		printf("thread creation failed\n");
	}
	
	if( 0 != pthread_create(&thid2,&attr2,thread_function2,NULL))
	{
		printf("thread creation failed\n");
	}


	pthread_exit(NULL);
}
