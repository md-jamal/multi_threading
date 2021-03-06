#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *printme(void *ip)
{
  int *i;

  sleep(1);
  i = (int *) ip;
  printf("Hi.  I'm thread %d\n", *i);
  return NULL;
}

int main()
{
  int i, ids[4];
  pthread_t tids[4];
  void *retval;

  for (i = 0; i < 4; i++) {
    ids[i] = i;
    if (pthread_create(tids+i, NULL, printme, ids+i) != 0) {
      perror("pthread_create");
      exit(0);
    }
  }

  /* Don't call pthread_join() this time. */

  return 0;
}
