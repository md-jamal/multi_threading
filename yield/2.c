//code for 4 thread functions and yield
#include <stdio.h>
#include <pthread.h>
//creating 4 threads

pthread_t tid[4];


void *thread_fn3(void *arg)
{
	printf("thread 3 before yield\n");
	pthread_yield();
	printf("thread 3 after yield\n");
	pthread_exit(NULL);
}
void *thread_fn4(void *arg)
{
	printf("thread 4 before yield\n");
	pthread_yield();
	printf("thread 4 after yield\n");
	pthread_exit(NULL);
}
void *thread_fn2(void *arg)
{
	printf("thread 2 before yield\n");
	pthread_yield();
	printf("thread 2 after yield\n");
	pthread_exit(NULL);
}

void *thread_fn1(void *arg)
{
	printf("thread 1 before yield\n");
	pthread_yield();
	printf("thread 1 after yield\n");
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
 ret = pthread_create(&tid[2], NULL, thread_fn3, NULL);
 if (!ret)
  printf("Thread[%d] created Successfully\n",3);
 else
  printf("Thread[%d] not created\n",3);

 ret = pthread_create(&tid[3], NULL, thread_fn4, NULL);
 if (!ret)
  printf("Thread[%d] created Successfully\n",4);
 else
  printf("Thread[%d] not created\n",4);

 pthread_exit(NULL);

}
