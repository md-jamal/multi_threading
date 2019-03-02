/*****Exercise 1:  Create a Hello World program using threads*****/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void  *thread_func(void *arg)
{
	printf("Hello world\n");
}

int main()
{
	pthread_t pid;
	
	if ( pthread_create(&pid,NULL,thread_func,NULL) != 0) {
		perror("Error for pthread_create:");
		exit(1);
	}
	sleep(2);

	return 0;
}


