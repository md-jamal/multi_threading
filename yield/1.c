#include <stdio.h>
#include <pthread.h>


pthread_t tid[2];


void *thread_fn1(void *arg)
{
 printf("Thread 1 in execution\n");
 for(int i=0; i <100000; i++) {
	printf("value of i is %d\n", i);
	if (i == 9999)
		pthread_yield();
 }
 printf("Thread 1 in execution\n");
 pthread_exit(NULL);
}

void *thread_fn2(void *arg)
{
	sleep(4);
 printf("Thread 2 in execution\n");
 pthread_exit(NULL);
}

int main()
{
 int ret;
 ret = pthread_create(&tid[0], NULL, thread_fn1, NULL);
 if (!ret)
  printf("Thread[%d] created Successfully\n",1);
 else
  printf("Thread[%d] not created\n",1);
 ret = pthread_create(&tid[1], NULL, thread_fn2, NULL);
 if (!ret)
  printf("Thread[%d] created Successfully\n",2);
 else
  printf("Thread[%d] not created\n",2);


 pthread_exit(NULL);

}
