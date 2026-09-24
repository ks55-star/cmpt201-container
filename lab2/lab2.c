#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() { // get the input from the user first and keep getting it
  char *user = NULL;
  char *saveptr = NULL;
  int wstatus = 0;
  size_t size = 0;

  // while for keep getting the output
  while (user == NULL) {
    printf("enter program to run: ");
    ssize_t userinput = getline(&user, &size, stdin);
    if (userinput == -1) {
      break;
    }
    char *tokenize = strtok_r(user, " \n", &saveptr);

    pid_t pid = fork();
    if (pid == 0) {                     // if this is a child
      execlp(tokenize, tokenize, NULL); // did not terminate properly
      perror("Exec failure");
      exit(EXIT_FAILURE);
    } else {
      // waitpid(pid, &wstatus, 0);
      user = NULL;
      if (waitpid(pid, &wstatus, 0) == -1) {

        if (pid) { // did not terminate normally
          perror("did not terminate properly");
          exit(EXIT_FAILURE);
        }
        if (WIFEXITED(wstatus)) { // terminated normally but whether failed or succeeded
          printf("the child terminated with status %d", wstatus);
        } else {
          printf("did not terminate normally");
        }
      }
    }
    free(user);
  }
}
