#if 0
#include <pthread.h>
#include <stdio.h>
void *thread_func(void *arg);

int main(int argc, char **argv)
{
    int s;
    void *res;
	pthread_t t1;
	s = pthread_create(&t1, NULL, thread_func, "Hello World\n");
	 if (s != 0)
	 	printf("Err\n");
	printf("In Main()\n");
	s = pthread_detach(t1);

	if (s != 0)
		printf("Err\n");
		return 0;
}
												
void *thread_func(void *arg)													{
	char *s = (char *)arg;
	printf("%s", s);															    pthread_exit(0);
}
#endif

#include <pthread.h>
#include <stdio.h>

void *func(void *data)
{
    while (1)
	{
		printf("Speaking from the detached thread...\n");
		sleep(5);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t handle;
	if (!pthread_create(&handle, NULL, func, NULL))
	{
		printf("Thread create successfully !!!\n");
		if ( ! pthread_detach(handle) )
			printf("Thread detached successfully !!!\n");
	}																			    sleep(5);
	printf("Main thread dying...\n");
	return 0;
}
