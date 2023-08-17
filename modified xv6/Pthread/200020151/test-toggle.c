#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>
#include "zemaphore.h"

#define NUM_THREADS 3
#define NUM_ITER 10

zem_t zem[NUM_THREADS];

void *justprint(void *data)
{
  int thread_id = *((int *)data);

  for (int i = 0; i < NUM_ITER; i++) {
    zem_down(&zem[thread_id]);

    printf("This is thread %d\n", thread_id);
    
    zem_up(&zem[(thread_id+1)%NUM_THREADS]);
  }
  return 0;
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int thread_id[NUM_THREADS];
  
  zem_init(&zem[0], 1);
  for (int i = 1; i < NUM_THREADS; i++) {
  
    zem_init(&zem[i], 0);
    
  }
  
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_id[i] = i;
    pthread_create(&threads[i], NULL, justprint, (void *)&thread_id[i]);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
