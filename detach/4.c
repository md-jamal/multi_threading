#include <pthread.h>
#include <stdio.h>

void *func(void *data)
{
//	if ( ! pthread_detach(pthread_self()) )
//		printf("Thread detached successfully !!!\n");
	printf("Speaking from the detached thread...\n");
    pthread_exit(NULL);
}

int main()
{
	int ret;
    pthread_t handle;
    if (!pthread_create(&handle, NULL, func, NULL))
    {
        printf("Thread create successfully !!!\n");
    }

	printf("Before joining\n");
	sleep(5);
	ret = pthread_join(handle, NULL);
	if (ret != 0)
	{
		perror("pthread_join");
	}
    printf("Main thread dying...ret:%d\n", ret);
    return 0;
}
