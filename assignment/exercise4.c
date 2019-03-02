/*****Exercise 4: Write a program using threads,  where the main thread increments the value and the child thread decrements the same value*****/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int value=10;

void  *thread_func(void *arg)
{
	printf("Hello world\n");
	printf("Function thread id is : %ld\n",pthread_self());
	printf("In Function thread value decremented is %d\n",--value);
}

int main()
{
	pthread_t tid;

	if ( pthread_create(&tid,NULL,thread_func,NULL) != 0 ) {
		perror("Error for pthread_create:");
		exit(1);
	}
	
	printf("In main thread value incremented is %d\n",++value);
	
	printf("Main thread id is : %ld\n",pthread_self());
	
	sleep(2);

	return 0;
}


