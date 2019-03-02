/*****Exercise 2: To print the thread id of the threads along with the Hello World message*****/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void  *thread_func(void *arg)
{
	printf("Hello world\n");
	printf("Function thread id is : %ld\n",pthread_self());
}

int main()
{
	pthread_t tid;

	if ( pthread_create(&tid,NULL,thread_func,NULL) != 0 ) {
		perror("Error for pthread_create:");
		exit(1);
	}
	
	printf("Main thread id is : %ld\n",pthread_self());
	
	sleep(2);

	return 0;
}


