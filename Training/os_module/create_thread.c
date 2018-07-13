#include <stdio.h>
#include <pthread.h>
int a =10;

pthread_t thid1;
pthread_t thid2;
pthread_t thid;

void *thread_function(void *p);
void *thread_function1(void *p);
void *thread_function2(void *p);

void *thread_function(void *p)
{
	a = a + 10;
	//getchar();
	printf("thread function %d\n",a);
	if((pthread_create(&thid1,NULL,thread_function1,NULL)) != 0)
	{
		printf("thread creation failed\n"); 
	}
	pthread_join(thid1,NULL);
	return NULL;
}

void *thread_function1(void *p)
{
	a = a + 10;
//	getchar();
	printf("thread function1 %d\n",a);
	if((pthread_create(&thid2,NULL,thread_function2,NULL)) != 0)
	{
		printf("thread creation failed\n"); 
	}
	pthread_join(thid2,NULL);
 	return NULL;
}

void *thread_function2(void *p)
{
	a = a + 10;
//	getchar();
	printf("thread function2 %d\n",a);
	return NULL;
}


int main()
{
	a =	a+10;	
	printf("main thread = %d\n",a);
	if((pthread_create(&thid,NULL,thread_function,NULL)) != 0)
	{
		printf("thread creation failed\n"); 
	}
	pthread_join(thid,NULL);

	pthread_exit(NULL);
}
