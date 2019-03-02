/*****Exercise3.Write a program hellomany.c that will create a number N of threads specified in the command line, each of which prints out a hello message and its own thread ID*****/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void  *thread_func(void *arg)
{
	printf("Hello world\n");
	printf("Function thread %d id is : %ld\n",*(int *)arg,pthread_self());
}

int main(int argc, char *argv[])
{
	printf("argc is %d\n",argc);

	if (!(atoi(argv[1])))
	{
		perror("argv");
		exit(1);
	}

	printf("argv[1] is %d\n",atoi(argv[1]));
	
	int no_of_threads = atoi(argv[1]);

	pthread_t tid[no_of_threads];
	int i = 0;

	for (i = 0; i < no_of_threads; i++) {
		if ( pthread_create (&tid[i], NULL, thread_func, (void *)&(no_of_threads) ) != 0 ) {
			perror("Error for pthread_create:");
			exit(2);
		}
	}

	for (i = 0 ;i < no_of_threads ; i++)	
		pthread_join (tid[i], NULL);

	printf("Main thread id is : %ld\n",pthread_self());
	
//	sleep(2);

	return 0;
}

