#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Shared variables */
long total = 0;
long iters;
long thread_count;

void *Thread_work(void *rank);
void Acquire(void);
void Relinquish(void);

int main(int argc, char *argv[])
{
	long thread;
	pthread_t *thread_handles;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <number of threads> <iterations>\n", argv[0]);
		exit(0);
	}
	thread_count = strtol(argv[1], NULL, 10);
	iters = strtol(argv[2], NULL, 10);

	thread_handles = malloc(thread_count * sizeof(pthread_t));
	for (thread = 0; thread < thread_count; thread++)
		pthread_create(&thread_handles[thread], NULL, Thread_work, (void *) thread);

	for (thread = 0; thread < thread_count; thread++)
		pthread_join(thread_handles[thread], NULL);

	printf("Total = %ld\n", total);
	free(thread_handles);

	return 0;
}								/* main */


void *Thread_work(void *rank)
{
	long i;

	for (i = 0; i < iters; i++) {
		Acquire();
		total++;
		Relinquish();
	}

	return NULL;
}								/* Thread_work */


#ifdef ALL_IN_C

#define UNLOCKED 0
#define LOCKED 1

long lock = UNLOCKED;

void Acquire(void)
{
	while (lock == LOCKED);
	lock = LOCKED;
}								/* Acquire */

void Relinquish(void)
{
	lock = UNLOCKED;
}								/* Relinquish */
#endif
