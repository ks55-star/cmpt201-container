#define _GNU_SOURCE
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void *my_thread(void *arg) {
  char *msg = arg;
  printf("in thread %d: %s\n", gettid(), msg);
  sleep(1);
  printf("Threads done!\n");
  return (void *)strlen(msg);
}

const int MAX = 100000;

int cnt = 0;
void *firstthread(void *args) {
  for (int i = 0; i < MAX; i++) {
    cnt += 1;
  }
  return NULL;
}

int main() {
  pthread_t id1;
  if (pthread_create(&id1, NULL, my_thread, "Hello") != 0) {
    perror("Unable to create thread.");
    exit(EXIT_FAILURE);
  }

  void *thread_ret = 0;
  if (pthread_join(id1, &thread_ret) != 0) {
    perror("Unable to join");
    exit(EXIT_FAILURE);
  }

  pthread_t id2;
  if (pthread_create(&id2, NULL, firstthread, NULL) != 0) {
    pe
  }
}
