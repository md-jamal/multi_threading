#include <pthread.h>
#include <stdio.h>

void *func(void *data)
{
	if ( ! pthread_detach(pthread_self()) )
		printf("Thread detached successfully !!!\n");
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
    }

    sleep(5);
    printf("Main thread dying...\n");
    return 0;
}
