#include <pthread.h>
static void *func(void *arg) { pthread_exit(0); }
