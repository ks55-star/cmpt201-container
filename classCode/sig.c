#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int a) { write(STDOUT_FILENO, "TEST\n", a); }
int main() {
  handler(3);
  // creating a variable of the type sigaction initializing the struct
  struct sigaction sig;
  sig.sa_handler = handler;
  sig.sa_flags = 0;
  sigemptyset(&sig.sa_mask);
  pid_t pid = fork();
  if(pid==0){
    //this is the child
    sleep(100);
    
  }
  // register a signal handler
  int ret = sigaction(SIGINT, &sig, NULL);
  if (ret == -1) {
    perror("Sigaction() failed");
    exit(EXIT_FAILURE);
  }
  while (true) {
    sleep(1);
  }

  return 0;
}
